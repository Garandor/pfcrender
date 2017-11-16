/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/

#ifndef PLUGIN_PLUGIN__REGISTRY_H
#define PLUGIN_PLUGIN__REGISTRY_H

#include <QHash>
#include <QString>

namespace Plugins {
class Plugin;
}

namespace Common {

class Plugin_Registry {
private:
    static Plugin_Registry* instance;
    QHash<QString, Plugins::Plugin*> m_registered;

private:
    Plugin_Registry();
    Q_DISABLE_COPY(Plugin_Registry)

public:
    static const Plugin_Registry* getInstance();
    Plugins::Plugin* getPlugin(const QString& pluginName) const;
    QList<Plugins::Plugin*> getPlugins() const;
};

} // namespace Common
#endif
