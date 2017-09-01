#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include <QList>
#include <QQuickItem>
#include <QString>
#include "Import.h"

namespace Plugin
{
namespace LSYS
{
class LSYS : public QObject, Import
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "PFCRender.Plugin.Import")
    Q_INTERFACES(Plugin::Import)

private:
    std::unique_ptr<QQuickItem> _computeLSYS(QString axiom, int iterate);

public:
    LSYS();

    //Plugin Interface Methods
    QList<QString> lookupServices() override;
    void execService(QString name, QVariant params) override;
    bool hasService(QString name) override ;

    //Import Interface methods
    void* getParams() override;
    std::unique_ptr<QQuickItem> getModel() override;
    ~LSYS() override;

};

}  // namespace LSYS
}  // namespace Plugin
#endif
