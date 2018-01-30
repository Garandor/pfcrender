#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include <memory>

#include <QHash>
#include <QObject>
#include <QString>
#include <QtPlugin>

#include "Export.h"

namespace Plugins {
namespace Export {
    namespace SVG {

        class SVG : public Exporter {
            Q_OBJECT
            Q_INTERFACES(Exporter Plugin)
            Q_PLUGIN_METADATA(IID "PFCRender.Plugins.Export.SVG")

        private:
            PluginInfo m_info;

        public:
            SVG();
            virtual ~SVG() {}

            //Plugin Interface Methods
            const Plugins::PluginInfo& getInfo() const override;

            //Export Interface methods
            void exportModel(const ::Model::LSYSModel& mdl) const override;

        private:
            void drawSVG(const Model::LSYSModel& mdl) const;
        };

    } // namespace SVG
} // namespace Export
} // namespace Plugin
#endif
