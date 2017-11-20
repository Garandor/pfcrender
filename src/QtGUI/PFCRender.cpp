#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "Common/Sequence_Walker.h"

#include "PFCRender.h"
#include "ViewModel/ViewModelBuilder.h"

namespace QtGUI {

void PFCRender::onModelChanged()
{
    auto* mdlItem = qobject_cast<ViewModel::CustomGeometryModel*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    if (mdlItem) {
        auto vm = ViewModel::createGeom(*(m_mdl.getModel()));
        mdlItem->setGeometryNode(vm);
    }
}

void PFCRender::post_status(const QString& what)
{
    p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("status"))->setProperty("text", what);
}

PFCRender::PFCRender(QQmlApplicationEngine* eng)
    : p_eng(eng)
    , m_mdl()
    , m_vm()
{
    //Instantiate everything from the provided sequence
    Common::Sequence_Walker walker;

    post_status(QString(walker.m_stepNames.count()));

    walker.execute(m_mdl, m_vm);
    onModelChanged();

    //we should now have a model and viewmodel in place
    //now that everything is in place, connect all necessary signals so we can resume normal GUI operation
}

} // namespace QtGUI
