#include "LSYS.h"

//FXTLIB includes
#include "stringsubst.h"

#include<QSGGeometry>
#include<QSGFlatColorMaterial>

namespace Plugins
{
namespace LSYS
{

bool LSYS::hasService(QString name)
{
    return false;
}

void LSYS::execService(QString name, QVariant params)
{
    if(!name.compare(QStringLiteral("LSYS")))
    {
//        return getModel();
    }
    else{
//        return nullptr;
    }
}

std::unique_ptr<QSGGeometryNode> LSYS::getModel()
{
    //TODO: Make sure this uses move semantics
    const QString curve( _computeLSYS( QList<QString>{"F","F","F+F-F-F-F+F+F+F-F","+","+","-","-"}, 3 ) );

    std::unique_ptr<QSGGeometryNode> mdl = _createGeometry(std::move(curve));
    return mdl;
}

std::unique_ptr<QSGGeometryNode> LSYS::_createGeometry(const QString& curve)
{
    auto geom = std::make_unique<QSGGeometryNode>();

    //Build curve geometry
    auto *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 2);
    geometry->setDrawingMode(GL_LINES);
    geometry->setLineWidth(3);

    constexpr int seg_len =  10;

    //TODO: make interpretation of +- selectable
    enum class dir{
       U,D,L,R
    };
    dir last_dir = dir::R;
    int segcount = 0;

    for (int i=0; i<curve.length();i+=2)
    {
        if(i==0 && curve.at(i)=="F")
        {
        geometry->vertexDataAsPoint2D()[0].set(0, 0);
        geometry->vertexDataAsPoint2D()[1].set(seg_len,0);
        segcount = 1;

        last_dir = dir::R;
        continue;
        }

        //Quick and shitty implementation, this should be a Builder
        switch(curve.at(i-1).toLatin1())
        {
        case '+' :
            switch(last_dir)
            {
            case dir::R:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y-seg_len);
                last_dir = dir::D;
                break;
            case dir::L:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y+seg_len);
                last_dir = dir::U;
                break;
            case dir::U:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x+seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
                last_dir = dir::R;
                break;
            case dir::D:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x-seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
                last_dir = dir::L;
                break;
            }
            break;

        case '-' :
            switch(last_dir)
            {
            case dir::R:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y-seg_len);
                last_dir = dir::D;
                break;
            case dir::L:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x,geometry->vertexDataAsPoint2D()[segcount-1].y+seg_len);
                last_dir = dir::U;
                break;
            case dir::U:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x+seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
                last_dir = dir::R;
                break;
            case dir::D:
                segcount++;
                geometry->vertexDataAsPoint2D()[segcount].set(geometry->vertexDataAsPoint2D()[segcount-1].x-seg_len,geometry->vertexDataAsPoint2D()[segcount-1].y);
                last_dir = dir::L;
                break;
            }
            break;
        }
    }

    //Create Material
    auto *material = new QSGFlatColorMaterial;
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

QList<QString> LSYS::lookupServices()
{
    return QList<QString>{"asd","as"};
}

void* LSYS::getParams()
{
    QList<QString> myParams{};
    return nullptr;
}

LSYS::~LSYS()
{

}

const QString LSYS::_computeLSYS(const QList<QString> definition, ulong iterate)
{
    QString axio(QStringLiteral("F")); //TODO: IGNORE PARAMETER FOR NOW, CHANGE LATER

    //Build stringsubst object from passed params
    string_subst lsys{iterate};	//levels == number of generations == iterates
//    lsys.set_axiom(axio.toLatin1().data());

    lsys.set_axiom("F");

    const char *rules[10];
    rules[0]="F";
    rules[1]="F+F-F-F-F+F+F+F-F";
    rules[2]="+";
    rules[3]="+";
    rules[4]="-";
    rules[5]="-";

    lsys.set_rules(rules,6);

    QString curve{};
    if(lsys.first())
    {
       lsys.print_rules();

       ulong ct = 0;
       char c;
       while ( (c = lsys.current()) != '\0' )
       {
           curve.append(c);
           lsys.next();
       }
    }

    //Magic has been worked, return our result
    return static_cast<const QString>(curve);
}

}  // namespace LSYS
}  // namespace Plugin
