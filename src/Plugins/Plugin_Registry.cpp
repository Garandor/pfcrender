#include "Plugin_Registry.h"

namespace Plugins
{
Plugin_Registry* Plugin_Registry::instance = NULL;

Plugin_Registry * const Plugin_Registry::getInstance()
{
	if(instance == NULL)
		instance = new Plugin_Registry();
    return instance;
}

const QString Plugin_Registry::getPlugin(const QString& serviceName) const
{
    return m_registered.value(serviceName);
}

Plugin_Registry::Plugin_Registry() :  m_registered{}
{
    m_registered.insert("importLSYS",QString("libplugin_LSYS"));
}

}  // namespace Plugin
