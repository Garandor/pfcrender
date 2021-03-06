#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>

#include "Common/Config_Registry.h"
#include "Common/Plugin_Registry.h"

#include "QtCLI/PFCRenderCLI.h"
#include "QtGUI/PFCRenderGUI.h"
#include "QtGUI/QNanoPaintedCurve.h"

#include "projectinfo.h"

/**
 * @brief main program entry point
 * @param argc system argument count
 * @param argv system argument value array
 * @return 0 on success, non-zero on failure
 *
 * This methods sets up the Qt runtime environment and executes the application.
 * If batchmode was selected, run and exit, otherwise starts to GUI
 **/
int main(int argc, char** argv)
{
//Force Qt to use OpenGLESv2 / ANGLE on windows so we can use QNanoPainter
//Must be set before QGuiApplication
//http://doc.qt.io/qt-5/windows-requirements.html
#if defined(WIN32)
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
#endif

    QGuiApplication app(argc, argv);
    auto cr = Common::Config_Registry::getInstance(); //Note: cr uses plugin_registry so it is implicitly created
    app.setApplicationVersion(VERSION_STRING); //Set Version Information

    Model::LSYSModelImpl mdl;
    if (cr->getOpt("Main.Batch").compare("N/A")) {
        QtCLI::PFCRenderCLI desktop_obj(mdl);
    } else {

        //Register custom QML Types
        qmlRegisterType<QtGUI::QNanoPaintedCurve>("sci.pfcrender.qnanorenderedcurve", 1, 0, "QNanoRenderedCurve");

        QQmlApplicationEngine qeng(QUrl(QStringLiteral("qrc:///main.qml")));
        QtGUI::PFCRenderGUI desktop_obj(&qeng, mdl);

        return app.exec();
    }
}
