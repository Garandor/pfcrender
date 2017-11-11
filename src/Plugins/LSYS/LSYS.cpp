#include "LSYS.h"

//FXTLIB includes
#include "fxt/stringsubst.h"

#include<assert.h>
#include<QCommandLineParser>
#include<QVariant>
#include<QDebug>

namespace Plugins
{
namespace LSYS
{
    QList<QCommandLineOption> cliopts{
    QCommandLineOption ("lsys", "Comma seperated list of LSYS axiom and rules for stringsubst", "string"),
    QCommandLineOption ("it", "Number LSYS iterations to compute", "int")
    };

bool LSYS::hasService(QString name)
{
    return false;
}

QList<QCommandLineOption> LSYS::getCLIoptions()
{
    return cliopts;
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

std::unique_ptr<QString> LSYS::getModel(const QCommandLineParser& parseArgs)
{
    //TODO: Make sure this uses move semantics

    if(parseArgs.isSet(cliopts.at(0))  && parseArgs.isSet(cliopts.at(1)))
    {
        QList<QString>list = parseArgs.value(cliopts.at(0)).split(" ");
        ulong  iterates = parseArgs.value(cliopts.at(1)).toULong();
        auto ret = _computeLSYS( list , iterates );
        return ret;
    }
}

//for manual / testing invocation
std::unique_ptr<QString> LSYS::getModel(QList<QString> list, ulong it)
{
    auto ret = _computeLSYS(list, it );
    return ret;
}

LSYS::~LSYS()
{

}

std::unique_ptr<QString> LSYS::_computeLSYS(const QList<QString>& ruleList,const ulong iterates)
{
    assert(ruleList.count() >= 3); //need at least axiom and one rule
    assert(ruleList.count() %2 != 0); //need even number of rules + 1 axiom

    //Build stringsubst object from passed params
    string_subst lsys{iterates};	//levels == number of generations == iterates


    //Prepare parameters for stringsubst
    //save c-string representations of unicode QString rule params in temp vector
    //needed because toLatin1 creates only temporary objects
    std::vector<QByteArray> rules{};
    for(int i = 0; i < ruleList.count();i++)
    {
        rules.push_back(ruleList.at(i).toLatin1());
    }
    for (auto s: rules)
        qDebug() << s;

    //map c-string pointers in array
    const char * r[rules.size()];
    for (int i = 0; i < rules.size();i++)
        r[i] = rules.data()[i];

    //finally we can hand over a char **
    lsys.set_axiom(r[0]);						//First rule is axiom
    lsys.set_rules((r+1),ruleList.count()-1);	//other parameters are mappings

    //Run stringsubst
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
