#include "QPainterParse.h"
#include "Common/Config_Registry.h"
#include <QColor>
#include <gsl/gsl>

namespace Plugins {
namespace SVG {

    QPainterParse::QPainterParse(const QString& mdl, QPaintDevice& onto)
        : m_p{ &onto }
        , initial_angle(Common::Config_Registry::getInstance()->getOpt("ViewModel.InitialAngle").toDouble(nullptr))
        , angle(Common::Config_Registry::getInstance()->getOpt("ViewModel.Angle").toDouble(nullptr))
        , seglen(Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentLength").toDouble(nullptr))
        , rounding(Common::Config_Registry::getInstance()->getOpt("ViewModel.Rounding").toDouble(nullptr))
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
        QPen pen(colors.first());
        pen.setWidth(lineWidth);
        pen.setWidth(4); //TODO: Remove temp code

        m_p.setRenderHint(QPainter::Antialiasing, true);
        m_p.setPen(pen);

        ///TODO: Get colors from config
    }

    void QPainterParse::parsing_finalize()
    {
    }

    inline void QPainterParse::add_segment()
    {
        static QColor current_color;
        static QPointF p1{}, p2{};

        p1 = p2;
        p2 = pos.next();

        //        rounding = 0.3;

        if (!rounding)
            m_p.drawLine(p1, p2);
        else {
            QPainterPath a(p1);
            a.moveTo(p1);
            a.quadTo((1 - rounding) * p1.x() + rounding * p2.x(), (1 - rounding) * p1.y() + rounding * p2.y(), p2.x(), p2.y());
            m_p.drawPath(a);
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
