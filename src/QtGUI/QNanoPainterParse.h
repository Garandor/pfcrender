#pragma once
#include "Model/ModelStringParser.h"
#include "util/PolarVector2D.h"
#include <QStack>
#include <QString>
#include <qnanoquickitempainter.h>

namespace QtGUI {

// HelloItemPainter contains the painting code
class HelloItemPainter : public QNanoQuickItemPainter {

public:
    HelloItemPainter()
    {
    }

    void paint(QNanoPainter* p)
    {
        // Paint the background circle
        p->beginPath();
        p->circle(width() * 0.5, height() * 0.5, width() * 0.46);
        QNanoRadialGradient gradient1(width() * 0.5, height() * 0.4, width() * 0.6, width() * 0.2);
        gradient1.setStartColor("#808080");
        gradient1.setEndColor("#404040");
        p->setFillStyle(gradient1);
        p->fill();
        p->setStrokeStyle("#202020");
        p->setLineWidth(width() * 0.02);
        p->stroke();
        // Hello text
        p->setTextAlign(QNanoPainter::ALIGN_CENTER);
        p->setTextBaseline(QNanoPainter::BASELINE_MIDDLE);
        QNanoFont font1(QNanoFont::DEFAULT_FONT_BOLD_ITALIC);
        font1.setPixelSize(width() * 0.08);
        p->setFont(font1);
        p->setFillStyle("#B0D040");
        p->fillText("HELLO", width() * 0.5, height() * 0.4);
        // QNanoPainter text
        QNanoFont font2(QNanoFont::DEFAULT_FONT_THIN);
        font2.setPixelSize(width() * 0.18);
        p->setFont(font2);
        p->fillText("QNanoPainter", width() * 0.5, height() * 0.5);
    }
};
}
