#include "LSYS.h"
#include <gsl/gsl>

//FXTLIB includes
#include "fxt/stringsubst.h"

#include <QByteArray>
#include <QCommandLineParser>
#include <QDebug>
#include <QVariant>

#include "Common/Config_Registry.h"

#include <vector>

namespace Plugins {
namespace LSYS {

    //TODO: Make this a QHash of unique Option Name and QCommandlineOption
    QVector<QPair<QString, QCommandLineOption>> LSYS::getCLIoptions()
    {
        return cliopts;
    }

    const QString& LSYS::getName() const
    {
        return QString("LSYS");
    }

    std::unique_ptr<QString> LSYS::getModel()
    {
        //TODO: Make sure this uses move semantics
        auto cr = Common::Config_Registry::getInstance();

        //Check if all opts are set
        for (auto p : cliopts)
            if (cr->getOpt(p.left()) == "")
                qFatal() << "NOT ALL OPTIONS WERE SET: " << p.left() << " is empty";

        //CCreate the model
        QList<QString> list = cr->getOpt(cliopts[0].left()).split(" ");
        ulong iterates = cr->getOpt(cliopts[1].left()).toULong();
        auto ret = _computeLSYS(list, iterates);

        Ensures(ret.get() != nullptr);
        return ret;
    }
}

//for manual / testing invocation
std::unique_ptr<QString> LSYS::getModel(QList<QString> list, ulong it)
{
    auto ret = _computeLSYS(list, it);
    return ret;
}

std::unique_ptr<QString> LSYS::_computeLSYS(const QList<QString>& ruleList, const ulong iterates)
{
    Expects(ruleList.count() >= 3); //need at least axiom and one rule
    Expects(ruleList.count() % 2 != 0); //need even number of rules + 1 axiom

    //Build stringsubst object from passed params
    string_subst lsys{ iterates }; //levels == number of generations == iterates

    //Prepare parameters for stringsubst
    //save c-string representations of unicode QString rule params in temp vector
    //needed because toLatin1 creates only temporary objects
    std::vector<QByteArray> rules{};
    for (int i = 0; i < ruleList.count(); i++) {
        rules.push_back(ruleList.at(i).toLatin1());
    }

    //now create a ptr vector to those strings to hand to stringsubst
    std::vector<const char*> vs;
    for (QByteArray& rr : rules)
        vs.push_back(rr.constData());

    //finally we can hand over a char **
    lsys.set_axiom(vs[0]); //First rule is axiom
    lsys.set_rules((vs.data() + 1), vs.size() - 1); //other parameters are mappings

    //Run stringsubst
    auto curve = std::make_unique<QString>();
    if (lsys.first()) {
        lsys.print_rules();

        ulong ct = 0;
        char c;
        while ((c = lsys.current()) != '\0') {
            curve->append(c);
            lsys.next();
        }
    }

    //Magic has been worked, return our result
    return curve;
}

} // namespace LSYS
} // namespace Plugin
