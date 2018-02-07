#pragma once

#include "Model/LSYSModel.h"
#include <QtGUI/QNanoPainterParse.h>
#include <qnanoquickitem.h>

namespace QtGUI {

class QNanoRenderedCurve : public QNanoQuickItem {
    Q_OBJECT

    QString const* p_mdl; //non-owning pointer to model string

public slots:
    void onModelChanged(QString const* pstr)
    {
        p_mdl = pstr;
        //        update(); //update the paint node
    }

public:
    QNanoRenderedCurve(QQuickItem* parent = 0)
        : QNanoQuickItem(parent)
    {
    }

    QNanoQuickItemPainter* createItemPainter() const
    {
        // Create painter for this item
        return new QtGUI::QNanoCurvePainter();
    }

    const QString* getP_mdl() const;
};

} // namespace QtGUI
