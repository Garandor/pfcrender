#include <QGuiApplication>
#include <QCoreApplication>
#include <QUrl>
#include <QString>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "Plugin/Plugin_Registry.h"
#include "QtGUI/PFCRender.h"

int main(int argc, char** argv)
{
    Plugin::Plugin_Registry* plugins = Plugin::Plugin_Registry::getInstance();
	
	//open config file

	//populate registry

    //XXX: For now, let's not mess with CLI mode
#if 1
        QGuiApplication app(argc,argv);
        QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));

        QtGUI::PFCRender desktop_obj;

        return app.exec();
#else
		QCoreApplication qapp(argc,argv);
		return qapp.exec();
#endif
}
