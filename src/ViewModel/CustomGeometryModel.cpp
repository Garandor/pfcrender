#include<QDebug>
#include<QSGSimpleRectNode>
#include<algorithm>
#include "CustomGeometryModel.h"
namespace ViewModel
{


void CustomGeometryModel::setGeometryNode(QSGGeometryNode* newNode)
{
//    qDebug() << QStringLiteral("test") << QVariant((newNode != nullptr) ? true : false);

    //store the node reference so the render thread can get it later
    p_node = newNode;

    //do some processing on the node before addidng it to the scene
    //Normalize coordinates (make sure it has no negative coords)

    //fit to parent dimensions

    //Set up the new properties of the quickitem according to its new geometry
    _setNewOuterDimensions();

    qDebug() << "QQuickItem outer dimensions" << boundingRect();

    //Schedule updating the paintNode
    update();
    emit viewModelChanged();
}

QSGNode* CustomGeometryModel::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData);
    //if we have new geometry, load it
    if(p_node != nullptr)
    {
        auto ptemp = p_node;	//copy to temp ptr
        p_node = nullptr;		//reset the quickitem held ptr (node now managed by scene graph)
        return ptemp;
    }
    return oldNode;
}

void CustomGeometryModel::_setNewOuterDimensions()
{
    //calculate new bounding box and update properties
    // min = minium coordinate of the box
    // max = maxium coordinate of the box
    auto n =  dynamic_cast<QSGGeometryNode*>(p_node);
    auto g = n->geometry()->vertexDataAsPoint2D();
    QSGGeometry::Point2D min = g[0],
                         max = g[0];

    for (int i = 1; i < n->geometry()->vertexCount(); ++i)
    {
        if ( g[i].x < min.x ) min.x = g[i].x;
        if ( g[i].y < min.y ) min.y = g[i].y;
        if ( g[i].x > max.x ) max.x = g[i].x;
        if ( g[i].y > max.y ) max.y = g[i].y;
    }

    qDebug() << "rectangle coords: (" << min.x << ',' << min.y << ") ; (" << max.x << "," << max.y;
    this->setWidth(max.x - min.x);
    this->setHeight(max.y - min.y);

    //Normalize coordinates so they conform to item coordinates (0,0 = top of image) used by scenegraph
    if(std::min<double>({min.x,max.x,min.y,max.y}) < 0)
    {
        QSGTransformNode* wrapNode = new QSGTransformNode;
        //TODO: create matrix
        QMatrix4x4 transform = wrapNode->matrix();

        transform.translate(-std::min<double>({min.x,max.x,0.0}),-std::min<double>({min.y,max.y,0}),0);
//        qDebug() << parent()->property("height").toFloat() << ' ' << parent()->property("width").toFloat();
//        qDebug() << height() << ' ' << width();
//        transform.scale(std::min((parent()->property("height")).toFloat()/height(),parent()->property("width").toFloat()/width()));

        wrapNode->setMatrix(transform);
        wrapNode->appendChildNode(p_node);
        wrapNode->markDirty(QSGNode::DirtyNodeAdded);
        p_node = wrapNode;
    }

    qDebug() << ": " << x()  << " " << y();
    qDebug() << "bound: " << boundingRect().x()  << " " << boundingRect().y();
    qDebug() << "bound: " << boundingRect().width()  << " " << boundingRect().height();

    qDebug() << "parent: " << parent()->property("height") << " " << parent()->property("width");
    setTransformOrigin(QQuickItem::TopLeft);
    setScale(2);
    setSize(QSizeF(width()*2,height()*2));
    emit dimensionChanged();
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
