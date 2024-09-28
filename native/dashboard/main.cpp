

#include <QApplication>
#include <QQmlApplicationEngine>


#include <QtAppManCommon/logging.h>
#include <QtAppManLauncher/launchermain.h>
#include <QtAppManLauncher/dbusapplicationinterface.h>
#include <QtAppManLauncher/dbusnotification.h>
#include "DashboardInterface.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "FunctionModelAdaptor.h"
#include "FunctionModelProvider.h"
#include "QQmlContext"


int main(int argc, char *argv[])
{
    // QtAM::Logging::initialize(argc, argv);
    // QtAM::Logging::setApplicationId("dashboard");
    // QtAM::LauncherMain::initialize();
    QGuiApplication app(argc, argv);
    // QtAM::LauncherMain launcher;

    // launcher.registerWaylandExtensions();
    // launcher.loadConfiguration();
    // launcher.setupLogging(false, launcher.loggingRules(), QString(), launcher.useAMConsoleLogger());
    // launcher.setupDBusConnections();

    QQmlApplicationEngine engine;
    DashboardInterface tempModel;
    QDBusConnection::sessionBus().registerService("com.example.climate.adapter");
    engine.rootContext()->setContextProperty("tempModel", &tempModel);
    FunctionModelProvider *funcProvider = new FunctionModelProvider(&engine);
    new FunctionModelAdaptor(funcProvider);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/ToanVV11", funcProvider);
    connection.registerService("com.toanvv.vn");
    engine.rootContext()->setContextProperty("funcProvider", funcProvider);
    const QUrl url(QStringLiteral("qrc:/dashboard/Main.qml"));
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
    // Application interface for handling quit
    // QtAM::DBusApplicationInterface iface(launcher.p2pDBusName(), launcher.notificationDBusName());
    // iface.initialize();
    // QObject::connect(&iface, &QtAM::DBusApplicationInterface::quit, [&iface] () {
    //     iface.acknowledgeQuit();
    // });



    return app.exec();
}
