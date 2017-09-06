#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include "Import.h"

#include <QList>
#include <QObject>
#include <QQuickItem>
#include <QString>
#include<QtPlugin>
#include<memory>

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
    const QString _computeLSYS(QString axiom, ulong iterate);
    std::unique_ptr<QQuickItem> _createQuickItem(const QString& curve );
    std::unique_ptr<QQuickItem> _createGrid();

public:

    //Plugin Interface Methods
    QList<QString> lookupServices() override;
    void execService(QString name, QVariant params) override;
    bool hasService(QString name) override;

    //Import Interface methods
    void* getParams() override;
    std::unique_ptr<QQuickItem> getModel() override;

    ~LSYS() override;
};

}  // namespace LSYS
}  // namespace Plugin
#endif
