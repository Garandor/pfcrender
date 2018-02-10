#ifndef PLUGIN_IMPORT_H
#define PLUGIN_IMPORT_H

#include "Model/ModelStringBuilder.h"
#include "Plugin.h"

class QQuickItem;
class QCommandLineParser;

namespace Plugins {
class Import : public Plugin {
    Q_OBJECT

public:
    /**
     * @brief getFactory
     * @return A model factory object
     */
    virtual std::unique_ptr<Model::ModelStringBuilder> getStringBuilder() const = 0;

    virtual ~Import() {}
};
}

using namespace Plugins;
Q_DECLARE_INTERFACE(Import, "PFCRender.Plugins.Import")
#endif
