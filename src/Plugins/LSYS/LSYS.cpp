#include "LSYS.h"

//FXTLIB includes
#include "stringsubst.h"
#include "PFCModel.h"

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
        getModel();
        return;
    }
}

std::unique_ptr<QQuickPaintedItem> LSYS::getModel()
{
    //TODO: Make sure this uses move semantics
    const QString curve( _computeLSYS( QString("L+L"), 3 ) );

    auto paintedItem = _createQQuickPaintedItem(std::move(curve));

    return paintedItem;
}

auto LSYS::_createQQuickPaintedItem(const QString& curve)
{
    //Build the Painter from our curve
    std::unique_ptr<PFCModel> mdl{};

    QPainter p{mdl};

   //TODO: If this is not a case for a builder, I don't know what is
//    class enum orientation{
//        LEFT;
//        RIGHT;
//                UP;
//                DOWN;
//    };

    for (const QChar& c : curve )
    {
        switch (c.toLatin1())
        {
         case 'F' : {
            break;
        }
        case '+' : {
            break;
        }
        case '-' : {
            break;
        }
        }

    }

    return mdl;
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
