#include <QDebug>
#include <QPair>

#include "Common/CLIParser.h"
#include "Common/Plugin_Registry.h"
#include "Plugins/Plugin.h"

#include "Config_Registry.h"

namespace Common {
Config_Registry* Config_Registry::instance = nullptr;

Config_Registry* Config_Registry::getInstance()
{
    if (instance == nullptr)
        instance = new Config_Registry();
    return instance;
}

const QString Config_Registry::getOpt(const QString& optName) const
{
    return m_options.value(optName);
}

void Config_Registry::setOpt(const QPair<QString, QString>& p)
{
    Config_Registry::setOpt(p.first, p.second);
}

void Config_Registry::addToSequence(const QString& name)
{
    bool found{ false };
    for (auto p : Common::Plugin_Registry::getInstance()->getPlugins()) {
        if (0 == name.compare(p->getInfo().name, Qt::CaseInsensitive)) //If a plugin exists with the name of the passed arg
        {
            m_sequence.append(p->getInfo().name);
            qDebug() << "Appended plugin" << p->getInfo().name << " to sequence for step " << name;

            break;
        }
    }
    if (!found)
        qCritical() << "No plugin found for supplied positional commandline argument" << name;
}

void Config_Registry::clearSequence()
{
    m_sequence.clear();
}

const QVector<QString> Config_Registry::getSequence() const
{
    return m_sequence;
}

void Config_Registry::setOpt(const QString& optName, const QString& optValue)
{
    m_options.insert(optName, optValue);
    qDebug() << "inserted " << optName << " with " << optValue;
}

Config_Registry::Config_Registry()
    : m_options{}
{
    //TODO: Populate from Config File

    //TODO: Populate from CLI Parameters
    auto p_clip = CLIParser::getInstance();
    for (auto p : Plugin_Registry::getInstance()->getPlugins()) {
        for (auto opt : p->getInfo().co.keys())
            p_clip->addOption(opt, p->getInfo().co.value(opt, QCommandLineOption("wat"))); //TODO: Handle default case
    }
    //Parse all known commandline options
    p_clip->parse();

    //Add all options that have been set to the global config store
    QHashIterator<QString, QCommandLineOption> it(p_clip->getOptlist());
    while (it.hasNext()) {
        it.next();
        if (p_clip->getParser().isSet(it.value()))
            setOpt(it.key(), p_clip->getParser().value(it.value()));
    }

    //populate sequence
    for (auto arg : p_clip->getParser().positionalArguments())
        addToSequence(arg);
}

} // namespace Common
