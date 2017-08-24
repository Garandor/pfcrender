#ifndef PLUGIN_PLUGIN__REGISTRY_H
#define PLUGIN_PLUGIN__REGISTRY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Qt/QHashMap.h"
#include "Plugin/Import/Import_Registry.h"

namespace Plugin
{
class Plugin_Registry : public Import::Import_Registry
{
private:
	Qt::QHashMap m_registered;


private:
	Plugin_Registry();

public:
	static Plugin_Registry getInstance();

};

}  // namespace Plugin
#endif
