#pragma once
#include "Model/ModelStringParser.h"
#include "util/PolarVector2D.h"
#include <QStack>
#include <QString>

namespace Plugins {
namespace Export {
    class BboxParse {

    public:
        explicit BboxParse(const QString& mdl);
        QPointF min, max;
        static QRectF getBbox(const QString& mdl);

    private:
        void parsing_preamble();
        LSYS_STRING_PARSE_FUNC_DECL
        void add_segment();
        void next_color();
        void prev_color();
        void incAngle();
        void decAngle();
        void stackPush();
        void stackPop();

        //config options
        double seglen, angle, initial_angle;

        util::PolarVector2D pos;
        QStack<util::PolarVector2D> stack{};
        int cur_color_idx = 0;

        QPointF coord_last_drawn,
            coord_final;
    };
}
}
