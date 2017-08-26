#include <QGuiApplication>
#include <QCoreApplication>
#include <QUrl>
#include <QString>
#include <QQmlApplicationEngine>
#include "Plugin/Plugin_Registry.h"
#include "PFCStart.h"

PFCStart::PFCStart()
{
}

void PFCStart::do_stuff()
{
}

int main(int argc, char** argv)
{
	Plugin::Plugin_Registry* plugins = Plugin::Plugin_Registry::getInstance();
	
	//open config file

	//populate registry

	//XXX: Needs better distinction between CLI and GUI mode	
	if(argc=0){
		QGuiApplication qapp(argc,argv);
		QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:/main.qml")));
		return qapp.exec();
		}
	else
	{
		QCoreApplication qapp(argc,argv);
		return qapp.exec();
	}
}
