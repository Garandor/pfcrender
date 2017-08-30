/**
* @class Plugin_Registry This class holds filenames of registered plugins and returns them by names of the services they expose. What to do with the files is up to the caller
*
**/


#ifndef PLUGIN_PLUGIN__REGISTRY_H
#define PLUGIN_PLUGIN__REGISTRY_H

#include <QHash>
#include <QString>

namespace Plugin
{
class Plugin_Registry
{
private:
	static Plugin_Registry* instance;
	QHash<QString,QString> m_registered;

private:
	Plugin_Registry();
	Plugin_Registry(const Plugin_Registry &)= delete ;
	Plugin_Registry& operator=(const Plugin_Registry &) = delete;


public:
	static Plugin_Registry* getInstance();
	QString getPlugin(QString serviceName);
};

}  // namespace Plugin
#endif
