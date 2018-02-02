#include <QDebug>

#include "Sequence_Walker.h"

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"

#include "Plugins/Export.h"
#include "Plugins/Import.h"
#include "Plugins/ModifyModel.h"
#include "Plugins/ModifyVM.h"

Common::Sequence_Walker::Sequence_Walker()
    : m_stepNames()
{
    for (auto step : Common::Config_Registry::getInstance()->getSequence())
        addStep(step);
    Common::Config_Registry::getInstance()->clearSequence();
}

void Common::Sequence_Walker::addStep(const QString& stepName)
{
    m_stepNames.append(stepName);
}
/**
 * @brief Common::Sequence_Walker::execute
 * @param mod The model to be given to modify and export plugins. Unused by import
 *
 * sequence:
 *	check if step is plugin
 * 	get the factory
 * 	execute build
 * 	put result where it belongs
 */
void Common::Sequence_Walker::execute(Model::LSYSModel& mod)
{
    auto pr = Plugin_Registry::getInstance();

    for (auto step : m_stepNames) {
        //going by plugin type, execute get factory
        auto plugin = pr->getPlugin(step);

        //Case import plugin
        auto import = qobject_cast<Plugins::Import*>(plugin);
        if (import) {
            qDebug() << "Executing import plugin " << import->getInfo().name;
            auto factory = import->getFactory();
            mod.setModel(factory->createModel());
            continue;
        }

        //TODO: Case modify model plugin
        //        auto modmod = qobject_cast<Plugins::ModifyModel*>(plugin);
        //        if (!modmod == nullptr) {
        //            auto factory = modmod->getFactory();
        //            auto mdl = factory.modifyModel(owner.m_mdl);
        //            owner.m_mdl = mdl;
        //            continue;
        //        }

        //TODO: Case export plugin
        auto exportr = qobject_cast<Plugins::Exporter*>(plugin);
        if (exportr) {
            qDebug() << "Executing export plugin " << exportr->getInfo().name;
            exportr->exportModel(mod);
            continue;
        }
    }
}
