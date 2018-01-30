#include <gsl/gsl>

#include <QByteArray>
#include <QCommandLineParser>
#include <QDebug>
#include <QVariant>

#include "Common/Config_Registry.h"
#include "QPainterParse.h"

#include "SVG.h"

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
            QSvgGenerator qsvg;
            qsvg.setFileName("/home/osboxes/test.svg");
            //        qsvg.setSize({ 10000, 10000 });
            QPainterParse qpp(*mdl.getModel(), qsvg);
        }

    } // namespace SVG
} // namespace Export
} // namespace Plugin
