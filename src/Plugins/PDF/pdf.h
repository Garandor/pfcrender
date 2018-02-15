#pragma once

#include <memory>

#include <QHash>
#include <QObject>
#include <QString>
#include <QtPlugin>

#include "Export.h"

namespace Plugins {
namespace Export {
    namespace PDF {

        /**
         * @brief The PDF class
         * An exporter for PDFs
         * Fits a model to an A4 page and prints to PDF
         * \todo Make page characteristis user selectable
         */
        class PDF : public Exporter {
            Q_OBJECT
            Q_INTERFACES(Exporter Plugin)
            Q_PLUGIN_METADATA(IID "PFCRender.Plugins.Export.PDF")

        private:
            PluginInfo m_info;

        public:
            PDF();
            virtual ~PDF() {}

            //Plugin Interface Methods
            const Plugins::PluginInfo& getInfo() const override;

            //Export Interface methods
            void exportModel(const ::Model::LSYSModel& mdl) const override;

        private:
            void printPDF(const Model::LSYSModel& mdl) const;
        };

    } // namespace PDF
} // namespace Export
} // namespace Plugin
