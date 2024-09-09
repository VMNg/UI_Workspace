#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Media/enginemedia.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/PBL/Main.qml"_qs);
    qmlRegisterType<EngineMedia>("PlayerControl", 1, 0, "MediaControl");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
