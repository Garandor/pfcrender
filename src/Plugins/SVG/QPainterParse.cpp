#include "QPainterParse.h"
#include "Common/Config_Registry.h"
#include <QColor>
#include <gsl/gsl>

namespace Plugins {
namespace Export {
    namespace SVG {

        QPainterParse::QPainterParse(const QString& mdl, QPaintDevice& onto)
            : m_p{ &onto }
            , initial_angle(Common::Config_Registry::getInstance()->getOpt("ViewModel.InitialAngle").toDouble(nullptr))
            , angle(Common::Config_Registry::getInstance()->getOpt("ViewModel.Angle").toDouble(nullptr))
            , seglen(Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentLength").toDouble(nullptr))
            , rounding(Common::Config_Registry::getInstance()->getOpt("ViewModel.Rounding").toDouble(nullptr))

            , coord_final{}
            , coord_last_drawn{}
        {
            Expects(m_p.isActive());

            parsing_preamble();
            parse_model_string(mdl);
            parsing_finalize();
        }

        LSYS_STRING_PARSE_FUNC_DEF(QPainterParse)

        void QPainterParse::parsing_preamble()
        {
            //Config
            double lineWidth = Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentWidth").toDouble(nullptr);

            //Starting position
            pos.angle = initial_angle;
            pos.length = seglen;

            //initialize defaults
            m_pen.setColor(colors.first());
            m_pen.setWidthF(lineWidth);

            m_p.setRenderHint(QPainter::Antialiasing, true);
            m_p.setPen(m_pen);

            ///TODO: Get colors from config
        }

        void QPainterParse::parsing_finalize()
        {
            if (rounding) //Connect last arc segment to final coordinate
                m_p.drawLine(coord_last_drawn, coord_final);
        }

        inline void QPainterParse::add_segment()
        {
            Expects(rounding <= 0.5); //Rounding percentage must not be larger than 50% (where arc connects with arc, no line inbetween)

            static util::PolarVector2D p1{ pos }, p2{ pos }, p3{ pos };

            if (!rounding) //If we don't do rounding, we just draw a straight line between the current point an the last
            {
                p1 = p2;
                p2 = pos.next();

                m_p.drawLine(p1, p2);
            } else {
                static bool is_first_segment = true; //The first drawn segment needs to be handled differently than the inner segments)

                //With rounding, the curve calculation needs more history (current endpoint and the last two)

                //XXX: ugly, but we need the history to draw arcs
                p1 = p2;
                p2 = p3;
                p3 = pos.next();

                if (p2 == p1) //skip the first 2 points of the curve (not enough information to draw an arc on)
                    return;

                //first segment(draw line from starting point, to possible beginning of first arc
                if (is_first_segment) {
                    is_first_segment = false;

                    m_p.drawLine(
                        p1,
                        QPointF(p1.start.x + ((p2.start.x - p1.start.x) * rounding), p1.start.y + (p2.start.y - p1.start.y) * rounding));
                }

                //check if the angle changed between the last points
                if (p3.angle == p2.angle) {
                    //angle didnt change, means we can draw a straight line from the end of the last arc, to the potential start of the next one
                    m_p.drawLine(
                        p1.start.x + (p2.start.x - p1.start.x) * rounding, p1.start.y + (p2.start.y - p1.start.y) * rounding,
                        p2.start.x + (p3.start.x - p2.start.x) * rounding, p2.start.y + (p3.start.y - p2.start.y) * rounding);

                    coord_last_drawn = QPointF(p2.start.x + (p3.start.x - p2.start.x) * rounding, p2.start.y + (p3.start.y - p2.start.y) * rounding);
                    coord_final = p3;
                } else {
                    //angle changed, draw next arc segment

                    //1. move to last endpoiunt, draw line to beginning of next arc, draw arc
                    QPainterPath a;
                    a.moveTo(p1.start.x + (p2.start.x - p1.start.x) * rounding, p1.start.y + (p2.start.y - p1.start.y) * rounding);
                    a.lineTo(p2.start.x - (p2.start.x - p1.start.x) * rounding, p2.start.y - (p2.start.y - p1.start.y) * rounding);

                    a.quadTo(p2, QPointF(p2.start.x + ((p3.start.x - p2.start.x) * rounding), p2.start.y + (p3.start.y - p2.start.y) * rounding));

                    m_p.drawPath(a);
                    coord_last_drawn = QPointF(p2.start.x + ((p3.start.x - p2.start.x) * rounding), p2.start.y + (p3.start.y - p2.start.y) * rounding);
                    coord_final = p3;
                }
            }
        }

        inline void QPainterParse::next_color()
        {
            cur_color_idx++;
            if (cur_color_idx >= colors.size())
                cur_color_idx = 0;

            m_pen.setColor(colors.at(cur_color_idx));
            m_p.setPen(m_pen);
        }

        inline void QPainterParse::prev_color()
        {
            cur_color_idx--;
            if (cur_color_idx < 0)
                cur_color_idx = colors.size() - 1;

            m_pen.setColor(colors.at(cur_color_idx));
            m_p.setPen(m_pen);
        }

        inline void QPainterParse::incAngle()
        {
            pos.addToAngle(angle);
        }

        inline void QPainterParse::decAngle()
        {
            pos.addToAngle(-angle);
        }

        inline void QPainterParse::stackPush()
        {
            stack.push(pos);
        }

        inline void QPainterParse::stackPop()
        {
            if (stack.isEmpty())
                qWarning("Tried to pop from empty stack. Ignoring this character");
            else
                pos = stack.pop();
        }
    }
}
}
