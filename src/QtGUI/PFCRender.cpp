#include "PFCRender.h"
#include<QPluginLoader>
#include<QDir>
#include<QGuiApplication>
#include"Plugins/Plugin_Registry.h"
#include"Plugins/Import.h"
#include<QDebug>


namespace QtGUI
{

    PFCRender::PFCRender()
    {

        //Load plugin from registry

        QDir pluginsDir(qApp->applicationDirPath());
        pluginsDir.cd("../plugins");  //XXX : THIS WILL BREAK ON DEPLOYMENT
        QString pname(::Plugins::Plugin_Registry::getInstance()->getPlugin(QStringLiteral("importLSYS")));
        qDebug() <<  pname;
        qDebug() << pluginsDir.absoluteFilePath(Plugins::Plugin_Registry::getInstance()->getPlugin(QStringLiteral("importLSYS")));
        qDebug() << pluginsDir.absoluteFilePath(::Plugins::Plugin_Registry::getInstance()->getPlugin(QStringLiteral("importLSYS")));

        QPluginLoader ldr(pluginsDir.absoluteFilePath(Plugins::Plugin_Registry::getInstance()->getPlugin(QStringLiteral("importLSYS"))),this);
        QObject* plugin = ldr.instance();
        qDebug() << QVariant(ldr.isLoaded());
        if (plugin) {
                ::Plugins::Import* importer = qobject_cast<::Plugins::Import *>(plugin);
                if (importer)
                {
                    importer->execService(QStringLiteral("LSYS"),QVariant());
                }
        ldr.unload();
        }
        else
        {
            qWarning() << ldr.errorString() << " lo no que siento";
        }

    }

}  // namespace QtGUI
