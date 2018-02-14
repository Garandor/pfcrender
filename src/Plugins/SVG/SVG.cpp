#include <gsl/gsl>

#include <QByteArray>
#include <QCommandLineParser>
#include <QDebug>
#include <QVariant>

#include "Common/Config_Registry.h"
#include "QPainterParse.h"

#include "SVG.h"

#include <QFileInfo>
#include <QSvgGenerator>

namespace Plugins {
namespace Export {
    namespace SVG {

        SVG::SVG()
        {
            m_info = PluginInfo{};
            m_info.name = "SVG";
            m_info.desc = "Create an SVG file from the given data";
            m_info.conf_opts = {
                "Plugins.SVG.outfile"
            };
            m_info.co = {
                { "Plugins.SVG.outfile", QCommandLineOption("ofile", "Output file path for export", "full filepath") },
                { "Plugins.SVG.force", QCommandLineOption("force", "Force overwriting existing files") }
            },
            m_info.plugin = this;
        }

        const Plugins::PluginInfo& SVG::getInfo() const
        {
            return m_info;
        }

        void SVG::exportModel(const Model::LSYSModel& mdl) const
        {
            //While SVG is supposed to draw colored curves, we can also compute an SVG with default graphical info from the LSYS string
            //TBI
            drawSVG(mdl);
        }

        void SVG::drawSVG(const Model::LSYSModel& mdl) const
        {
            QString ofile = Common::Config_Registry::getInstance()->getOpt("Plugins.SVG.outfile");
            QString force = Common::Config_Registry::getInstance()->getOpt("Plugins.SVG.force");

            if (!ofile.compare("N/A")) {
                qWarning() << "No output filename given";
                return;
            }

            if (QFileInfo(ofile).exists() && !force.compare("N/A")) {
                qWarning() << "Not overwriting existing file without --force";
                return;
            }

            if (!QFileInfo(ofile).isWritable()) {
                qWarning() << "Specified location " << ofile << ".svg is not writable";
                return;
            }
            qDebug() << "PDF: Writing to " << ofile;

            QSvgGenerator qsvg;
            qsvg.setFileName(ofile);
            //        qsvg.setSize({ 10000, 10000 });
            QPainterParse qpp(*mdl.getModel(), qsvg);
        }

    } // namespace SVG
} // namespace Export
} // namespace Plugin
