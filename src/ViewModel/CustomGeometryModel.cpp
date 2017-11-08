#include<QDebug>
#include "CustomGeometryModel.h"
namespace ViewModel
{


void CustomGeometryModel::setGeometryNode(std::unique_ptr<QSGGeometryNode> newNode)
{
//    qDebug() << QStringLiteral("test") << QVariant((newNode != nullptr) ? true : false);
    m_geometry = std::move(newNode);
    update();
    emit viewModelChanged();
}

QSGNode* CustomGeometryModel::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData);
    //
    if(m_geometry.get() != oldNode)
    {
        m_geometry.get()->markDirty(QSGNode::DirtyNodeAdded | QSGNode::DirtyNodeRemoved);
        return m_geometry.get();
    }
    return oldNode;
}

CustomGeometryModel::CustomGeometryModel() : QQuickItem()
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

}  // namespace Model
