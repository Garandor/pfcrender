#ifndef PLUGIN_IMPORT_H
#define PLUGIN_IMPORT_H
#include<memory>		//for unique_ptr
#include"Plugin.h"

class QQuickItem;

namespace Plugin
{
class Import : Plugin
{
    /**
    * @brief getModel to register in GUI
    * Since Model is likely a very large QQuickItem, we hand it over as a unique pointer to force using move semantics
    * @return  A unique pointer to the QQuickItem to use as new model
    */
    virtual std::shared_ptr<QQuickItem> getModel();
    virtual ~Import();
};

}

#endif
