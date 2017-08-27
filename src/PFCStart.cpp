#include <QGuiApplication>
#include <QCoreApplication>
#include <QUrl>
#include <QString>
#include <QQmlApplicationEngine>
#include "Plugin/Plugin_Registry.h"

int main(int argc, char** argv)
{
    Plugin::Plugin_Registry* plugins = Plugin::Plugin_Registry::getInstance();
	
	//open config file

	//populate registry

    //XXX: For now, let's not mess with CLI mode
#if 1
		QGuiApplication qapp(argc,argv);
        QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));
		return qapp.exec();
#else
		QCoreApplication qapp(argc,argv);
		return qapp.exec();
#endif
}
