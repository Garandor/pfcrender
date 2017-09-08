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

        QPluginLoader ldr(pluginsDir.absoluteFilePath(Plugins::Plugin_Registry::getInstance()->getPlugin(QStringLiteral("importLSYS"))),this);
        QObject* plugin = ldr.instance();
        if (plugin) {
                ::Plugins::Import* importer = qobject_cast<::Plugins::Import *>(plugin);
                if (importer)
                {
                    auto mdl = importer->getModel();
                }
        ldr.unload();
        }
        else
        {
            qWarning() << "Plugin Load failed with :" << ldr.errorString() ;
        }

    }

}  // namespace QtGUI
