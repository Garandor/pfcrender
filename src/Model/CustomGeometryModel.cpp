#include<QDebug>
#include "CustomGeometryModel.h"
namespace Model
{

QString CustomGeometryModel::getType()
{
	return 0;
}

void CustomGeometryModel::setGeometryNode(std::unique_ptr<QSGGeometryNode> newNode)
{
    qDebug() << QStringLiteral("test") << QVariant((newNode != nullptr) ? true : false);
    m_geometry = std::move(newNode);
    update();
    emit modelChanged();
}

QSGNode* CustomGeometryModel::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData)
{
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
    //BUG possible: Check if the Geometry and Material get deleted by Qt and then reference nullpointers on subsequent rendering attempts of the SGGNode
    //The Node itself should get automagically deleted by the smart ptr
}

}  // namespace Model
