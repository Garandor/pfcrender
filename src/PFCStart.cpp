#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"

#include "QtCLI/PFCRenderCLI.h"
#include "QtGUI/PFCRenderGUI.h"
#include "QtGUI/QNanoPaintedCurve.h"

#include "projectinfo.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);
    auto cr = Common::Config_Registry::getInstance(); //Note: cr uses plugin_registry so it is implicitly created
    app.setApplicationVersion(VERSION_STRING); //Set Version Information

    if (cr->getOpt("Main.Batch").compare("N/A")) {
        QtCLI::PFCRenderCLI desktop_obj;
    } else {

        //Register custom QML Types
        qmlRegisterType<QtGUI::QNanoPaintedCurve>("sci.pfcrender.qnanorenderedcurve", 1, 0, "QNanoRenderedCurve");

        QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));
        QtGUI::PFCRenderGUI desktop_obj(&qeng);

        return app.exec();
    }
}
