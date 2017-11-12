#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QString>
#include <QUrl>

#include "Model/LSYSModel.h"
#include "Plugins/Plugin_Registry.h"
#include "QtGUI/PFCRender.h"
#include "ViewModel/CustomGeometryModel.h"

#include "projectinfo.h"

int main(int argc, char** argv)
{
    Plugins::Plugin_Registry* plugins = Plugins::Plugin_Registry::getInstance();

//open config file

//populate registry

//XXX: For now, let's not mess with CLI mode
#if 1
    QGuiApplication app(argc, argv);
#else
    QCoreApplication app(argc, argv);
#endif
    //Set Version Information
    app.setApplicationVersion(VERSION_STRING);

    //Register custom QML Types
    qmlRegisterType<ViewModel::CustomGeometryModel>("sci.pfcrender.customModel", 1, 0, "CustomGeometryModel");

#if 1
    QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));
    QtGUI::PFCRender desktop_obj(&qeng);
#endif

    return app.exec();
}
