#include "ViewModelBuilder.h"

#include <QSGGeometryNode>
#include <QSGVertexColorMaterial>

#include <QStack>

#include <gsl/gsl>

#include "Common/Config_Registry.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QtMath> //cos, sin
#include <cmath> //fmod

namespace ViewModel {

/**
 * @brief The PolarVector2D class
 * utility class for easy calculation of vertex coordinates,
 * making sure it only gets instantiated once
 */
class PolarVector2D {
    QSGGeometry::ColoredPoint2D start;

public:
    qreal angle;
    qreal length;

public:
    PolarVector2D()
        : start{ 0.0, 0.0, 0, 0, 0, 0 }
        , angle{ 0 }
        , length{ 10 }
    {
        setColor(QColor(Qt::black));
    }
    PolarVector2D& next()
    {
        start.x += length * qCos(angle / 180 * M_PI);
        start.y += length * qSin(angle / 180 * M_PI);
        return *(this);
    }
    const QSGGeometry::ColoredPoint2D& getPoint() { return start; }
    void addToAngle(qreal inc) { angle = fmod((angle + inc), 360); }
    void setColor(const QColor& c)
    {
        start.set(start.x,
            start.y,
            gsl::narrow<uchar>(c.red()),
            gsl::narrow<uchar>(c.green()),
            gsl::narrow<uchar>(c.blue()),
            gsl::narrow<uchar>(c.alpha()));
    }

    const QColor getColor() const
    {
        return QColor(start.r, start.g, start.b, start.a);
    }

