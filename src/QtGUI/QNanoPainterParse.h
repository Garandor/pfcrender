#pragma once
#include "Model/LSYSModel.h"
#include "Model/ModelStringParser.h"
#include "util/PolarVector2D.h"
#include <QColor>
#include <QList>
#include <QStack>
#include <QString>
#include <qnanoquickitempainter.h>

namespace QtGUI {

// HelloItemPainter contains the painting code
class QNanoCurvePainter : public QNanoQuickItemPainter {

public:
    QNanoCurvePainter()
        : pos()
        , rounding(0)
        , stack{}
        , cur_color_idx(0)
        , modelstring()
    {
    }
    void paint(QNanoPainter* p) override;
    void synchronize(QNanoQuickItem* item) override;

private:
    QNanoPainter* p;
    QString modelstring;

    util::PolarVector2D pos, p1, p2, p3;
    bool is_first_segment = true; //The first drawn segment needs to be handled differently than the inner segments)
    QStack<util::PolarVector2D> stack{};
    int cur_color_idx;
    double angle;

    QPointF   coord_final,
            min,
            max;

    QRectF boundingBox;

    double rounding;

void calculate_bounding_box();
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
};

static const QList<QColor>
    colors({ QColor(Qt::black),
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
