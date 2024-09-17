#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Media/EngineMedia.h"
#include "Media/src/SongListController.h"
#include "Media/src/VideoListController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    EngineMedia m_media;

    QQmlApplicationEngine engine;

    //Load music, media to model
    SongListController pListSong;
    VideoListController pListVideo;
    const QUrl url(u"qrc:/PBL/Main.qml"_qs);
    QDir dirSong("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music");
    QDir dirVideo("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Video");
    QStringList listSongs=dirSong.entryList(QStringList()<<"*.mp3"<<"*.MP3",QDir::Files);
    QStringList listVideos=dirVideo.entryList(QStringList()<<"*.mp4"<<"*.MP4",QDir::Files);
    foreach (QString filename, listSongs) {
        pListSong.addSong(Song(filename));
    }
    foreach (QString filename, listVideos) {
        pListVideo.addVideo(Video(filename));
    }

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QQmlContext *context=engine.rootContext();

    context->setContextProperty("playerControl",&m_media);
    context->setContextProperty("playListSong",&pListSong);
    context->setContextProperty("playListVideo",&pListVideo);

    engine.load(url);
    return app.exec();
}
