#include "stdout.h"
#include "Model/LSYSModel.h"
#include <iostream>

namespace Plugins {
namespace Export {
    namespace Stdout {

        StdoutExport::StdoutExport()
        {
            m_info = PluginInfo{};
            m_info.name = "stdout";
            m_info.desc = "Dump the model string to stdout";
            m_info.conf_opts = {};
            m_info.co = {},
            m_info.plugin = this;
        }

        const Plugins::PluginInfo& StdoutExport::getInfo() const
        {
            return m_info;
        }

        void StdoutExport::exportModel(const Model::LSYSModel& mdl) const
        {
            std::cout << (*mdl.getModel()).toStdString() << std::endl;
        }

    } // namespace Stdout
} // namespace Export
} // namespace Plugin
