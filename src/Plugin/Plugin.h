#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include <QList>
#include <QString>

namespace Plugin
{
class Plugin
{

public:
    virtual QList<QString> lookupServices() =0 ;

    //TODO:FIGURE OUT RETURN TYPES FOR THESE, AUTO doesnt work
    virtual void execService(QString name, QVariant params) =0 ;

    virtual void* getParams()=0 ;

    virtual bool hasService(QString name)=0 ;

    virtual ~Plugin() =0 ;
};
}  // namespace Plugin


Q_DECLARE_INTERFACE(Plugin::Import,"PFCRender.Plugin.Import")
#endif

