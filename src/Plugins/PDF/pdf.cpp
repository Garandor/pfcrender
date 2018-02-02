#include <gsl/gsl>

#include <QByteArray>
#include <QCommandLineParser>
#include <QDebug>
#include <QVariant>

#include "Common/Config_Registry.h"
#include "QPainterParse.h"

#include "pdf.h"

#include <QPrinter>

namespace Plugins {
namespace Export {
    namespace PDF {

        PDF::PDF()
        {
            m_info = PluginInfo{};
            m_info.name = "PDF";
            m_info.desc = "Create a PDF file from the given data";
            m_info.conf_opts = {
                "Plugins.PDF.outfile"
            };
            m_info.co = {
                { "Plugins.PDF.outfile", QCommandLineOption("ofile", "Output file path for export", "full filepath") },
            },
            m_info.plugin = this;
        }

        const Plugins::PluginInfo& PDF::getInfo() const
        {
            return m_info;
        }

        void PDF::exportModel(const Model::LSYSModel& mdl) const
        {
            //While SVG is supposed to draw colored curves, we can also compute an SVG with default graphical info from the LSYS string
            //TBI
            printPDF(mdl);
        }

        void PDF::printPDF(const Model::LSYSModel& mdl) const
        {
            QPrinter printer{};
            printer.setOutputFileName("/home/osboxes/test.pdf");
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOrientation(QPrinter::Landscape);
            printer.setResolution(QPrinter::HighResolution);
            QPainterParse qpp(*mdl.getModel(), printer);
        }

    } // namespace SVG
} // namespace Export
} // namespace Plugin
