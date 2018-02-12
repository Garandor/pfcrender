#include <QColor>
#include <gsl/gsl>

#include "Common/Config_Registry.h"

#include "QNanoCurvePainter.h"
#include "QNanoPaintedCurve.h"

namespace QtGui {
}

void QtGUI::QNanoCurvePainter::paint(QNanoPainter* pe)
{
    Expects(pe); //fail on nullptr
    p = pe;

    //if nothing changed from the last redraw, don't redraw
    cur_color_idx = 0;

    //If we have no string, just draw a circle
    if (modelstring.isEmpty()) {
        qWarning() << "QNanoCurvePainter: Modelstring was empty";
        return;
    }
    // Pick up bounding box and draw curve in one parsing of the string
    parsing_preamble();

    parse_model_string(modelstring);
    parsing_finalize();

    boundingBox = QRectF(min, max);
    emit boundingBoxChanged(boundingBox);
    emit painting_done();
}

void QtGUI::QNanoCurvePainter::synchronize(QNanoQuickItem* item)
{
    auto* real_item = qobject_cast<QtGUI::QNanoPaintedCurve*>(item);
    if (!real_item->drawing_params_changed)
        //copy the string over from the model
        return;

    //Transfer state info from GUI thread item if it changed

    //Copy Can not be avoided since model runs on GUI thread and this is the render thread
    //Reading from pointer while GUI thread is unblocked would cause race condition
    if (real_item->p_mdl)
        modelstring = *(real_item->p_mdl);

    //mark changes synchronized
    real_item->drawing_params_changed = false;
    markDirty(QSGNode::DirtyMaterial);
}

inline void QtGUI::QNanoCurvePainter::parsing_preamble()
{
    p->beginPath();

    //calculate BBox and translate coordinates, so the top left ends up at 0,0
    //    calculate_bounding_box();

    //    p->translate(min);

    //Starting position
    pos = {};

    //initialize config
    pos.angle = Common::Config_Registry::getInstance()->getOpt("ViewModel.InitialAngle").toDouble(nullptr);
    pos.length = Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentLength").toDouble(nullptr);
    p->setStrokeStyle(QNanoColor::fromQColor(colors.first()));
    p->setLineWidth(Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentWidth").toDouble(nullptr));
    angle = Common::Config_Registry::getInstance()->getOpt("ViewModel.Angle").toDouble(nullptr);
    rounding = Common::Config_Registry::getInstance()->getOpt("ViewModel.Rounding").toDouble(nullptr);

    p->setAntialias(false);
    ///TODO: Get colors from config

    is_first_segment = true;
    p1 = p2 = p3 = pos;
    p->moveTo(pos);
}

inline void QtGUI::QNanoCurvePainter::parsing_finalize()
{
    //    p->fill();
    if (rounding) //Connect last arc segment to final coordinate
        p->lineTo(coord_final);
    p->stroke();
}

//String parsing
LSYS_STRING_PARSE_FUNC_DEF(QtGUI::QNanoCurvePainter)

inline void QtGUI::QNanoCurvePainter::add_segment()
{
    Expects(rounding <= 0.5); //Rounding percentage must not be larger than 50% (where arc connects with arc, no line inbetween)

    //pick up boundingBox alongside rendering to avoid going through the string twice
    if (pos.start.x < min.x())
        min.setX(pos.start.x);
    else if (pos.start.x > max.x())
        max.setX(pos.start.x);
    if (pos.start.y < min.y())
        min.setY(pos.start.y);
    else if (pos.start.y > max.y())
        max.setY(pos.start.y);

    if (!rounding) //If we don't do rounding, we just draw a straight line between the current point an the last
    {
        p2 = pos.next();

        p->lineTo(p2);
    } else {
        //XXX: ugly, but we need the history to draw arcs
        p1 = p2;
        p2 = p3;
        p3 = pos.next();

        if (p2 == p1) //skip the first 2 points of the curve (not enough information to draw an arc on)
            return;

        //first segment(draw line from starting point, to possible beginning of first arc
        if (is_first_segment) {
            p->lineTo(QPointF(p1.start.x + ((p2.start.x - p1.start.x) * rounding), p1.start.y + (p2.start.y - p1.start.y) * rounding));
            p->quadTo(p2, QPointF(p1.start.x + ((p2.start.x - p1.start.x) * rounding), p1.start.y + (p2.start.y - p1.start.y) * rounding));
        }

        //check if the angle changed between the last points
        if (p3.angle == p2.angle) {
            //angle didnt change, means we can draw a straight line from the end of the last arc, to the potential start of the next one
            p->lineTo(p2.start.x + (p3.start.x - p2.start.x) * rounding, p2.start.y + (p3.start.y - p2.start.y) * rounding);

            coord_final = p3;
        } else {
            //angle changed, draw next arc segment

            //1. move to last endpoint, draw line to beginning of next arc, draw arc
            p->lineTo(p2.start.x - (p2.start.x - p1.start.x) * rounding, p2.start.y - (p2.start.y - p1.start.y) * rounding);
            p->quadTo(p2, QPointF(p2.start.x + ((p3.start.x - p2.start.x) * rounding), p2.start.y + (p3.start.y - p2.start.y) * rounding));

            coord_final = p3;
        }
    }
}

void QtGUI::QNanoCurvePainter::next_color()
{
    cur_color_idx++;
    if (cur_color_idx >= colors.size())
        cur_color_idx = 0;
    p->stroke();
    p->beginPath();
    p->moveTo(pos.start.x, pos.start.y);
    p->setStrokeStyle(QNanoColor::fromQColor(colors.at(cur_color_idx)));
}

void QtGUI::QNanoCurvePainter::prev_color()
{
    cur_color_idx--;
    if (cur_color_idx < 0)
        cur_color_idx = colors.size() - 1;

    p->stroke();
    p->beginPath();
    p->moveTo(pos.start.x, pos.start.y);
    p->setStrokeStyle(QNanoColor::fromQColor(colors.at(cur_color_idx)));
}

void QtGUI::QNanoCurvePainter::incAngle()
{
    pos.addToAngle(angle);
}

void QtGUI::QNanoCurvePainter::decAngle()
{
    pos.addToAngle(-angle);
}

void QtGUI::QNanoCurvePainter::stackPush()
{
    stack.push(pos);
}

void QtGUI::QNanoCurvePainter::stackPop()
{
    if (stack.isEmpty())
        qWarning("Tried to pop from empty stack. Ignoring this character");
    else
        pos = stack.pop();
}
