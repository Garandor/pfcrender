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
#include"ViewModel/CustomGeometryModel.h"
#include"ViewModel/ViewModelFactory.h"

namespace QtGUI
{

void PFCRender::onModelChanged(const QString& mdl)
{
    auto* mdlItem = qobject_cast<ViewModel::CustomGeometryModel*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    if(mdlItem)
    {
        mdlItem->setGeometryNode(std::move(ViewModel::createGeom(mdl)));
    }
}

PFCRender::PFCRender(QQmlApplicationEngine* eng) : p_eng(eng)
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
                     auto dataModel = importer->getModel();

                     QObject::connect(&m_dMdl,SIGNAL(modelChanged(const QString&)),this,SLOT(onModelChanged(const QString&)));

                     m_dMdl.setModel(std::move(dataModel));

                }
        ldr.unload();
        }
        else
        {
            qWarning() << "Plugin Load failed with :" << ldr.errorString() ;
        }


    }

}  // namespace QtGUI
