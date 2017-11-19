#ifndef PLUGIN_IMPORT_H
#define PLUGIN_IMPORT_H

#include <memory>

#include "Plugin.h"

class QQuickItem;
class QCommandLineParser;

namespace Plugins {
class ModifyVM : public Plugin {
    Q_OBJECT

public:
    /**
    * @brief getModel to create model string from this plugin
    * Since Model is likely a very large String, we hand it over as a unique pointer to force using move semantics
    * @return  A unique pointer to the QString to use as new model
    */

    virtual std::unique_ptr<QString> getModel(const QCommandLineParser&) = 0;

    virtual ~Import() {}
};
}

using namespace Plugins;
Q_DECLARE_INTERFACE(ModifyVM, "PFCRender.Plugins.ModifyVM")
#endif
