#ifndef PLUGIN_PLUGIN__REGISTRY_H
#define PLUGIN_PLUGIN__REGISTRY_H

#include <QHash>
#include <QString>
#include <QObject>

namespace Plugin
{
class Plugin_Registry
{
private:
	static Plugin_Registry* instance;
	QHash<QString,QObject*> m_registered;

private:
	Plugin_Registry();
	Plugin_Registry(const Plugin_Registry &)= delete ;
	Plugin_Registry& operator=(const Plugin_Registry &) = delete;

public:
	static Plugin_Registry* getInstance();

};

}  // namespace Plugin
#endif
