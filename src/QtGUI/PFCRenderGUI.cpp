#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"
#include "Common/Sequence_Walker.h"

#include "QtGUI/QNanoPaintedCurve.h"

#include "PFCRenderGUI.h"

namespace QtGUI {

void PFCRenderGUI::onModelChanged()
{
    auto* mdlItem = qobject_cast<QtGUI::QNanoPaintedCurve*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    if (mdlItem) {
        mdlItem->onModelChanged(m_mdl.getModel());
    } else {
        qDebug() << "Not currently displaying a curve, ignoring model change";
    }
}

void PFCRenderGUI::onTimeout()
{
    timer->start(100);
    onModelChanged(); //Notify VM that the model changed
}

void PFCRenderGUI::onPaintingDone()
{
    timer->stop();
}

void PFCRenderGUI::post_status(const QString& what)
{
    p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("status"))->setProperty("text", what);
}

PFCRenderGUI::PFCRenderGUI(QQmlApplicationEngine* eng)
    : p_eng(eng)
    , m_mdl()
{
    //Instantiate everything from the provided sequence
    Common::Sequence_Walker walker;

    post_status(QString(walker.m_stepNames.count()));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    QString flosnek{ "L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+" };
    auto* mdlItem = qobject_cast<QtGUI::QNanoPaintedCurve*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));

    m_mdl.setModel(flosnek);

    //now that everything is in place, connect all necessary signals so we can resume normal GUI operation
}

/**
 * @brief PFCRenderGUI::~PFCRenderGUI
 * If this object goes out of scope, that means the program is shutting down. Cleanup the Singletons
 */
PFCRenderGUI::~PFCRenderGUI()
{
    delete Common::Config_Registry::getInstance();
    delete Common::Plugin_Registry::getInstance();
}

} // namespace QtGUI
