#ifndef PLUGIN_EXPORT_H
#define PLUGIN_EXPORT_H

#include "Plugin.h"

#include "Model/LSYSModel.h"

class QQuickItem;
class QCommandLineParser;

namespace Plugins {
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
<<<<<<< HEAD
Q_DECLARE_INTERFACE(Export, "PFCRender.Plugins.Export")
=======
Q_DECLARE_INTERFACE(Exporter, "PFCRender.Plugins.Exporter")
>>>>>>> stdout dumper plugin

#endif
