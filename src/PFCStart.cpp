#include <QGuiApplication>
#include <QCoreApplication>
#include <QUrl>
#include <QString>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "Plugins/Plugin_Registry.h"
#include "QtGUI/PFCRender.h"
#include "Model/LSYSModel.h"
#include "ViewModel/CustomGeometryModel.h"

int main(int argc, char** argv)
{
    Plugins::Plugin_Registry* plugins = Plugins::Plugin_Registry::getInstance();
	
	//open config file

	//populate registry

    //XXX: For now, let's not mess with CLI mode
#if 1
        qmlRegisterType<ViewModel::CustomGeometryModel>("sci.pfcrender.customModel", 1, 0, "CustomGeometryModel");


        QGuiApplication app(argc,argv);
        QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));


        QtGUI::PFCRender desktop_obj(&qeng);

        return app.exec();
#else
		QCoreApplication qapp(argc,argv);
		return qapp.exec();
#endif
}