    operator QPointF() { return QPointF(start.x, start.y); }
};

void ViewModelBuilder::parse_config(QString opt_name, std::function<void(double)> fnc)
{
    if (!(Common::Config_Registry::getInstance()->getOpt(opt_name).isEmpty())) {
        bool ok = false;
        qreal temp = Common::Config_Registry::getInstance()->getOpt(opt_name).toDouble(&ok);
        if (!ok)
            qCritical() << "Failed converting passed config option for " << opt_name << " to qreal. Passed string: " << Common::Config_Registry::getInstance()->getOpt(opt_name);
        else
            fnc(temp);
    } else
        qDebug() << "No option given for " << opt_name << ", using default";
}

void ViewModelBuilder::draw_curve(QString curve, QPaintDevice& onto)
{
    static const QList<QColor> colors({ QColor(Qt::black),
        QColor(Qt::blue),
        QColor(Qt::green),
        QColor(Qt::red),
        QColor(Qt::cyan),
        QColor::fromCmykF(0.45, 0.86, 0, 0),
        QColor::fromCmykF(0, 0.61, 0.87, 0),
        QColor::fromCmykF(0, 0.83, 1, 0.7),
        QColor(Qt::magenta),
        QColor::fromCmykF(0.86, 0.91, 0, 0.04),
        QColor::fromCmykF(0.5, 0, 1, 0),
        QColor::fromCmykF(0.64, 0, 0.95, 0.4) });

    double lineWidth = Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentWidth").toDouble(nullptr);
    double initialAngle = Common::Config_Registry::getInstance()->getOpt("ViewModel.InitialAngle").toDouble(nullptr); //Initial Angle
    double angle = Common::Config_Registry::getInstance()->getOpt("ViewModel.Angle").toDouble(nullptr); //Angle per segment
    double seglen = Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentLength").toDouble(nullptr); //Segment Length
    double rounding = Common::Config_Registry::getInstance()->getOpt("ViewModel.Rounding").toDouble(nullptr); //Segment Length

    QPixmap pmap(4000, 4000);
    pmap.fill();
    QPainter painter(&pmap);
    //    QPainter pen(onto);
    if (!painter.isActive())
        abort();

    QPen pen(colors.first());
    pen.setWidth(lineWidth);
    pen.setWidth(4);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(pen);

    QStack<ViewModel::PolarVector2D> stack{};
    PolarVector2D pos{};
    // XXX: Maybe iterate over vertex array instead?
    for (const QChar& c : curve) {
        if (c.isNull()) // String is \0 terminated, end loop
            break;

        if (c.isLetter()) // Denotes drawing a line segment
        {
            rounding = 0.3;
            QPointF p1 = pos;
            QPointF p2 = pos.next();
            if (rounding == 0)
                painter.drawLine(p1, p2);
            else {
                QPainterPath a(p1);
                a.moveTo(p1);
                a.quadTo((1 - rounding) * p1.x() + rounding * p2.x(), (1 - rounding) * p1.y() + rounding * p2.y(), p2.x(), p2.y());
                painter.drawPath(a);
            }
            continue;
        }
        if (c != '0' && c.isDigit()) {
            // Direct strokes, e.g., for terdragon:
            // stringsubst 3 1 1 121 2 232 3 313 | tail -1 | ./bin 3 2 1 1 0.15 >
            // tmp-pic.tex && make dotex #
            // TODO: bin mir nicht sicher, ob und wie wir diesen hack unterstuetzen
            // wollen
            qCritical("direct strokes not implemented");
        }

        static int idx = 0; // XXX:
        switch (c.toLatin1()) {
        case '+': // change dir clockwise
            pos.addToAngle(angle);
            continue;
        case '-': // change dir counterclockwise
            pos.addToAngle(-angle);
            continue;
        case '0': // ignored (as symbol for "no turn")
            continue;
        case '[': // push position and direction on stack
            stack.push(pos);
            continue;
        case ']': // pop position and direction from stack
            if (stack.isEmpty())
                qWarning("Tried to pop from empty stack. Ignoring this character");
            else
                pos = stack.pop();
            continue;
        case '_': // special command:  next color
            //            idx = colors.indexOf(pos.getColor())+1;
            idx++;
            if (idx >= colors.size())
                idx = 0;
            pen.setColor(colors.at(idx));
            painter.setPen(pen);
            pos.setColor(colors.at(idx));
            continue;
        case '~': // special command:  previous color
            //            idx = colors.indexOf(pos.getColor())-1;
            idx--;
            if (idx < 0)
                idx = colors.size() - 1;
            pen.setColor(colors.at(idx));
            painter.setPen(pen);
            pos.setColor(colors.at(idx));
            continue;
        default:
            qCritical(QString("not recognized symbol ")
                          .append(c)
                          .append(" present in model")
                          .toLatin1());
            break;
        }
    }

    painter.end();
    pmap.save(QString("test.png"), nullptr, 100);
}

void ViewModelBuilder::add_segment()
{

    qFatal("not implemented");
}

void ViewModelBuilder::next_color()
{

    qFatal("not implemented");
}

void ViewModelBuilder::prev_color()
{

    qFatal("not implemented");
}

void ViewModelBuilder::incAngle()
{

    qFatal("not implemented");
}

void ViewModelBuilder::decAngle()
{

    qFatal("not implemented");
}

void ViewModelBuilder::stackPush()
{

    qFatal("not implemented");
}

void ViewModelBuilder::stackPop()
{
    qFatal("not implemented");
}

QSGGeometryNode*
ViewModelBuilder::_createGeometry(const QString& curve)
{

    QPixmap a;
    draw_curve(curve, a);

    // XXX: Very monolithic function, refactor
    // TODO: Also this in not core functionality, should be a plugin
    // Color list equivalent to how it was before
    static const QList<QColor> colors({ QColor(Qt::black),
        QColor(Qt::blue),
        QColor(Qt::green),
        QColor(Qt::red),
        QColor(Qt::cyan),
        QColor::fromCmykF(0.45, 0.86, 0, 0),
        QColor::fromCmykF(0, 0.61, 0.87, 0),
        QColor::fromCmykF(0, 0.83, 1, 0.7),
        QColor(Qt::magenta),
        QColor::fromCmykF(0.86, 0.91, 0, 0.04),
        QColor::fromCmykF(0.5, 0, 1, 0),
        QColor::fromCmykF(0.64, 0, 0.95, 0.4) });
    auto geom = new QSGGeometryNode; // As all QSG classes are managed by the
    // scene graph, we need not worry about
    // leaking memory / unique_ptrs / cleanup

    QStack<ViewModel::PolarVector2D> stack{};

    // Count number of segments by counting all letters in string to allocate
    // correct size for the geometry
    unsigned int segcount = 0;
    for (QChar c : curve)
        if (c.isLetter())
            segcount++;

    Expects(segcount > 0);

    // Build curve geometry
    auto geometry = new QSGGeometry(
        QSGGeometry::defaultAttributes_ColoredPoint2D(), segcount + 1);
    geometry->setVertexDataPattern(
        QSGGeometry::StaticPattern); // we won't touch the vertices after they
    // have first been rendered. NOTE: if we do,
    // mark_dirty
    geometry->setDrawingMode(
        QSGGeometry::DrawLineStrip); // Draw connected lines each vertex
    geometry->setLineWidth(4); // TODO: User configable

    //Create initial vector for rendering the curve
    PolarVector2D pos{};
    qreal angleIncrement = 90;

    //Read user supplied config options, this could be greatly simplified with std::optional

    //Line Rendering Width
    parse_config("ViewModel.SegmentWidth", [&](double param) { geometry->setLineWidth(param); });

    //Initial Angle
    parse_config("ViewModel.InitialAngle", [&](double param) { pos.angle = param; });

    //Angle per segment
    parse_config("ViewModel.Angle", [&](double param) { angleIncrement = param; });

    //Segment Length
    parse_config("ViewModel.SegmentLength", [&](double param) { pos.length = param; });

    QSGGeometry::ColoredPoint2D* v = geometry->vertexDataAsColoredPoint2D();

    v[0] = pos.getPoint();
    unsigned int offset = 1;

    // XXX: Maybe iterate over vertex array instead?
    for (const QChar& c : curve) {
        if (c.isNull()) // String is \0 terminated, end loop
            break;

        if (c.isLetter()) // Denotes drawing a line segment
        {
            v[offset++] = pos.next().getPoint();
            continue;
        }
        if (c != '0' && c.isDigit()) {
            // Direct strokes, e.g., for terdragon:
            // stringsubst 3 1 1 121 2 232 3 313 | tail -1 | ./bin 3 2 1 1 0.15 >
            // tmp-pic.tex && make dotex #
            // TODO: bin mir nicht sicher, ob und wie wir diesen hack unterstuetzen
            // wollen
            qCritical("direct strokes not implemented");
        }

        static int idx = 0; // XXX:
        switch (c.toLatin1()) {
        case '+': // change dir clockwise
            pos.addToAngle(angleIncrement);
            continue;
        case '-': // change dir counterclockwise
            pos.addToAngle(-angleIncrement);
            continue;
        case '0': // ignored (as symbol for "no turn")
            continue;
        case '[': // push position and direction on stack
            stack.push(pos);
            continue;
        case ']': // pop position and direction from stack
            if (stack.isEmpty())
                qWarning("Tried to pop from empty stack. Ignoring this character");
            else
                pos = stack.pop();
            continue;
        case '_': // special command:  next color
            //            idx = colors.indexOf(pos.getColor())+1;
            idx++;
            if (idx >= colors.size())
                idx = 0;
            pos.setColor(colors.at(idx));
            continue;
        case '~': // special command:  previous color
            //            idx = colors.indexOf(pos.getColor())-1;
            idx--;
            if (idx < 0)
                idx = colors.size() - 1;
            pos.setColor(colors.at(idx));
            continue;
        default:
            qCritical(QString("not recognized symbol ")
                          .append(c)
                          .append(" present in model")
                          .toLatin1());
            break;
        }
    }
    geometry->markVertexDataDirty();

    //    for(int i=0;i<geometry->vertexCount();i++)
    //        printf("%f:%f\t",v[i].x,v[i].y);
    //    fflush(stdout);

    // Create Material
    QSGVertexColorMaterial* material = new QSGVertexColorMaterial;
    material->setFlag(QSGMaterial::Blending, true);

    // Assign everything to the node
    geom->setGeometry(geometry);
    geom->setMaterial(material);
    // Make sure the model releases resources when not needed anymore
    geom->setFlag(QSGNode::OwnedByParent, true);
    // Set flags to make sure geometry and material are destroyed with the node
    geom->setFlag(QSGNode::OwnsGeometry);
    geom->setFlag(QSGNode::OwnsMaterial);

    return geom;
}

QSGGeometryNode*
createGeom(const QString& mdl)
{
    ViewModelBuilder fac;
    fac.parse_model_string(mdl);
    return fac._createGeometry(mdl);
}
}
