#include "CustomGeometryModel.h"
#include <QDebug>
#include <QMatrix>
#include <QSGGeometryNode>
#include <QSGNode>
#include <algorithm>

namespace ViewModel {

void CustomGeometryModel::setGeometryNode(std::pair<QSGGeometryNode*, QRectF> vm)
{
    //store the node reference so the render thread can get it later
    p_node = vm.first;

    //process the node to normalize to Qt coordiantes
    _normalizeGeometry(vm.second);

    //Schedule updating the paintNode
    update();

    //fit to parent dimensions
    emit viewModelChanged();
}

QSGNode* CustomGeometryModel::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData);
    //if we have new geometry, load it
    if (p_node != nullptr) {
        auto ptemp = p_node; //copy to temp ptr
        p_node = nullptr; //reset the quickitem held ptr (node will now be managed by scene graph)
        return ptemp;
    }
    return oldNode;
}

void CustomGeometryModel::_normalizeGeometry(QRectF& boundingBox)
{
    m_vertexSize.setWidth(boundingBox.width());
    m_vertexSize.setHeight(boundingBox.height());
    this->setSize(boundingBox.size());

    //Normalize coordinates so they conform to item coordinates (0,0 = top of image) used by scenegraph
    QRectF normalized = boundingBox.normalized();
    normalized.moveTo(0, 0);
    if (normalized != boundingBox) {
        QSGTransformNode* wrapNode = new QSGTransformNode;
        //TODO: create matrix
        auto transform = wrapNode->matrix().toAffine();

        transform.translate(normalized.left() - boundingBox.left(), normalized.bottom() - boundingBox.bottom());

        wrapNode->setMatrix(transform);
        wrapNode->appendChildNode(p_node);
        wrapNode->markDirty(QSGNode::DirtyNodeAdded);
        p_node = wrapNode;
    }

    setTransformOrigin(QQuickItem::TopLeft);
}

CustomGeometryModel::CustomGeometryModel()
    : QQuickItem()
{
    setFlags(QQuickItem::ItemHasContents);
}

CustomGeometryModel::~CustomGeometryModel()
{
    //BUG possible: While we are sure the QSGGeometryNode is deleted via smart_ptr on model destruction, the contained Geometry and Material are managed by Qt
    //If we reuse the GeometryNode it is possible to have deleted geometries and materials
    //Check if the Geometry and Material get deleted by Qt and then reference nullpointers on subsequent rendering attempts of the SGGNode
    //The Node itself should get automagically deleted by the smart ptr
}

QSizeF CustomGeometryModel::vertexSize()
{
    return m_vertexSize;
}

} // namespace Model
