#include <QDebug>

//FXTLIB include
#include "fxt/stringsubst.h"

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"
#include "LSYS.h"
#include "LSYSModelFactory.h"

namespace Plugins {
namespace LSYS {

    std::unique_ptr<QString> LSYSModelFactory::createModel()
    {
        auto pr = Common::Plugin_Registry::getInstance();
        auto cr = Common::Config_Registry::getInstance();

        Plugin* p = pr->getPlugin("LSYS");

        //Check if all opts are set
        for (auto opt : p->getInfo().conf_opts)
            if (cr->getOpt(opt) == "") {
                qCritical() << "NOT ALL OPTIONS WERE SET: " << opt << " is empty";
                abort();
            }

        //Create the model
        QList<QString> list = cr->getOpt(p->getInfo().conf_opts[0]).split(" ");
        ulong iterates = cr->getOpt(p->getInfo().conf_opts[1]).toULong();
        auto ret = _computeLSYS(list, iterates);

        Ensures(ret.get() != nullptr);
        return ret;
    }

    std::unique_ptr<QString> LSYSModelFactory::_computeLSYS(const QList<QString>& ruleList, const ulong iterates)
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
            //            lsys.print_rules();

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
}
}
