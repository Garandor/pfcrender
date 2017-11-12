#include <memory>

#include <QDebug>
#include <QDir>
#include <QGuiApplication>
#include <QPluginLoader>
#include <QQmlApplicationEngine>
#include <QQuickItem>

#include "PFCRender.h"
#include "Plugins/Import.h"
#include "Plugins/Plugin_Registry.h"
#include "ViewModel/CustomGeometryModel.h"
#include "ViewModel/ViewModelBuilder.h"

#include "CLI/CLIParser.h"

namespace QtGUI {

void PFCRender::onModelChanged(const QString& mdl)
{
    auto* mdlItem = qobject_cast<ViewModel::CustomGeometryModel*>(p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("model")));
    if (mdlItem) {
        mdlItem->setGeometryNode(ViewModel::createGeom(mdl));
    }
}

void PFCRender::post_status(const QString& what)
{
    p_eng->rootObjects()[0]->findChild<QQuickItem*>(QStringLiteral("status"))->setProperty("text", what);
}

PFCRender::PFCRender(QQmlApplicationEngine* eng)
    : p_eng(eng)
{
    //Load plugin from registry
    QDir pluginsDir(qApp->applicationDirPath());
    pluginsDir.cd("../plugins"); //XXX : THIS WILL BREAK ON DEPLOYMENT

    //get CLI options
    ::CLI::CLIParser* p_clip = ::CLI::CLIParser::getInstance();

    //Iterate through all registered plugins, load them, get their info (XXX: inefficient)
    for (const QString& p : Plugins::Plugin_Registry::getInstance()->getRegistry().values()) {
        QPluginLoader ldr(pluginsDir.absoluteFilePath(p), this);
        QObject* plugin = ldr.instance();
        if (plugin) {
            ::Plugins::Plugin* pp = qobject_cast<::Plugins::Plugin*>(plugin);
            if (pp) {
                qDebug() << "Loaded Plugin " << p;
                p_clip->addOptions(pp->getCLIoptions(), p);
            }
            ldr.unload();
        }
    }

    //Parse CLI and invoke operations
    p_clip->parse();

    //TODO: Find how to set a priority / sequence for operation execution (mb have plugins define prerequisites?)
    //Execute built-in commands

    //Execute plugins
    //BUG: key is in registry twice, idk why
    //if any cmdline args of a plugin have been set, call its corresponding plugin once
    for (const QString& pname : p_clip->getRegistry().keys()) {
        for (const QCommandLineOption& opt : p_clip->getRegistry().values(pname)) {
            if (p_clip->getParser().isSet(opt)) {
                //TODO: Architecture still not complete, how to handle different plugin types? Import/Export/Modify
                QPluginLoader ldr(pluginsDir.absoluteFilePath(pname), this);
                QObject* plugin = ldr.instance();
                if (plugin) {
                    ::Plugins::Import* importer = qobject_cast<::Plugins::Import*>(plugin);
                    if (importer) {

                        post_status(QString("Running plugin ").append(pname));
                        auto dataModel = importer->getModel(p_clip->getParser());

                        QObject::connect(&m_dMdl, SIGNAL(modelChanged(const QString&)), this, SLOT(onModelChanged(const QString&)));

                        m_dMdl.setModel(std::move(dataModel));
                    }
                    ldr.unload();
                } else {
                    qWarning() << "Plugin Load failed with :" << ldr.errorString();
                }

                break; //move to next key
            }
        }
    }
}

} // namespace QtGUI
