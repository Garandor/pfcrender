#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include <QCommandLineOption>
#include <QObject>
#include <QString>
#include <QVector>
#include <QtPlugin>

namespace Plugins {
class Plugin : public QObject {
    Q_OBJECT
public:
    virtual const QString& getName() const;
    virtual QVector<QPair<QString, QCommandLineOption>> getCLIoptions() = 0;

    virtual void* getParams() = 0;

    virtual ~Plugin() {}
};
} // namespace Plugin

using namespace Plugins;
Q_DECLARE_INTERFACE(Plugin, "PFCRender.Plugins.Plugin")
#endif
