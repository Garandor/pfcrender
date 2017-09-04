#include "LSYS.h"

#include"stringsubst.h"

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
        _computeLSYS( QStringLiteral("L+L"), 2 );
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

    //Build stringsubst object from passed params

    string_subst lsys{1};
    lsys.set_axiom(axiom.toLatin1().data());

    const char *rules[10];
    rules[0]="+";
    rules[1]="L+L-L";

    lsys.set_rules(rules,2);

   lsys.print_all();

   for( ; iterate > 0 ;iterate--)
       lsys.next();

   lsys.print_all();

    //Populate our QQuickItem

    //Return it to the caller
   return mdl;
}

}  // namespace LSYS
}  // namespace Plugin
