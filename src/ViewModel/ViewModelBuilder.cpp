#include "ViewModelBuilder.h"

#include <QSGGeometryNode>
#include <QSGVertexColorMaterial>

#include <QStack>

#include <gsl/gsl>

#include <QDebug>
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
};

QSGGeometryNode*
ViewModelBuilder::_createGeometry(const QString& curve)
{
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

    assert(segcount > 0);

    // todo: segment length and angle user selectable
    //    constexpr qreal initialAngle = 0;
    constexpr qreal angleIncrement = 90;

    //    constexpr qreal length = 10;

    PolarVector2D pos{};

    QSGGeometry::ColoredPoint2D* v = geometry->vertexDataAsColoredPoint2D();

    v[0] = pos.getPoint();
    unsigned int offset = 1;

    // XXX: Maybe iterate over vertex array instead?
    for (const QChar& c : curve) {
        if (c.isNull()) // String is guaranteed to be \0 terminated, this is our
            // sign to stop
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
            qFatal("direct strokes not implemented");
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
            qFatal(QString("not recognized symbol ")
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
    return fac._createGeometry(mdl);
}
}
