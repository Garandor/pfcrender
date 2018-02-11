#include "BboxParse.h"
#include "Common/Config_Registry.h"
#include <gsl/gsl>

namespace Plugins {
namespace Export {

    BboxParse::BboxParse(const QString& mdl)
        : initial_angle(Common::Config_Registry::getInstance()->getOpt("ViewModel.InitialAngle").toDouble(nullptr))
        , angle(Common::Config_Registry::getInstance()->getOpt("ViewModel.Angle").toDouble(nullptr))
        , seglen(Common::Config_Registry::getInstance()->getOpt("ViewModel.SegmentLength").toDouble(nullptr))
        , coord_final{}
        , coord_last_drawn{}
    {
        parsing_preamble();
        parse_model_string(mdl);
    }

    LSYS_STRING_PARSE_FUNC_DEF(BboxParse)

    void BboxParse::parsing_preamble()
    {
        //Starting position
        pos.angle = initial_angle;
        pos.length = seglen;
    }

    inline void BboxParse::add_segment()
    {
        pos.next();

        if (pos.start.x < min.x())
            min.setX(pos.start.x);
        else if (pos.start.x > max.x())
            max.setX(pos.start.x);
        if (pos.start.y < min.y())
            min.setY(pos.start.y);
        else if (pos.start.y > max.y())
            max.setY(pos.start.y);
    }

    inline void BboxParse::next_color()
    {
    }

    inline void BboxParse::prev_color()
    {
    }

    inline void BboxParse::incAngle()
    {
        pos.addToAngle(angle);
    }

    inline void BboxParse::decAngle()
    {
        pos.addToAngle(-angle);
    }

    inline void BboxParse::stackPush()
    {
        stack.push(pos);
    }

    inline void BboxParse::stackPop()
    {
        if (stack.isEmpty())
            qWarning("Tried to pop from empty stack. Ignoring this character");
        else
            pos = stack.pop();
    }

    QRectF BboxParse::getBbox(const QString& mdl)
    {
        BboxParse bbp(mdl);
        return QRectF(bbp.min, bbp.max);
    }
}
}
