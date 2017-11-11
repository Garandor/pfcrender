#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include <QObject>
#include <QList>
#include <QString>
#include <QtPlugin>
#include<QCommandLineOption>

namespace Plugins
{
class Plugin : public QObject
{
    Q_OBJECT
public:
    virtual QList<QString> lookupServices() =0 ;

    //TODO:FIGURE OUT RETURN TYPES FOR THESE, AUTO doesnt work
    virtual void execService(QString name, QVariant params) =0 ;

    virtual QList<QCommandLineOption> getCLIoptions() = 0;

    virtual void* getParams()=0 ;

    virtual bool hasService(QString name)=0 ;

    virtual ~Plugin() {}
};
}  // namespace Plugin

using namespace Plugins;
Q_DECLARE_INTERFACE(Plugin,"PFCRender.Plugins.Plugin")
#endif

