#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include <QCommandLineOption>
#include <QHash>
#include <QObject>
#include <QString>
#include <QVector>
#include <QtPlugin>
#include <gsl/gsl>

namespace Plugins {

class Plugin;

//XXX: Most of this is static info
struct PluginInfo {
    QString name;
    QString desc;
    QVector<QString> conf_opts; //names of config settings relating to this plugin
    QHash<QString, QCommandLineOption> co; //needs association of conf option to QCLO object
    Plugin* plugin;
};

class Plugin : public QObject {
    Q_OBJECT
public:
    virtual const PluginInfo& getInfo() const = 0;

    virtual ~Plugin() {}
};
} // namespace Plugin

using namespace Plugins;
Q_DECLARE_INTERFACE(Plugin, "PFCRender.Plugins.Plugin")
#endif
