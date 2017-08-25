
#include "PFCStart.h"

PFCStart::PFCStart()
{
}

void PFCStart::do_stuff()
{
}

int main(int argc, void** argv)
{
	Plugin_Registry plugins = Plugin_Registry.getInstance();
	
	//open config file

	//populate registry

		
	if(argc=0){
		QGuiApplication qapp = new QGuiApplication(argc,argv);
		QQmlApplicationEngine qeng = new QQmlApplicationEngine();
		qeng.load(main.qml);
	}
	else()
	{

	}
	
	return 0;
}
