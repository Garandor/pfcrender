#include "NanoCustomGeometryModel.h"
#include <QDebug>
#include <QMatrix>
#include <QSGGeometryNode>
#include <QSGNode>
#include <algorithm>

namespace QtGUI {

const QString* QNanoRenderedCurve::getP_mdl() const
{
    return p_mdl;
}

} // namespace Model
