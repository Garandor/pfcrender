#include"ViewModelFactory.h"

#include<QSGFlatColorMaterial>
#include<QSGGeometryNode>

namespace ViewModel {

QSGGeometryNode *ViewModelFactory::_createGeometry(const QString& curve)
{
    auto geom = new QSGGeometryNode; //As all QSG classes are managed by the scene graph, we need not worry about leaking memory / unique_ptrs / cleanup

    //Count number of segments by counting occurrences of F in string to allocate correct size

    //Build curve geometry
    unsigned int segcount = 0;
    for (QChar c : curve)
        if(c == QChar('F'))segcount++;

    //TODO: Go through string to find Fs so we only allocate a vertex for an actual segment
    auto geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), segcount+1);
    geometry->setVertexDataPattern(QSGGeometry::StaticPattern);	//we won't touch the vertices after they have first been rendered. NOTE: if we do, mark_dirty
    geometry->setDrawingMode(QSGGeometry::DrawLineStrip);	//Draw connected lines each vertex
    geometry->setLineWidth(3);

    assert(segcount > 0);

    //todo: segment size selectable
    constexpr float seg_len =  10.0;

    //TODO: make interpretation of +- selectable
    enum class dir{
       U,D,L,R
    };
    dir direc = dir::R;

    QSGGeometry::Point2D* v = geometry->vertexDataAsPoint2D();
    unsigned int offset = 1;
//    add_segment_to(geometry,offset,{0,0},{0,0});
    v[0] = {0.0f,0.0f};

    for ( const QChar c : curve )
    {
        if(c.isNull())
            break;

        v[offset]=v[offset-1];

        //TODO: Quick and shitty implementation, this should be a Builder
        switch(c.toLatin1())
        {
        case 'F' :	//Add new line segment
        {
            switch(direc)
            {
            case dir::R:
                v[offset].x += seg_len;
                break;
            case dir::L:
                v[offset].x -= seg_len;
                break;
            case dir::D:
                v[offset].y += seg_len;
                break;
            case dir::U:
                v[offset].y -= seg_len;
                break;
            }
            offset++;
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
    geometry->markVertexDataDirty();

    for(int i=0;i<geometry->vertexCount();i++)
        printf("%f:%f\t",v[i].x,v[i].y);
    fflush(stdout);


    //Create Material
    QSGFlatColorMaterial* material = new QSGFlatColorMaterial();
    material->setColor(QColor(255, 0, 0));

    //Assign everything to the node
    geom->setGeometry(geometry);
    geom->setMaterial(material);

    //Make sure the model releases resources when not needed anymore
    geom->setFlag(QSGNode::OwnedByParent,true);
    //Set flags to make sure geometry and material are destroyed with the node
    geom->setFlag(QSGNode::OwnsGeometry);
    geom->setFlag(QSGNode::OwnsMaterial);

    return geom;
}

QSGGeometryNode *createGeom(const QString & mdl)
{
    ViewModelFactory fac;
    return fac._createGeometry(mdl);

}

}
