#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"

#include "QtCLI/PFCRender.h"
#include "QtGUI/PFCRender.h"
#include "ViewModel/CustomGeometryModel.h"

#include "projectinfo.h"

int main(int argc, char** argv)
{
    //populate registries
    auto pr = Common::Plugin_Registry::getInstance();
    auto cr = Common::Config_Registry::getInstance(); //Note: pr should be initialised before cr because it adds plugin specific CLI options

#if NOGUI
    QCoreApplication app(argc, argv);
#else
    //    if (cr->getOpt("batch") == "true")
    //        QCoreApplication app(argc, argv);
    //    else
    QGuiApplication app(argc, argv);
#endif
    //Set Version Information
    app.setApplicationVersion(VERSION_STRING);

#if NOGUI
    QtCLI::PFCRender desktop_obj();
#else
    if (cr->getOpt("batch").isEmpty()) {
        //Register custom QML Types
        qmlRegisterType<ViewModel::CustomGeometryModel>("sci.pfcrender.customModel", 1, 0, "CustomGeometryModel");

        QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));
        QtGUI::PFCRender desktop_obj(&qeng);
    }
#endif

    return app.exec();
}
