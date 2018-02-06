#include "QNanoPainterParse.h"
#include "Common/Config_Registry.h"
#include "NanoCustomGeometryModel.h"
#include <QColor>
#include <gsl/gsl>

namespace QtGui {
}

void QtGUI::QNanoCurvePainter::paint(QNanoPainter* pe)
{
    Expects(pe); //fail on nullptr
    p = pe;

    //If we have no string, just draw a circle
    if (modelstring.isEmpty()) {
        p->setStrokeStyle("#202020");
        p->setLineWidth(width() * 0.02);
        p->circle(width() * 0.5, height() * 0.5, width() * 0.46);
        return;
    }
    // Pick up bounding box and draw curve in one parsing of the string
    parsing_preamble();
    parse_model_string(modelstring);
    parsing_finalize();

    normalize();

    // Paint the background circle
    //    QNanoRadialGradient gradient1(width() * 0.5, height() * 0.4, width() * 0.6, width() * 0.2);
    //    gradient1.setStartColor("#808080");
    //    gradient1.setEndColor("#404040");
    //    p->setFillStyle(gradient1);
    //    p->fill();
    //    p->setStrokeStyle("#202020");
    //    p->setLineWidth(width() * 0.02);
    //    p->stroke();
    //    // Hello text
    //    p->setTextAlign(QNanoPainter::ALIGN_CENTER);
    //    p->setTextBaseline(QNanoPainter::BASELINE_MIDDLE);
    //    QNanoFont font1(QNanoFont::DEFAULT_FONT_BOLD_ITALIC);
    //    font1.setPixelSize(width() * 0.08);
    //    p->setFont(font1);
    //    p->setFillStyle("#B0D040");
    //    p->fillText("HELLO", width() * 0.5, height() * 0.4);
    //    // QNanoPainter text
    //    QNanoFont font2(QNanoFont::DEFAULT_FONT_THIN);
    //    font2.setPixelSize(width() * 0.18);
    //    p->setFont(font2);
    //    p->fillText("QNanoPainter", width() * 0.5, height() * 0.5);
}

void QtGUI::QNanoCurvePainter::synchronize(QNanoQuickItem* item)
{
    //only gets executed when the model changed
    auto* real_item = qobject_cast<QtGUI::QNanoRenderedCurve*>(item);
    //copy the string over from the model
    //Can not be avoided since model runs on GUI thread and this is the render thread
    //Reading from pointer while GUI thread is unblocked would cause race condition
    if (real_item->getP_mdl())
        modelstring = *(real_item->getP_mdl());
}

inline void QtGUI::QNanoCurvePainter::parsing_preamble()
{
    //Starting position
    pos = {};
    pos.angle = Common::Config_Registry::getInstance()->getOpt("ViewModel.InitialAngle").toDouble(nullptr);
    pos.length = Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentLength").toDouble(nullptr);

    //initialize defaults
    p->setStrokeStyle(QNanoColor::fromQColor(colors.first()));
    p->setLineWidth(Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentWidth").toDouble(nullptr));
    angle = Common::Config_Registry::getInstance()->getOpt("ViewModel.Angle").toDouble(nullptr);

    p->setAntialias(false);
    ///TODO: Get colors from config

    is_first_segment = true;
    p1 = p2 = p3 = pos;
    p->beginPath();
    p->moveTo(pos);
}

inline void QtGUI::QNanoCurvePainter::parsing_finalize()
{
    if (rounding) //Connect last arc segment to final coordinate
        p->lineTo(coord_final);
}

//String parsing
LSYS_STRING_PARSE_FUNC_DEF(QtGUI::QNanoCurvePainter)

inline void QtGUI::QNanoCurvePainter::add_segment()
{
    Expects(rounding <= 0.5); //Rounding percentage must not be larger than 50% (where arc connects with arc, no line inbetween)

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
            is_first_segment = false;

            p->lineTo(QPointF(p1.start.x + ((p2.start.x - p1.start.x) * rounding), p1.start.y + (p2.start.y - p1.start.y) * rounding));
            return;
        }

        //check if the angle changed between the last points
        if (p3.angle == p2.angle) {
            //angle didnt change, means we can draw a straight line from the end of the last arc, to the potential start of the next one
            p->lineTo(p2.start.x + (p3.start.x - p2.start.x) * rounding, p2.start.y + (p3.start.y - p2.start.y) * rounding);

            coord_final = p3;
        } else {
            //angle changed, draw next arc segment

            //1. move to last endpoiunt, draw line to beginning of next arc, draw arc
            p->lineTo(p2.start.x - (p2.start.x - p1.start.x) * rounding, p2.start.y - (p2.start.y - p1.start.y) * rounding);
            p->quadTo(p2, QPointF(p2.start.x + ((p3.start.x - p2.start.x) * rounding), p2.start.y + (p3.start.y - p2.start.y) * rounding));

            coord_final = p3;
        }
    }
}

void QtGUI::QNanoCurvePainter::next_color()
{
}

void QtGUI::QNanoCurvePainter::prev_color()
{
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

void QtGUI::QNanoCurvePainter::normalize()
{
}
