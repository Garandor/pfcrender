#include "LSYS.h"

#include"stringsubst.h"

namespace Plugin
{
namespace LSYS
{

QList<QString> LSYS::lookupServices()
{
    return QList<QString>{"asd","asd"};
}

auto LSYS::execService(QString name, auto params)
{
	return 0;
}

bool LSYS::hasService(QString name)
{
	return false;
}

std::shared_ptr<QQuickItem> LSYS::_computeLSYS(QString LSYS, int iterate)
{
    //Create a unique pointer to the QuickItem we will create and use as the new model
    std::shared_ptr<QQuickItem> mdl = std::make_shared<QQuickItem>(Q_NULLPTR);

    //call stringsubst


    //Populate our QQuickItem

    //Return it to the caller
    return mdl;
}
}  // namespace LSYS
}  // namespace Plugin
