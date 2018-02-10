
#include "Common/CLIOptions.h"
#include "Common/CLIParser.h"
#include "Common/Plugin_Registry.h"
#include "Plugins/Plugin.h"

#include "Config_Registry.h"

#include <QDebug>
#include <QPair>

namespace Common {
Config_Registry* Config_Registry::instance = nullptr;

Config_Registry* Config_Registry::getInstance()
{
    if (instance == nullptr)
        instance = new Config_Registry();
    return instance;
}

//Enhancement: When using C++17 is possible this should become a std::optional
/**
 * @brief Config_Registry::getOpt
 * @param optName
 * @return the value passed to this option, or an empty string
 */
const QString Config_Registry::getOpt(const QString& optName) const
{
    if (!m_options.contains(optName))
        return QStringLiteral("N/A");
    return m_options.value(optName);
}

void Config_Registry::setOpt(const QPair<QString, QString>& p)
{
    Config_Registry::setOpt(p.first, p.second);
}

void Config_Registry::add_to_sequence(const QString& name)
{
    bool found{ false };
    for (auto p : Common::Plugin_Registry::getInstance()->getPlugins()) {
        if (0 == name.compare(p->getInfo().name, Qt::CaseInsensitive)) //If a plugin exists with the name of the passed arg
        {
            m_sequence.append(p->getInfo().name);
            qDebug() << "Appended plugin" << p->getInfo().name << " to sequence for step " << name;

            found = true;
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
    , m_set{ "THNuernberg", "PFCRender" }
{
    //Fallbacks are confusing since they dont get deleted by clear - so lets not use them
    m_set.setFallbacksEnabled(false);

    //Get or create an instance of the CLI parser to populate with options
    Common::CLIParser clip;

    //Read built-in (core app) options
    for (auto o : Common::builtin_opts) //add config key and cmdline option
        clip.addOption(o); //add pairs of config variables and their cmdlineoptions

    //Read options exposed by Plugins
    for (auto p : Plugin_Registry::getInstance()->getPlugins()) {
        for (auto opt : p->getInfo().co.keys())
            clip.addOption(opt, p->getInfo().co.value(opt, QCommandLineOption("wat"))); //add config key and cmdline option
    }

    //Now that all options are known to CLI Parser, read the commandline
    clip.parse();

    //XXX: Need to load singleton from CLI before loading from file because of --clear switch, (and possibly other future switches) this leads to parsing CLI options twice. Sure there is a better solution

    QHashIterator<QString, QCommandLineOption> it(clip.getOptlist());
    while (it.hasNext()) {
        it.next();
        if (clip.getParser().isSet(it.value()))
            setOpt(it.key(), clip.getParser().value(it.value()));
    }

    //Initialize registry with defaults/last used state from config file unless --clear is provided
    if ((getOpt("Main.Clear").compare("N/A")) != 0) {
        m_set.clear();
    } else {
        for (auto k : m_set.allKeys())
            setOpt(k, m_set.value(k).toString());
    }

    //XXX: Readd from CLI parser to overwrite defaults
    QHashIterator<QString, QCommandLineOption> it2(clip.getOptlist());
    while (it2.hasNext()) {
        it2.next();
        if (clip.getParser().isSet(it2.value())) {
            setOpt(it2.key(), clip.getParser().value(it2.value()));
            qDebug() << "Config_Reg - Read from file: " << it2.key() << " : " << clip.getParser().value(it2.value());
        }
    }

    //populate sequence from positional arguments
    for (auto arg : clip.getParser().positionalArguments())
        add_to_sequence(arg);
}

/**
 * @brief Config_Registry::~Config_Registry
 * Since this is a singleton class, this destructor only gets called on program end and is responsible for saving the application state
 */
Config_Registry::~Config_Registry()
{
    store_to_file();
}

void Config_Registry::store_to_file()
{
    qDebug() << "storing config to disk:" << m_set.fileName();
    auto i = m_options.constBegin();
    while (i != m_options.constEnd()) {

        if (!(i.key().compare("Main.Batch") && i.key().compare("Main.Clear"))) //Never store batchmode operation switch
            ++i;
        else {
            m_set.setValue(i.key(), i.value());
            qDebug() << i.key() << " : " << i.value();
            ++i;
        }
    }

    m_set.sync(); //clear write buffer
}

} // namespace Common
