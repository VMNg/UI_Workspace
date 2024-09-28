

#include <QApplication>
#include <QQmlApplicationEngine>


#include <QtAppManCommon/logging.h>
#include <QtAppManLauncher/launchermain.h>
#include <QtAppManLauncher/dbusapplicationinterface.h>
#include <QtAppManLauncher/dbusnotification.h>
#include "FunctionModel.h"
#include "FunctionModelInterface.h"
#include "RenderVideo.h"
#include <QQmlContext>


int main(int argc, char *argv[])
{
    // QtAM::Logging::initialize(argc, argv);
    // QtAM::Logging::setApplicationId("media");

    // QtAM::LauncherMain::initialize();
    QGuiApplication app(argc, argv);
    // QtAM::LauncherMain launcher;

    // launcher.registerWaylandExtensions();
    // launcher.loadConfiguration();
    // launcher.setupLogging(false, launcher.loggingRules(), QString(), launcher.useAMConsoleLogger());
    // launcher.setupDBusConnections();

    QQmlApplicationEngine engine;
    qmlRegisterSingletonInstance<FunctionModel>("MDA.Models",1,0,"FunctionModel",FunctionModel::initialize(&engine));
    qmlRegisterType<RenderVideo>("RenderVideo", 1, 0, "VideoRender");
    FunctionModelInterface functionModelInterface(&engine);
    engine.rootContext()->setContextProperty("functionModelInterface", &functionModelInterface);
    const QUrl url(QStringLiteral("qrc:/media/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);
    //Application interface for handling quit
    // QtAM::DBusApplicationInterface iface(launcher.p2pDBusName(), launcher.notificationDBusName());
    // iface.initialize();
    // QObject::connect(&iface, &QtAM::DBusApplicationInterface::quit, [&iface] () {
    //     iface.acknowledgeQuit();
    // });


    return app.exec();
}
