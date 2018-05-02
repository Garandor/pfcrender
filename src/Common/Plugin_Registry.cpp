#include "Plugin_Registry.h"
#include "Plugins/Plugin.h"
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QLibrary>
#include <QPluginLoader>
namespace Common {
Plugin_Registry* Plugin_Registry::instance = NULL;

Plugin_Registry* Plugin_Registry::getInstance()
{
    if (instance == NULL)
        instance = new Plugin_Registry();
    return instance;
}

Plugins::Plugin* Plugin_Registry::getPlugin(const QString& pluginName) const
{
    return m_registered.value(pluginName);
}

QList<Plugins::Plugin*> Plugin_Registry::getPlugins() const
{
    return m_registered.values();
}

Plugin_Registry::Plugin_Registry()
    : m_registered{}
{
    //Load and store all plugins in the plugin folder
    qDebug() << qApp->applicationDirPath().append("/plugins");
    QDirIterator it(QDir(qApp->applicationDirPath().append("/plugins"), "*", QDir::Unsorted, QDir::Files));
    while (it.hasNext()) {
        QFile f(it.next());
        if (!QLibrary::isLibrary(f.fileName())) {
            qWarning() << "Found garbage file " << f.fileName() << " in plugins folder. Ignoring";
            continue;
        }
        QPluginLoader ldr(f.fileName());
        QObject* plInstance = ldr.instance();
        if (plInstance) {
            ::Plugins::Plugin* plug = qobject_cast<::Plugins::Plugin*>(plInstance);
            if (plug) {
                qDebug() << "inserting plugin " << plug->getInfo().name;
                m_registered.insert(plug->getInfo().name, plug);
                assert(plug == plug->getInfo().plugin);
            }
        } else {
            qWarning() << "Loading of Plugin " << f.fileName() << " failed with :" << ldr.errorString();
        }
    }
}

} // namespace Common
