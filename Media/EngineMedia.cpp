#include "Media/EngineMedia.h"
#include "src/FunctionModel.h"
#include "src/RenderVideo.h"

EngineMedia::EngineMedia(QObject *parent) : QObject(parent), m_qmlEngine(this){
    qmlRegisterSingletonInstance<FunctionModel>("MDA.Models",1,0,"FunctionModel",FunctionModel::initialize(this));
    // FunctionModel::getInstance().m_listSongController = new SongListController();
    // FunctionModel::getInstance().m_listVideoController = new VideoListController();
    // QDir dirSong("/home/fr/Moc_project/UI_Workspace/Media/Music/");
    // QDir dirVideo("/home/fr/Moc_project/UI_Workspace/Media/Video/");
    // QStringList listSongs = dirSong.entryList(QStringList()<<"*.mp3"<<"*.MP3",QDir::Files);
    // QStringList listVideos = dirVideo.entryList(QStringList()<<"*.mp4"<<"*.MP4",QDir::Files);
    // FunctionModel::getInstance().addSong(listSongs, listMedia, urlSong);
    // FunctionModel::getInstance().addSong(listVideos, listVideo, urlVideo);
    // FunctionModel::getInstance().initialize();
    qmlRegisterType<RenderVideo>("RenderVideo", 1, 0, "VideoRender");
    m_qmlEngine.load(u"qrc:/PBL/Main.qml"_qs);
}

EngineMedia::~EngineMedia()
{

}
