#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include <memory>

#include <QHash>
#include <QObject>
#include <QString>
#include <QtPlugin>

#include "Export.h"

namespace Plugins {
namespace SVG {

    class SVG : public Export {
        Q_OBJECT
        Q_INTERFACES(Export Plugin)
        Q_PLUGIN_METADATA(IID "PFCRender.Plugins.Export.SVG")

    private:
        PluginInfo m_info;

    public:
        SVG();

        //Plugin Interface Methods
        const Plugins::PluginInfo& getInfo() const override;

        //Export Interface methods
        void exportModel(const ::Model::LSYSModel& mdl) const override;
        void exportViewModel(const ::ViewModel::CustomGeometryModel& mdl) const override;

    private:
        void drawSVG();
    };

} // namespace SVG
} // namespace Plugin
#endif
