#ifndef PLUGIN_IMPORT_H
#define PLUGIN_IMPORT_H

#include <memory>

#include "Plugin.h"

class QQuickItem;
class QCommandLineParser;

namespace Plugins {
class ModifyModel : public Plugin {
    Q_OBJECT

public:
    virtual ~ModifyModel() {}
};
}

using namespace Plugins;
Q_DECLARE_INTERFACE(ModifyModel, "PFCRender.Plugins.ModifyModel")
#endif
