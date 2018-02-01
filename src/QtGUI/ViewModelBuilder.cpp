#include "ViewModelBuilder.h"

#include <QSGGeometryNode>
#include <QSGVertexColorMaterial>

#include "Common/Config_Registry.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>

namespace QtGUI {

ViewModelBuilder::ViewModelBuilder()
    : stack{}
    , p_geo(new QSGGeometryNode) //XXX: not exception safe. Will get freed by the QSGScenegraph memory management
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
    , temp_vertexstore{}
{
}

std::pair<QSGGeometryNode*, QRectF> ViewModelBuilder::build(const QString& mdl)
{
    parsing_preamble(mdl);
    const unsigned int segcount = parse_model_string(mdl);
    parsing_finalize(segcount);

    return std::make_pair(p_geo, QRectF(min, max));
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

    temp_vertexstore.push_back(p); //add position to vertex array

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
    //We read vertices into a temporary array with

    m_g->allocate(temp_vertexstore.size()); //XXX: Can not be used here since it invalidates vertex data. Keep the worstcase size for now
    memcpy(m_g->vertexData(), temp_vertexstore.data(), temp_vertexstore.size() * sizeof(QSGGeometry::ColoredPoint2D)); //Copy array content to QSGGeometry

    m_g->markVertexDataDirty(); //Mark dirty to tell Qt to redraw

    // Create Material
    QSGVertexColorMaterial* material = new QSGVertexColorMaterial;
    material->setFlag(QSGMaterial::Blending, true);

    // Assign everything to the node
    p_geo->setGeometry(m_g);
    p_geo->setMaterial(material);
    // Make sure the model releases resources when not needed anymore
    p_geo->setFlag(QSGNode::OwnedByParent, true);
    // Set flags to make sure geometry and material are destroyed with the node
    p_geo->setFlag(QSGNode::OwnsGeometry);
    p_geo->setFlag(QSGNode::OwnsMaterial);
}

inline void ViewModelBuilder::parsing_preamble(const QString& mdl)
{
    //create a new Geometry (Wrapper for OpenGL vertices) don't allocate any space (we do this later), since we write to a temporary during parsing
    m_g = new QSGGeometry(
        QSGGeometry::defaultAttributes_ColoredPoint2D(), 0);

    // we won't touch the vertices after they have first been rendered
    //NOTE: if we do -> mark_dirty
    m_g->setVertexDataPattern(QSGGeometry::StaticPattern);
    m_g->setDrawingMode(QSGGeometry::DrawLineStrip); // Draw connected lines each vertex

    pos = util::PolarVector2D{}; //Create initial vector for rendering the curve

    //Read user supplied config options. XXX: this could be greatly simplified with std::optional once C++17 is supported by CI

    parse_config("ViewModel.SegmentWidth", [&](double param) { m_g->setLineWidth(param); }); //Line Rendering Width
    parse_config("ViewModel.InitialAngle", [&](double param) { pos.angle = param; }); //Initial Angle
    parse_config("ViewModel.Angle", [&](double param) { angle_increment = param; }); //Angle per segment
    parse_config("ViewModel.SegmentLength", [&](double param) { pos.length = param; }); //Segment Length

    temp_vertexstore.push_back(pos.getPoint());
}

std::pair<QSGGeometryNode*, QRectF> createGeom(const QString& mdl)
{
    return ViewModelBuilder().build(mdl);
}
}
