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

public:
	static Plugin_Registry* getInstance();

};

}  // namespace Plugin
#endif
