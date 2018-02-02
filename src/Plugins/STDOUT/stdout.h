#pragma once
#include <QString>

#include "Export.h"

namespace Plugins {
namespace Export {
    namespace Stdout {

        class StdoutExport : public Exporter {
            Q_OBJECT
            Q_INTERFACES(Exporter Plugin)
            Q_PLUGIN_METADATA(IID "PFCRender.Plugins.Export.Stdout")

        private:
            PluginInfo m_info;

        public:
            StdoutExport();

            //Plugin Interface Methods
            const Plugins::PluginInfo& getInfo() const override;

            //Export Interface methods
            void exportModel(const ::Model::LSYSModel& mdl) const override;
        };

    } // namespace Stdout
} // namespace Export
} // namespace Plugin
