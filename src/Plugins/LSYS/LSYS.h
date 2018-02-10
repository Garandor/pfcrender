#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include <memory>

#include <QHash>
#include <QObject>
#include <QString>
#include <QtPlugin>

#include "Import.h"

namespace Plugins {
namespace LSYS {

    class LSYS : public Import {
        Q_OBJECT
        Q_INTERFACES(Import Plugin)
        Q_PLUGIN_METADATA(IID "PFCRender.Plugins.Import.LSYS")

    private:
        PluginInfo m_info;

    public:
        LSYS();

        //Plugin Interface Methods
        const Plugins::PluginInfo& getInfo() const override;

        //Import Interface methods
        std::unique_ptr<Model::ModelStringBuilder> getStringBuilder() const override;
    };

} // namespace LSYS
} // namespace Plugin
#endif
