#include <gsl/gsl>

#include "BboxParse.h"
#include "Common/Config_Registry.h"
#include "QPainterParse.h"
#include "pdf.h"

#include <QByteArray>
#include <QCommandLineParser>
#include <QDebug>
#include <QFileInfo>
#include <QPrinter>
#include <QString>
#include <QVariant>

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
                { "Plugins.PDF.outfile", QCommandLineOption("ofile", "Output file path for export", "full filepath no file extension") },
                { "Plugins.PDF.force", QCommandLineOption("force", "Force overwriting existing files") }
            },
            m_info.plugin = this;
        }

        const Plugins::PluginInfo& PDF::getInfo() const
        {
            return m_info;
        }

        void PDF::exportModel(const Model::LSYSModel& mdl) const
        {
            printPDF(mdl);
        }

        void PDF::printPDF(const Model::LSYSModel& mdl) const
        {
            QPrinter printer{};

            QString ofile = Common::Config_Registry::getInstance()->getOpt("Plugins.PDF.outfile");
            QString force = Common::Config_Registry::getInstance()->getOpt("Plugins.PDF.force");

            if (!ofile.compare("N/A")) {
                qWarning() << "No output filename given";
                return;
            }

            if (QFileInfo(ofile).exists() && !force.compare("N/A")) {
                qWarning() << "Not overwriting existing file without --force";
                return;
            }

            if (!QFileInfo(ofile).isWritable()) {
                qWarning() << "Specified location " << ofile << ".pdf is not writable";
                return;
            }
            qDebug() << "PDF: Writing to " << ofile;
            printer.setOutputFileName(ofile);

            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOrientation(QPrinter::Landscape);
            printer.setResolution(QPrinter::HighResolution);

            QRectF bounding_box = Export::BboxParse::getBbox(*mdl.getModel());

            QPointF translate = -bounding_box.topLeft();
            double scale = qMin(printer.pageRect().width() / bounding_box.width(), printer.pageRect().height() / bounding_box.height());
            qDebug() << "PDF: " << translate << scale;
            QPainterParse qpp(*mdl.getModel(), printer, translate, scale);
        }

    } // namespace SVG
} // namespace Export
} // namespace Plugin
