#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"
#include "Common/Sequence_Walker.h"

#include "PFCRenderGUI.h"
#include "QtGUI/ViewModelBuilder.h"

namespace QtGUI {

void PFCRenderGUI::onModelChanged()
{
    auto* mdlItem = qobject_cast<QtGUI::CustomGeometryModel*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    if (mdlItem) {
        auto vm = QtGUI::createGeom(*(m_mdl.getModel()));
        mdlItem->setGeometryNode(vm);
    }
}

void PFCRenderGUI::post_status(const QString& what)
{
    p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("status"))->setProperty("text", what);
}

PFCRenderGUI::PFCRenderGUI(QQmlApplicationEngine* eng)
    : p_eng(eng)
    , m_mdl()
    , m_vm()
{
    //Instantiate everything from the provided sequence
    Common::Sequence_Walker walker;

    post_status(QString(walker.m_stepNames.count()));

    walker.execute(m_mdl, m_vm);
    onModelChanged(); //XXX: This shouldnt be here

    //we should now have a model and viewmodel in place
    //now that everything is in place, connect all necessary signals so we can resume normal GUI operation
}

/**
 * @brief PFCRenderGUI::~PFCRenderGUI
 * If this object goes out of scope, that means the program is shutting down. Cleanup the Singletons
 */
PFCRenderGUI::~PFCRenderGUI()
{
    Common::Config_Registry::getInstance()->~Config_Registry();
    Common::Plugin_Registry::getInstance()->~Plugin_Registry();
}

} // namespace QtGUI
