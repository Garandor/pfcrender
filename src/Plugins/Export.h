#ifndef PLUGIN_EXPORT_H
#define PLUGIN_EXPORT_H

#include "Plugin.h"

#include "Model/LSYSModel.h"
#include "ViewModel/CustomGeometryModel.h"

class QQuickItem;
class QCommandLineParser;

namespace Plugins {
class Export : public Plugin {
    Q_OBJECT

public:
    /**
     * @brief runs the export plugin
     * @return void
     */
    virtual void exportModel(const ::Model::LSYSModel&) const = 0;

    /**
     * @brief runs the export plugin
     * @return void
     */
    virtual void exportViewModel(const ::ViewModel::CustomGeometryModel&) const = 0;

    virtual ~Export() {}
};
}

using namespace Plugins;
Q_DECLARE_INTERFACE(Export, "PFCRender.Plugins.Export")

#endif
