#include <gsl/gsl>

#include <QByteArray>
#include <QCommandLineParser>
#include <QDebug>
#include <QVariant>

#include "Common/Config_Registry.h"
#include "LSYSModelFactory.h"

#include "LSYS.h"
namespace Plugins {
namespace LSYS {

    LSYS::LSYS()
    {
        m_info = PluginInfo{};
        m_info.name = "LSYS";
        m_info.desc = "Create a PFC description from a Lindenmeyer System";
        m_info.conf_opts = {
            "Plugins.LSYS.rules",
            "Plugins.LSYS.it",
        };
        m_info.co = {
            { "Plugins.LSYS.rules", QCommandLineOption("rules", "Comma seperated list of LSYS axiom and rules for stringsubst", "string") },
            { "Plugins.LSYS.it", QCommandLineOption("it", "Number LSYS iterations to compute", "int") },
        },
        m_info.plugin = this;

        qmlRegisterSingletonType<Common::Config_Registry>(Common::Config_Registry::URI, Common::Config_Registry::V_MAJ, Common::Config_Registry::V_MIN, Common::Config_Registry::QMLTYPE, Common::Config_Registry::qmlInstance);
    }

    const Plugins::PluginInfo& LSYS::getInfo() const
    {
        return m_info;
    }

    std::unique_ptr<Model::ModelFactory> LSYS::getFactory() const
    {
        return std::make_unique<LSYSModelFactory>();
    }

} // namespace LSYS
} // namespace Plugin
