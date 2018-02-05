#pragma once

#include <QtGUI/QNanoPainterParse.h>
#include <qnanoquickitem.h>

namespace QtGUI {

// HelloItem provides the API towards QML
class QNanoRenderedCurve : public QNanoQuickItem {
    Q_OBJECT
public:
    QNanoRenderedCurve(QQuickItem* parent = 0)
        : QNanoQuickItem(parent)
    {
    }

    // Reimplement
    QNanoQuickItemPainter* createItemPainter() const
    {
        // Create painter for this item
        return new QtGUI::QNanoCurvePainter();
    }
};

} // namespace Model
