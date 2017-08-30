#ifndef PLUGIN_LSYS_LIB_L_S_Y_S_H
#define PLUGIN_LSYS_LIB_L_S_Y_S_H

#include <QList>
#include <QQuickItem>
#include <QString>
#include <QQuickItem>
#include "Import.h"

namespace Plugin
{
namespace LSYS
{
class LSYS : public QObject, Import
{
private:
	std::unique_ptr<QQuickItem> _computeLSYS(QString LSYS, int iterate);

public:
    LSYS();
	QList<QString> lookupServices();

	auto execService(QString name, auto params);

	bool hasService(QString name);

    //Import Interface methods
    virtual std::unique_ptr<QQuickItem> getModel() override;
    virtual ~LSYS() override;

};

}  // namespace LSYS
}  // namespace Plugin
#endif
