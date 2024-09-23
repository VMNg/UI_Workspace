#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "Media/EngineMedia.h"
#include "Media/src/SongListController.h"
#include "Media/src/VideoListController.h"
#include "Media/src/RenderVideo.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    EngineMedia m_media;
    return app.exec();
}
