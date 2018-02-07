#include <QDebug>
#include <QMatrix>
#include <QSGGeometryNode>
#include <QSGNode>
#include <algorithm>

#include "QNanoPaintedCurve.h"
#include "QtGUI/QNanoCurvePainter.h"

namespace QtGUI {

void QNanoPaintedCurve::onModelChanged(const QString* pstr)
{
    drawing_params_changed = true;
    p_mdl = pstr;

    update(); //update the paint node
}

QNanoQuickItemPainter* QNanoPaintedCurve::createItemPainter() const
{
    // Create painter for this item
    auto* ptr = new QtGUI::QNanoCurvePainter();
    connect(ptr, &QNanoCurvePainter::boundingBoxChanged, this, &QNanoPaintedCurve::onBoundingBoxChanged, Qt::QueuedConnection); //receive notifications on bounding box change
    return dynamic_cast<QNanoQuickItemPainter*>(ptr);
}

} // namespace Model
