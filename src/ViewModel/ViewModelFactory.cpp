#include"ViewModelFactory.h"

#include<QSGFlatColorMaterial>
#include<QSGGeometryNode>
#include<QDebug>

namespace ViewModel {

void add_segment_to(QSGGeometry* g, unsigned int &offset, QSGGeometry::Point2D start, QSGGeometry::Point2D end)
{
//        qDebug() << "x" << ((g->vertexDataAsPoint2D()[offset]).x) << "y" << ((g->vertexDataAsPoint2D()[offset]).y);

        g->vertexDataAsPoint2D()[offset]= start;
//        qDebug() << "x" << ((g->vertexDataAsPoint2D()[offset]).x) << "y" << ((g->vertexDataAsPoint2D()[offset]).y);
        offset++;
        g->vertexDataAsPoint2D()[offset] = end;
//        qDebug() << "x" << ((g->vertexDataAsPoint2D()[offset]).x) << "y" << ((g->vertexDataAsPoint2D()[offset]).y);
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
    dir direc = dir::R;

    unsigned int offset = 0;

    add_segment_to(geometry,offset,{0,0},{0,0});

    for ( int i=0; i < curve.length()-3 ; i++ )
    {
        //Quick and shitty implementation, this should be a Builder
        switch(curve.at(i).toLatin1())
        {
        case 'F' :	//Add new line segment
        {
            QSGGeometry::Point2D start(geometry->vertexDataAsPoint2D()[offset-1]),
                    end(geometry->vertexDataAsPoint2D()[offset-1]);
            switch(direc)
            {
            case dir::R:
                end.x += seg_len;
                break;
            case dir::L:
                end.x -= seg_len;
                break;
            case dir::D:
                end.y -= seg_len;
                break;
            case dir::U:
                end.y += seg_len;
                break;
            }
            add_segment_to(geometry,offset,start,end);
            break;
        }
        case '+' : 	//change dir clockwise
            switch(direc)
            {
            case dir::R:
                direc = dir::D;
                break;
            case dir::D:
                direc = dir::L;
                break;
            case dir::L:
                direc = dir::U;
                break;
            case dir::U:
                direc = dir::R;
                break;
            }
            break;
        case '-' :	//change dir counterclockwise
            switch(direc)
            {
            case dir::R:
                direc = dir::U;
                break;
            case dir::U:
                direc = dir::L;
                break;
            case dir::L:
                direc = dir::D;
                break;
            case dir::D:
                direc = dir::R;
                break;
            }
            break;
        }
    }

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
