/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/

#ifndef PLUGIN_PLUGIN__REGISTRY_H
#define PLUGIN_PLUGIN__REGISTRY_H

#include <QMultiHash>
#include <QString>

class Plugin;

namespace Plugins {
class Plugin_Registry {
private:
    static Plugin_Registry* instance;
    QMultiHash<QString, Plugin&> m_registered;

private:
    Plugin_Registry();
    Q_DISABLE_COPY(Plugin_Registry)

public:
    static const Plugin_Registry* getInstance();
    const Plugin& getPlugin(const QString& serviceName) const;
    const QHash<QString, Plugin&>& getRegistry() const;
};

} // namespace Plugin
#endif
