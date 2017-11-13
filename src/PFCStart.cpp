#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>

#include "Plugins/Plugin_Registry.h"
#include "QtCLI/PFCRender.h"
#include "QtGUI/PFCRender.h"
#include "ViewModel/CustomGeometryModel.h"

#include "projectinfo.h"

int main(int argc, char** argv)
{
    Plugins::Plugin_Registry* plugins = Plugins::Plugin_Registry::getInstance();

//open config file

//populate registry

#if NOGUI
    QCoreApplication app(argc, argv);
#else
    QGuiApplication app(argc, argv);
#endif
    //Set Version Information
    app.setApplicationVersion(VERSION_STRING);

    //Register custom QML Types
    qmlRegisterType<ViewModel::CustomGeometryModel>("sci.pfcrender.customModel", 1, 0, "CustomGeometryModel");

#if NOGUI
    QtCLI::PFCRender desktop_obj();
#else
    QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));
    QtGUI::PFCRender desktop_obj(&qeng);
#endif

    return app.exec();
}
