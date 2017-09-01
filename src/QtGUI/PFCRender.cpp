#include "PFCRender.h"
#include<QPluginLoader>
#include<QDir>
#include<QGuiApplication>
#include"Plugin_Registry.h"
#include"Import.h"

namespace QtGUI
{

    PFCRender::PFCRender()
    {

        //Load plugin from registry

        QDir pluginsDir(qApp->applicationDirPath());
        pluginsDir.cd("Plugins");
        QPluginLoader ldr(pluginsDir.absoluteFilePath(Plugin::Plugin_Registry::getInstance()->getPlugin(QStringLiteral("importLSYS"))),this);

        QObject *plugin = ldr.instance();
        if (plugin) {
                ::Plugin::Import* importer = qobject_cast<::Plugin::Import *>(plugin);
                if (importer)
                {
                    importer->execService(QStringLiteral("LSYS"),QVariant());
                }
        ldr.unload();
        }

    }

}  // namespace QtGUI
