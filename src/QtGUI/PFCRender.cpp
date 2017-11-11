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

#include"CLI/CLIParser.h"

namespace QtGUI
{

void PFCRender::onModelChanged(const QString& mdl)
{
    auto* mdlItem = qobject_cast<ViewModel::CustomGeometryModel*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    if(mdlItem)
    {
        mdlItem->setGeometryNode(ViewModel::createGeom(mdl));
    }
}

void PFCRender::post_status(const QString &what)
{
    p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("status"))->setProperty("text",what);
}

PFCRender::PFCRender(QQmlApplicationEngine* eng) : p_eng(eng)
    {
        //Load plugin from registry
        QDir pluginsDir(qApp->applicationDirPath());
        pluginsDir.cd("../plugins");  //XXX : THIS WILL BREAK ON DEPLOYMENT


        //get CLI options
        ::CLI::CLIParser* p_clip = ::CLI::CLIParser::getInstance();

        //Iterate through all registered plugins, load them, get their info (XXX: inefficient)
        for(const QString& p : Plugins::Plugin_Registry::getInstance()->getRegistry().values())
        {
        QPluginLoader ldr(pluginsDir.absoluteFilePath(p),this);
        QObject* plugin = ldr.instance();
        if (plugin) {
                ::Plugins::Plugin* pp = qobject_cast<::Plugins::Plugin *>(plugin);
                if (pp)
                {
                    qDebug() << "Loaded Plugin " << p;
                    p_clip->addOptions(pp->getCLIoptions());
                }
        ldr.unload();
        }
        }

        //XXX: Invoke LSYS plugin manually for now
        QString pname(::Plugins::Plugin_Registry::getInstance()->getPlugin(QStringLiteral("importLSYS")));

        QPluginLoader ldr(pluginsDir.absoluteFilePath(pname),this);
        QObject* plugin = ldr.instance();
        if (plugin) {
                ::Plugins::Import* importer = qobject_cast<::Plugins::Import *>(plugin);
                if (importer)
                {

                    post_status("Running Import plugin");
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
