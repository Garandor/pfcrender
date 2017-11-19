#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "Common/Sequence_Walker.h"

#include "PFCRender.h"
#include "ViewModel/ViewModelBuilder.h"

namespace QtGUI {

void PFCRender::onModelChanged(const QString& mdl)
{
    auto* mdlItem = qobject_cast<ViewModel::CustomGeometryModel*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    if (mdlItem) {
        auto vm = ViewModel::createGeom(mdl);
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

    //now that everything is in place, connect all necessary signals so we can resume normal GUI operation
    // QObject::connect(&m_dMdl, SIGNAL(modelChanged(const QString&)), &m_vm, SLOT(onModelChanged(const QString&)));
    //                        m_dMdl.setModel(std::move(dataModel));
}

} // namespace QtGUI
