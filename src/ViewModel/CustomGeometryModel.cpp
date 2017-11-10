#include<QDebug>
#include<QSGSimpleRectNode>
#include "CustomGeometryModel.h"
namespace ViewModel
{


void CustomGeometryModel::setGeometryNode(std::unique_ptr<QSGGeometryNode> newNode)
{
//    qDebug() << QStringLiteral("test") << QVariant((newNode != nullptr) ? true : false);
    if(newNode != m_geometry)
    {
    m_geometry = std::move(newNode);

    _setNewOuterDimensions();

    //Normalize coordinates (make sure it has no negative coords)

    _normalizeGeometry();
    qDebug() << "QQuickItem outer dimensions" << boundingRect();

    update();
    emit viewModelChanged();
    }
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

void CustomGeometryModel::_setNewOuterDimensions()
{
    //calculate new bounding box and update properties
    // min = minium coordinate of the box
    // max = maxium coordinate of the box
    #define V m_geometry.get()->geometry()->vertexDataAsPoint2D()
    QSGGeometry::Point2D min = V[0];
    QSGGeometry::Point2D max = V[0];
    for (int i = 1; i < m_geometry.get()->geometry()->vertexCount(); ++i)
    {
        if ( V[i].x < min.x ) min.x = V[i].x;
        if ( V[i].y < min.y ) min.y = V[i].y;
        if ( V[i].x > max.x ) max.x = V[i].x;
        if ( V[i].y > max.y ) max.y = V[i].y;
    }

    qDebug() << "rectangle coords: (" << min.x << ',' << min.y << ") ; (" << max.x << "," << max.y;
    this->setWidth(max.x - min.x);
    this->setHeight(max.y - min.y);

    //Normalize coordinates to 0
    setX(min.x < 0 ? -min.x : x());
    setX(max.x < 0 ? -max.x : x());

    setY(min.y < 0 ? -min.y : y());
    setY(max.y < 0 ? -max.y : y());

    qDebug() << ": " << x()  << " " << y();

    qDebug() << "parent: " << parent()->property("height") << " " << parent()->property("width");
    emit dimensionChanged();

//    setScale(0.5);
}

void CustomGeometryModel::_normalizeGeometry()
{
    //TODO: If boundingRect() is not equal to flickable size
    //TODO: If is negative
    //wrap geometry in a transform node
    QSGTransformNode* tl = new QSGTransformNode();
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
