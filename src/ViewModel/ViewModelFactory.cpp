#include"ViewModelFactory.h"

#include<QSGFlatColorMaterial>
#include<QSGGeometryNode>

namespace ViewModel {

void add_segment_at(QSGGeometry* g, unsigned int &offset, QSGGeometry::Point2D start, QSGGeometry::Point2D end)
{
        g->vertexDataAsPoint2D()[offset]= start;
        g->vertexDataAsPoint2D()[offset++] = end;
        offset++;
}

std::unique_ptr<QSGGeometryNode> ViewModelFactory::_createGeometry(const QString& curve)
{
    auto geom = std::make_unique<QSGGeometryNode>();

    //Count number of segments by counting occurrences of F in string to allocate correct size

    //Build curve geometry
    auto *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), curve.size());
    geometry->setDrawingMode(GL_LINES);
    geometry->setLineWidth(3);

    constexpr int seg_len =  10;

    //TODO: make interpretation of +- selectable
    enum class dir{
       U,D,L,R
    };
    dir last_dir = dir::R;

    unsigned int offset = 0;

    add_segment_at(geometry,offset,{100,30},{100,30});
    add_segment_at(geometry,offset,{100,30},{100,30});


//    for ( int i=0; i < curve.size() - 2;i += 2 )
//    {
//        if(i==0 && curve.at(i)=="F")
//        {
//        geometry->vertexDataAsPoint2D()[0].set(0, 0);
//        geometry->vertexDataAsPoint2D()[1].set(seg_len,0);
//        segcount = 1;

//        last_dir = dir::R;
//        continue;
//        }

//        //Quick and shitty implementation, this should be a Builder
//        switch(curve.at(i-1).toLatin1())
//        {
//        case '+' :
//            switch(last_dir)
//            {
//            case dir::R:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y-seg_len);
//                last_dir = dir::D;
//                break;
//            case dir::L:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y+seg_len);
//                last_dir = dir::U;
//                break;
//            case dir::U:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x+seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
//                last_dir = dir::R;
//                break;
//            case dir::D:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x-seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
//                last_dir = dir::L;
//                break;
//            }
//            break;

//        case '-' :
//            switch(last_dir)
//            {
//            case dir::R:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y-seg_len);
//                last_dir = dir::D;
//                break;
//            case dir::L:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y+seg_len);
//                last_dir = dir::U;
//                break;
//            case dir::U:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x+seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
//                last_dir = dir::R;
//                break;
//            case dir::D:
//                segcount++;
//                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x-seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
//                last_dir = dir::L;
//                break;
//            }
//            break;
//        }
//    }

    //Create Material
    QSGFlatColorMaterial* material = new QSGFlatColorMaterial();
    material->setColor(QColor(255, 0, 0));

    //Assign everything to the node
    geom->setGeometry(geometry);
    geom->setMaterial(material);

    //Make sure no automatic resource release is done on this object, the owner (=model) must release resources (guaranteed by smart_ptr)
    geom->setFlag(QSGNode::OwnedByParent,false);
    //Set flags to make sure geometry and material are destroyed with the node
    geom->setFlag(QSGNode::OwnsGeometry);
    geom->setFlag(QSGNode::OwnsMaterial);

    return geom;
}

std::unique_ptr<QSGGeometryNode> createGeom(const QString & mdl)
{
    ViewModelFactory fac;
    return std::move(fac._createGeometry(mdl) );

}

}
