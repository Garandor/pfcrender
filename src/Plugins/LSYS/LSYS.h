#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include <memory>

#include <QList>
#include <QObject>
#include <QString>
#include <QtPlugin>

#include "Import.h"

class QCommandLineParser;

namespace Plugins {
namespace LSYS {

    class LSYS : public Import {
        Q_OBJECT
        Q_INTERFACES(Import Plugin)
        Q_PLUGIN_METADATA(IID "PFCRender.Plugins.Import.LSYS")

    private:
        /**
          * cliopts - Hash marking config values this plugin exports
          * Key is the unique string, QCommandLineOption is used by the CLI Parser
          */
        QVector<QPair<QString, QCommandLineOption>> cliopts{
            { "Plugins.LSYS.lsys", QCommandLineOption("lsys", "Comma seperated list of LSYS axiom and rules for stringsubst", "string") },
            { "Plugins.LSYS.it", QCommandLineOption("it", "Number LSYS iterations to compute", "int") }
        };

    private:
        std::unique_ptr<QString> _computeLSYS(const QList<QString>& definition, const ulong iterate);

    public:
        std::unique_ptr<QString> getModel(QList<QString> list, ulong it);

        //Plugin Interface Methods
        QVector<QPair<QString, QCommandLineOption>> getCLIoptions() override;
        const QString& getName() const override;

        //Import Interface methods
        std::unique_ptr<QString> getModel(const QCommandLineParser&) override;
    };

} // namespace LSYS
} // namespace Plugin
#endif
