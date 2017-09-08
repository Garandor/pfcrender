#include<memory>

#include<QQmlApplicationEngine>
#include<QQuickItem>
#include<QPluginLoader>
#include<QDir>
#include<QGuiApplication>
#include<QDebug>

#include "PFCRender.h"
#include"Plugins/Plugin_Registry.h"
#include"Plugins/Import.h"
#include"Model/CustomGeometryModel.h"


namespace QtGUI
{

    PFCRender::PFCRender(QQmlApplicationEngine* eng)
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
                    auto mdlData = importer->getModel();

                    Model::CustomGeometryModel* mdlItem = qobject_cast<Model::CustomGeometryModel*>(eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
                    if(mdlItem)
                    {
                        mdlItem->setGeometryNode(std::move(mdlData));
                    }

                }
        ldr.unload();
        }
        else
        {
            qWarning() << "Plugin Load failed with :" << ldr.errorString() ;
        }


    }

    void PFCRender::onQmlReady()
    {

    }

}  // namespace QtGUI
