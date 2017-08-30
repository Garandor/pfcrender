#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include <QList>
#include <QString>

namespace Plugin
{
class Plugin
{
public:
	virtual QList<QString> lookupServices()=0;

    virtual auto execService() -> int =0;

	virtual bool hasService()=0;

};

}  // namespace Plugin
#endif
