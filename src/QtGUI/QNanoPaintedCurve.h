#pragma once

#include "Model/LSYSModel.h"
#include <qnanoquickitem.h>

namespace QtGUI {

class QNanoCurvePainter;
/**
 * @brief The QNanoRenderedCurve class
 * This class is the GUI interface to the scene graph
 *
 */
class QNanoPaintedCurve : public QNanoQuickItem {
    Q_OBJECT

signals:
    void boundingBoxChanged(QRectF newBox); //Forwarding signal to qml

public slots:
    void onConfigChanged()
    {
        drawing_params_changed = true;
    }
    void onModelChanged(QString const* pstr);

    void onBoundingBoxChanged(QRectF newBox)
    {
        setSize(newBox.size());
        emit boundingBoxChanged(newBox);
    }

public:
    QNanoPaintedCurve(QQuickItem* parent = 0)
        : QNanoQuickItem(parent)
    {
    }

    QNanoQuickItemPainter* createItemPainter() const;

private:
    QString const* p_mdl; //non-owning pointer to model string
    bool drawing_params_changed = false;

    friend class QtGUI::QNanoCurvePainter;
};

} // namespace QtGUI
