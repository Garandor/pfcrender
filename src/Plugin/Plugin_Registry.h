/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/


#ifndef PLUGIN_PLUGIN__REGISTRY_H
#define PLUGIN_PLUGIN__REGISTRY_H

#include <QHash>
#include <QString>
#include <QFile>

namespace Plugin
{
class Plugin_Registry
{
private:
	static Plugin_Registry* instance;
    QHash<QString,QString> m_registered;

private:
	Plugin_Registry();
    Q_DISABLE_COPY(Plugin_Registry)


public:
    static Plugin_Registry* const getInstance();
    const QString& getPlugin(const QString& serviceName) const;
};

}  // namespace Plugin
#endif
