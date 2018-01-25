#include "ViewModelBuilder.h"

#include <QSGGeometry>
#include <QSGGeometryNode>
#include <QSGVertexColorMaterial>

#include "Common/Config_Registry.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>

namespace ViewModel {

ViewModelBuilder::ViewModelBuilder()
    : stack{}
    , m_geo(new QSGGeometryNode) //XXX: not exception safe. Will get freed by the QSGScenegraph memory management
    , pos{}
    , min{}
    , max{}
    , current_segment(1)
    , colors({ QColor(Qt::black),
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
          QColor::fromCmykF(0.64, 0, 0.95, 0.4) })
    , cur_color(colors.cbegin())
{
}

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

LSYS_STRING_PARSE_FUNC_DEF(ViewModelBuilder)

inline void ViewModelBuilder::add_segment()
{
    auto p = pos.next().getPoint();
    m_g->vertexDataAsColoredPoint2D()[current_segment++] = p;

    //Pick up bounding box along the way
    if (p.x < min.x())
        min.setX(p.x);
    else if (p.x > max.x())
        max.setX(p.x);
    if (p.y < min.y())
        min.setY(p.y);
    else if (p.y > max.y())
        max.setY(p.y);
}

inline void ViewModelBuilder::next_color()
{
    if (cur_color != colors.end())
        pos.setColor(*(cur_color++));
    else {
        cur_color = colors.begin();
        pos.setColor(*cur_color);
    }
}

inline void ViewModelBuilder::prev_color()
{
    if (cur_color != colors.begin())
        pos.setColor(*(cur_color--));
    else {
        cur_color = colors.end();
        pos.setColor(*cur_color);
    }
}

inline void ViewModelBuilder::incAngle()
{
    pos.addToAngle(angle_increment);
}

inline void ViewModelBuilder::decAngle()
{
    pos.addToAngle(-angle_increment);
}

inline void ViewModelBuilder::stackPush()
{
    stack.push(pos);
}

inline void ViewModelBuilder::stackPop()
{
    pos = stack.pop();
    if (stack.isEmpty())
        qWarning("Tried to pop from empty stack. Ignoring this character");
}

inline void ViewModelBuilder::parsing_finalize(const unsigned int vertexcount)
{

    m_g->allocate(vertexcount); //Make sure Geometry gets realloc'd to its final size
    m_g->markVertexDataDirty(); //Mark dirty to tell Qt to redraw

    // Create Material
    QSGVertexColorMaterial* material = new QSGVertexColorMaterial;
    material->setFlag(QSGMaterial::Blending, true);

    // Assign everything to the node
    m_geo->setGeometry(m_g);
    m_geo->setMaterial(material);
    // Make sure the model releases resources when not needed anymore
    m_geo->setFlag(QSGNode::OwnedByParent, true);
    // Set flags to make sure geometry and material are destroyed with the node
    m_geo->setFlag(QSGNode::OwnsGeometry);
    m_geo->setFlag(QSGNode::OwnsMaterial);
}

inline void ViewModelBuilder::parsing_preamble(const QString& mdl)
{
    //allocate a new Geometry (Wrapper for OpenGL vertices) with enough space for the worst case, where every string char is a segment
    m_g = new QSGGeometry(
        QSGGeometry::defaultAttributes_ColoredPoint2D(), mdl.length() + 1);

    // we won't touch the vertices after they have first been rendered
    //NOTE: if we do -> mark_dirty
    m_g->setVertexDataPattern(QSGGeometry::StaticPattern);
    m_g->setDrawingMode(QSGGeometry::DrawLineStrip); // Draw connected lines each vertex

    pos = util::PolarVector2D{}; //Create initial vector for rendering the curve

    //initialize defaults
    m_g->setLineWidth(4);
    angle_increment = 90;

    //Read user supplied config options. XXX: this could be greatly simplified with std::optional once C++17 is supported by CI

    parse_config("ViewModel.SegmentWidth", [&](double param) { m_g->setLineWidth(param); }); //Line Rendering Width
    parse_config("ViewModel.InitialAngle", [&](double param) { pos.angle = param; }); //Initial Angle
    parse_config("ViewModel.Angle", [&](double param) { angle_increment = param; }); //Angle per segment
    parse_config("ViewModel.SegmentLength", [&](double param) { pos.length = param; }); //Segment Length

    auto v = m_g->vertexDataAsColoredPoint2D();
    v[0] = pos.getPoint();
}

std::pair<QSGGeometryNode*, QRectF&&>
createGeom(const QString& mdl)
{
    ViewModelBuilder fac;

    fac.parsing_preamble(mdl);
    const unsigned int segcount = fac.parse_model_string(mdl);
    fac.parsing_finalize(segcount);

    return std::make_pair(fac.m_geo, QRectF(fac.min, fac.max));
}
}
