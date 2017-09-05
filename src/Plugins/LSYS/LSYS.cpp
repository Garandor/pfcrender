#include "LSYS.h"

#include"stringsubst.h"
#include"string.h"

namespace Plugins
{
namespace LSYS
{

QList<QString> LSYS::lookupServices()
{
    return QList<QString>{"asd","as"};
}

void LSYS::execService(QString name, QVariant params)
{
    if(!name.compare(QStringLiteral("LSYS")))
    {
        _computeLSYS( QString("L+L"), 6 );
    }
}

bool LSYS::hasService(QString name)
{
    return false;
}

void* LSYS::getParams()
{
    QList<QString> myParams{};
    return nullptr;
}

std::unique_ptr<QQuickItem> LSYS::getModel()
{
    return nullptr;
}

LSYS::~LSYS()
{

}


std::unique_ptr<QQuickItem> LSYS::_computeLSYS(QString axiom, int iterate)
{
    //Create a unique pointer to the QuickItem we will create and use as the new model
    std::unique_ptr<QQuickItem> mdl = std::make_unique<QQuickItem>(Q_NULLPTR);

    QString axio(QStringLiteral("F")); //TODO: IGNORE PARAMETER FOR NOW, CHANGE LATER
    std::cout << "Curve: R9-1 for square grid" << std::endl;
    //Build stringsubst object from passed params

    string_subst lsys{50};	//Initial "levels" whatever those are
    lsys.set_axiom(axio.toLatin1().data());

    const char *rules[10];
    rules[0]="F";
    rules[1]="F+F-F-F-F+F+F+F-F";
    rules[2]="+";
    rules[3]="+";
    rules[4]="-";
    rules[5]="-";

    lsys.set_rules(rules,6);

   if(lsys.first())
   {
    lsys.print_rules();
    iterate--;
       for( ; iterate > 0 ;iterate--)
       {
           lsys.next();
//           lsys.print_all();
                    for(int i=0;i<lsys.nlev_+1;i++)
                       std::cout << (char)*lsys.lev_ptr_[i];
         std::cout << std::endl;

       }
}

    //Populate our QQuickItem

    //Return it to the caller
   return mdl;
}

}  // namespace LSYS
}  // namespace Plugin
