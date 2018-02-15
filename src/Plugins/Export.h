#ifndef PLUGIN_EXPORT_H
#define PLUGIN_EXPORT_H

#include "Plugin.h"

#include "Model/LSYSModel.h"

class QQuickItem;
class QCommandLineParser;

namespace Plugins {
/**
 * @brief The Exporter interface
 */
class Exporter : public Plugin {
    Q_OBJECT

public:
    /**
     * @brief runs the export plugin
     * @return void
     */
    virtual void exportModel(const ::Model::LSYSModel&) const = 0;

    virtual ~Exporter() {}
};
}

using namespace Plugins;
Q_DECLARE_INTERFACE(Exporter, "PFCRender.Plugins.Exporter")

#endif
