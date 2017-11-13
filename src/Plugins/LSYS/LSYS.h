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
        std::unique_ptr<QString> _computeLSYS(const QList<QString>& definition, const ulong iterate);
        static QList<QCommandLineOption> m_cliopts;

    public:
        std::unique_ptr<QString> getModel(QList<QString> list, ulong it);

        //Plugin Interface Methods
        QList<QString> lookupServices() override;
        void execService(QString name, QVariant params) override;
        bool hasService(QString name) override;
        QList<QCommandLineOption> getCLIoptions() override;

        //Import Interface methods
        void* getParams() override;
        std::unique_ptr<QString> getModel(const QCommandLineParser&) override;
    };

} // namespace LSYS
} // namespace Plugin
#endif
