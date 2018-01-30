#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"

#include "QtCLI/PFCRenderCLI.h"
#include "QtGUI/CustomGeometryModel.h"
#include "QtGUI/PFCRenderGUI.h"

#include "projectinfo.h"

int main(int argc, char** argv)
{
#if NOGUI
    QCoreApplication app(argc, argv);
#else
    //    if (cr->getOpt("batch") == "true") //TODO: Handle batch mode
    //        QCoreApplication app(argc, argv);
    //    else
    QGuiApplication app(argc, argv);
#endif
    //Set Version Information
    app.setApplicationVersion(VERSION_STRING);

    //Creation of registry singletons moved to when they are first accessed

#if NOGUI
    QtCLI::PFCRender_CLI desktop_obj();
#else
    //    if (cr->getOpt("batch").isEmpty()) { //TODO: Handle batch mode
    //Register custom QML Types
    qmlRegisterType<QtGUI::CustomGeometryModel>("Sci.Pfcrender.CustomModel", 1, 0, "CustomGeometryModel");

    //Declare Config_Registry to the QML type system so our plugins can access it
    qmlRegisterSingletonType<Common::Config_Registry>(Common::Config_Registry::URI, Common::Config_Registry::V_MAJ, Common::Config_Registry::V_MIN, Common::Config_Registry::QMLTYPE, Common::Config_Registry::qmlInstance);

    QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));
    QtGUI::PFCRenderGUI desktop_obj(&qeng);
//    }
#endif

    return app.exec();
}
