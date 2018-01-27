#pragma once
#include "ViewModel/ModelStringParser.h"
#include "util/PolarVector2D.h"
#include <QPainter>
#include <QStack>
#include <QString>

namespace Plugins {
namespace SVG {

    class QPainterParse {

    public:
        explicit QPainterParse(const QString& mdl, QPaintDevice& onto);

    private:
        void parsing_preamble();
        void parsing_finalize();

        LSYS_STRING_PARSE_FUNC_DECL
        void add_segment();
        void next_color();
        void prev_color();
        void incAngle();
        void decAngle();
        void stackPush();
        void stackPop();

        QPainter m_p;
        QPen m_pen;

        //config options
        const double seglen, rounding, angle, initial_angle;

        util::PolarVector2D pos;
        QStack<util::PolarVector2D> stack{};
        int cur_color_idx = 0;
    };

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
}
}
