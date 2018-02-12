#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"
#include "Common/Sequence_Walker.h"

#include "QtGUI/QNanoPaintedCurve.h"

#include "PFCRenderGUI.h"
#include <iostream>

#include <QTimer>
namespace QtGUI {

auto start = std::chrono::steady_clock::now();
auto end = std::chrono::steady_clock::now();

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
    auto flosnek = std::make_unique<QString>("L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R++-L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R++-L+RR++R+L--L-R-L+R++R-L--LL-R+--L+R++R-L--LL-R+L+R++R-L--LL-R+--L+RR++R+L--L-R+--L+R++R-L--LL-R++-L+RR++R+L--L-R-L+RR++R+L--L-R++-L+RR++R+L--L-R+L+R++R-L--LL-R+--L+R++R-L--LL-R+--L+RR++R+L--L-R+");

    start = std::chrono::steady_clock::now();
    m_mdl.setModel(std::move(flosnek));
}

void PFCRenderGUI::onPaintingDone()
{
    end = std::chrono::steady_clock::now();
    auto dur = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << dur << std::endl;
}

void PFCRenderGUI::post_status(const QString& what)
{
    p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("status"))->setProperty("text", what);
}

PFCRenderGUI::PFCRenderGUI(QQmlApplicationEngine* eng)
    : p_eng(eng)
    , m_mdl()
{

    qDebug() << "steady_clock";
    qDebug() << std::chrono::steady_clock::period::num;
    qDebug() << std::chrono::steady_clock::period::den;
    qDebug() << "steady = " << std::chrono::steady_clock::is_steady;

    //Instantiate everything from the provided sequence
    Common::Sequence_Walker walker;

    post_status(QString(walker.m_stepNames.count()));

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(1000);

    connect(&m_mdl, SIGNAL(modelChanged(QString)), this, SLOT(onModelChanged()));

    auto* mdlItem = qobject_cast<QtGUI::QNanoPaintedCurve*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    connect(mdlItem, SIGNAL(paintingDone()), this, SLOT(onPaintingDone()));

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
