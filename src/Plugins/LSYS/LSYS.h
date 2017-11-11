#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include<memory>

#include <QList>
#include <QObject>
#include <QSGGeometryNode>
#include <QString>
#include<QtPlugin>

#include "Import.h"

namespace Plugins
{
namespace LSYS
{
class LSYS : public Import
{
    Q_OBJECT
    Q_INTERFACES(Import)
    Q_PLUGIN_METADATA(IID "PFCRender.Plugins.Import.LSYS")

private:
    std::unique_ptr<QString> _computeLSYS( const QList<QString>& definition, const ulong iterate );

public:
    //Plugin Interface Methods
    QList<QString> lookupServices() override;
    void execService(QString name, QVariant params) override;
    bool hasService(QString name) override;
    QList<QCommandLineOption> getCLIoptions() override;


    //Import Interface methods
    void* getParams() override;
    std::unique_ptr<QString> getModel() override;

    ~LSYS() override;
};

}  // namespace LSYS
}  // namespace Plugin
#endif
