#include "Config_Registry.h"
#include "Common/CLIParser.h"
#include "Common/Plugin_Registry.h"
#include <QDebug>
#include <QPair>

#include "Plugins/Plugin.h"

namespace Common {
Config_Registry* Config_Registry::instance = NULL;

const Config_Registry* Config_Registry::getInstance()
{
    if (instance == NULL)
        instance = new Config_Registry();
    return instance;
}

const QString Config_Registry::getOpt(const QString& optName) const
{
    return m_registered.value(optName);
}

void Config_Registry::setOpt(const QPair<QString, QString>& p)
{
    Config_Registry::setOpt(p.first, p.second);
}

void Config_Registry::setOpt(const QString& optName, const QString& optValue)
{
    m_registered.insert(optName, optValue);
    qDebug() << "inserted " << optName << " with " << optValue;
}

Config_Registry::Config_Registry()
    : m_registered{}
{
    //TODO: Populate from Config File

    //TODO::Populate from CLI Parameters
    auto p_clip = CLIParser::getInstance();
    for (auto p : Plugin_Registry::getInstance()->getPlugins()) {
        for (QPair<QString, QCommandLineOption> pair : p->getCLIoptions())
            p_clip->addOption(pair);
    }
    //Parse all known commandline options
    p_clip->parse();

    //Add all options that have been set to the global config store
    QHashIterator<QString, QCommandLineOption> it(p_clip->getOptlist());
    while (it.hasNext()) {
        if (p_clip->getParser().isSet(it.key()))
            setOpt(it.key(), p_clip->getParser().value(it.value()));
    }
}

} // namespace Common
