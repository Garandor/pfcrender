#include "Plugin_Registry.h"

namespace Plugin
{

Plugin_Registry* Plugin_Registry::getInstance()
{
	if(instance == NULL)
		instance = new Plugin_Registry();
	return instance;
}

Plugin_Registry::Plugin_Registry()
{
}
}  // namespace Plugin
