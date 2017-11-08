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
//        return getModel();
    }
    else{
//        return nullptr;
    }
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

std::unique_ptr<QString> LSYS::getModel()
{
        //TODO: Make sure this uses move semantics
    auto ret = _computeLSYS(QList<QString>{"F","F","F+F-F-F-F+F+F+F-F","+","+","-","-"}, 3 );

    return ret;
}

LSYS::~LSYS()
{

}

std::unique_ptr<QString> LSYS::_computeLSYS(const QList<QString> definition, ulong iterate)
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

    auto curve = std::make_unique<QString>();
    if(lsys.first())
    {
       lsys.print_rules();

       ulong ct = 0;
       char c;
       while ( (c = lsys.current()) != '\0' )
       {
           curve->append(c);
           lsys.next();
       }
    }

    //Magic has been worked, return our result
    return curve;
}

}  // namespace LSYS
}  // namespace Plugin
