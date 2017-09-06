#ifndef PLUGIN_IMPORT_H
#define PLUGIN_IMPORT_H

#include"Plugin.h"
#include<QQuickPaintedItem>
#include<memory>		//for unique_ptr

class QQuickItem;

namespace Plugins
{
class Import : public Plugin
{
    Q_OBJECT

public:

    /**
    * @brief getModel to register in GUI
    * Since Model is likely a very large QQuickItem, we hand it over as a unique pointer to force using move semantics
    * @return  A unique pointer to the QQuickItem to use as new model
    */
    virtual std::unique_ptr<QQuickPaintedItem> getModel() =0 ;



    virtual ~Import() {}
};

}

using namespace Plugins;
Q_DECLARE_INTERFACE(Import,"PFCRender.Plugins.Import")
#endif
