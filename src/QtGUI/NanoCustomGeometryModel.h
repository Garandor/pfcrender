#pragma once

#include "Model/LSYSModel.h"
#include <QtGUI/QNanoPainterParse.h>
#include <qnanoquickitem.h>

namespace QtGUI {

class QNanoRenderedCurve : public QNanoQuickItem {
    Q_OBJECT
    QString const* p_mdl; //non-owning pointer to model string

signals:
    void boundingBoxChanged(QRectF newBox); //Forwarding signal to qml

public slots:
    void onModelChanged(QString const* pstr)
    {
        p_mdl = pstr;
        //        update(); //update the paint node
    }

    void onBoundingBoxChanged(QRectF newBox)
    {
        qDebug() << "HAHAHAHAHAHAHAHHAA";
        emit boundingBoxChanged(newBox);
    }

public:
    QNanoRenderedCurve(QQuickItem* parent = 0)
        : QNanoQuickItem(parent)
    {
    }

    QNanoQuickItemPainter* createItemPainter() const
    {
        // Create painter for this item
        auto* ptr = new QtGUI::QNanoCurvePainter();
        connect(ptr, &QNanoCurvePainter::boundingBoxChanged, this, &QNanoRenderedCurve::onBoundingBoxChanged,Qt::QueuedConnection); //receive notifications on bounding box change
        return dynamic_cast<QNanoQuickItemPainter*>(ptr);
    }

    const QString* getP_mdl() const;
};

} // namespace QtGUI
