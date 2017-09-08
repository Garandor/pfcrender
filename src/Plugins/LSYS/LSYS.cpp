#include "LSYS.h"

//FXTLIB includes
#include "stringsubst.h"

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
        return getModel();
    }
    else{
        return nullptr;
    }
}

QSGGeometryNode* LSYS::getModel()
{
    //TODO: Make sure this uses move semantics
    const QString curve( _computeLSYS( QList<QString>{"F","F","F+F-F-F-F+F+F+F-F","+","+","-","-"}, 3 ) );

    auto mdl = _createGeometry(std::move(curve));
    return mdl;
}

auto LSYS::_createGeometry(const QString& curve)
{
    QSGGeometryNode* geom = new QSGGeometryNode;

    //Set Geometry
    //TODO: build curve from LSYS
    QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 2);
    geometry->setDrawingMode(GL_LINES);
    geometry->setLineWidth(3);
    geometry->vertexDataAsPoint2D()[0].set(0, 0);
    geometry->vertexDataAsPoint2D()[1].set(width(), height());

    //Create Material
    QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
    material->setColor(QColor(255, 0, 0));

    //Assign everything to the node
    geom->setGeometry(geometry);
    geom->setMaterial(material);

    //Set flags to makes sure geometry and material are destroyed with the node
    geom->setFlag(QSGNode::OwnedByParent);
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


void* LSYS::getParams()
{
    QList<QString> myParams{};
    return nullptr;
}
LSYS::~LSYS()
{

}


const QString LSYS::_computeLSYS(QString axiom, ulong iterate)
{
    //Create a unique pointer to the QuickItem we will create and use as the new model
    std::unique_ptr<QQuickItem> mdl = std::make_unique<QQuickItem>(Q_NULLPTR);

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
