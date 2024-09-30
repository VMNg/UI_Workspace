#include "FunctionModel.h"
#include <QDBusConnection>
#include <QDBusInterface>

FunctionModel::FunctionModel(QObject *parent)
    : QObject{parent}
{
    m_listSongController = new SongListController();
    m_listVideoController = new VideoListController();
    QString appDir = QCoreApplication::applicationDirPath();
    QString baseDir = QDir(appDir).filePath("../../../..");
    QDir dirSong(baseDir+"/native/media/Music/");
    QDir dirVideo(baseDir+"/native/media/Video/");
    QStringList listSongs = dirSong.entryList(QStringList()<<"*.mp3"<<"*.MP3",QDir::Files);
    QStringList listVideos = dirVideo.entryList(QStringList()<<"*.mp4"<<"*.MP4",QDir::Files);
    addSong(listSongs, listMedia, urlSong);
    addSong(listVideos, listVideo, urlVideo);
    initialize();
}

FunctionModel::~FunctionModel()
{
    if(M_Player != nullptr){
        delete M_Player;
        M_Player = nullptr;
    }
    if(audioOutput != nullptr){
        delete audioOutput;
        audioOutput = nullptr;
    }
}
static FunctionModel *g_singleton = nullptr;
FunctionModel *FunctionModel::initialize(QObject *parent)
{
    if(g_singleton == nullptr){
        g_singleton = new FunctionModel(parent);
    }
    return g_singleton;
}

FunctionModel &FunctionModel::getInstance()
{
    if(g_singleton == nullptr)
    {
        // In ra log loi
    }
    return *g_singleton;
}

SongListController *FunctionModel::listSongController() const
{
    return m_listSongController;
}

void FunctionModel::setListSongController(SongListController* newListSongController)
{
    if (m_listSongController == newListSongController)
        return;
    m_listSongController = newListSongController;
    emit listSongControllerChanged();
}

VideoListController *FunctionModel::listVideoController() const
{
    return m_listVideoController;
}

void FunctionModel::setListVideoController(VideoListController* newListVideoController)
{
    if (m_listVideoController == newListVideoController)
        return;
    m_listVideoController = newListVideoController;
    emit listVideoControllerChanged();
}
uint FunctionModel::shuffle_list(uint begin, uint end)
{
    // Define range
    int min = begin;
    int max = end;

    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // Generate random number in the range [min, max]
    uint randomValue = distrib(gen);
    return randomValue;
}

void FunctionModel::play_media(uint index, QList<QString> listModel)
{
    if(typeSong == true){
        setRunning(true);
        M_Player->setSource(QUrl::fromLocalFile((listModel[index])));
        M_Player->play();
        FunctionModel::setstart(true);
    } else{
        setRunning(false);
        M_Player->setSource(QUrl::fromLocalFile((listModel[index])));
        M_Player->play();
        FunctionModel::setstart(true);
    }
}

void FunctionModel::handle_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::MediaStatus::EndOfMedia){
        if(m_shuffle == true){
            handle_suffleMedia();
        } else{
            on_pushButton_Next_clicked();
        }
    }
}

void FunctionModel::on_pushButton_Play_clicked()
{
    M_Player->play();
    if(typeSong == true){
        setRunning(true);
    }
    FunctionModel::setstart(true);
}

void FunctionModel::on_pushButton_Pause_clicked()
{
    M_Player->pause();
    if(typeSong == true){
        setRunning(false);
    }
    FunctionModel::setstart(false);
}

void FunctionModel::on_pushButton_Next_clicked()
{
    if(typeSong == true){
        if(currentIndex < listMedia.size() - 1){
            currentIndex += 1U;
        } else {
            currentIndex = 0U;
        }
        play_media(currentIndex, listMedia);
    } else{
        if(currentIndex < listVideo.size() - 1){
            currentIndex += 1U;
        } else {
            currentIndex = 0U;
        }
        play_media(currentIndex, listVideo);
    }
    emit nextMedia();
}

void FunctionModel::on_pushButton_Previous_clicked()
{
    if(typeSong == true){
        if(currentIndex > 0){
            currentIndex -= 1U;
        } else {
            currentIndex = listMedia.size() - 1;
        }
        play_media(currentIndex, listMedia);
    } else{
        if(currentIndex > 0){
            currentIndex -= 1U;
        } else {
            currentIndex = listVideo.size() - 1;
        }
        play_media(currentIndex, listVideo);
    }
    emit previousMedia();
}

void FunctionModel::playClicked()
{
    emit play();
}

void FunctionModel::pauseClicked()
{
    emit pause();
}

void FunctionModel::nextClicked()
{
    emit next();
}

void FunctionModel::previousClicked()
{
    emit previous();
}

void FunctionModel::shufferClicked()
{
    emit shuffer();
}


bool FunctionModel::shuffle() const
{
    return m_shuffle;
}

void FunctionModel::setShuffle(bool newShuffle)
{
    if (m_shuffle == newShuffle)
        return;
    m_shuffle = newShuffle;
    emit shuffleChanged();
}

void FunctionModel::handle_suffleMedia()
{
    uint random_idx;
    if(typeSong == true){
        do {
            (random_idx = shuffle_list(0, (listMedia.size() - 1)));
        } while(random_idx == currentIndex);
        play_media(random_idx, listMedia);
    } else{
        do {
            (random_idx = shuffle_list(0, (listVideo.size() - 1)));
        } while(random_idx == currentIndex);
        play_media(random_idx, listVideo);
    }
}

void FunctionModel::addSong(const QStringList& listSongs, QList<QString>& list, QString urlPath)
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString baseDir = QDir(appDir).filePath("../../../..");
    foreach (QString filename, listSongs) {
        list.append(baseDir + urlPath + filename);
        if(list == listMedia){
            m_listSongController->addSong(filename);
        }
        else{
            m_listVideoController->addVideo(filename);
        }
    }
}

void FunctionModel::initialize()
{
    M_Player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    videoSink = new QVideoSink();
    M_Player->setVideoOutput(videoSink);
    M_Player->setAudioOutput(audioOutput);
    M_Player->setSource(QUrl::fromLocalFile((listMedia[currentIndex])));
    audioOutput->setVolume(0.5);

    //Connect slot,signal
    connect(videoSink, &QVideoSink::videoFrameChanged, this, &FunctionModel::EngineFrameChanged);
    connect(this, &FunctionModel::play, this, &FunctionModel::on_pushButton_Play_clicked);
    connect(this, &FunctionModel::pause, this, &FunctionModel::on_pushButton_Pause_clicked);
    connect(this, &FunctionModel::next, this, &FunctionModel::on_pushButton_Next_clicked);
    connect(this, &FunctionModel::previous, this, &FunctionModel::on_pushButton_Previous_clicked);
    connect(M_Player, &QMediaPlayer::mediaStatusChanged, this,  &FunctionModel::handle_mediaStatusChanged);
    connect(M_Player, &QMediaPlayer::positionChanged, this, [&](qint64 position){
        position_slider = position;
        QString current_position = convertTime(position);
        FunctionModel::setCurrentPosition(current_position);
    });
    connect(M_Player, &QMediaPlayer::durationChanged, this, [&](qint64 dur) {
        duration_slider = dur;
        setDuration_Media(convertTime(dur));
    });
    // connect(this, &FunctionModel::shuffer, this, &FunctionModel::on_pushButton_Shuffer_clicked);
}

void FunctionModel::playAtIndex(uint index)
{
    currentIndex = index;
    if(typeSong == true){
        if((index < 0) ||  (index > (listMedia.size() -1))){
            return;
        } else{
            play_media(index, listMedia);
        }
    }else{
        if((index < 0) ||  (index > (listVideo.size() -1))){
            return;
        } else{
            play_media(index, listVideo);
        }
    }
}

uint64_t FunctionModel::getDurationForSlider()
{
    return duration_slider;
}

uint64_t FunctionModel::getPositionForSlider()
{
    return position_slider;
}

void FunctionModel::setPosition(qreal position)
{
    M_Player->setPosition(position);
}

void FunctionModel::setVolume(float volume)
{
    audioOutput->setVolume(volume);
}

void FunctionModel::setPlayBackMedia(qreal rate)
{
    M_Player->setPlaybackRate(rate);
}

void FunctionModel::setTypeMedia(bool type)
{
    typeSong = type;
    qWarning() << "changed Type: " << type;
}

QString FunctionModel::currentPosition() const
{
    return m_currentPosition;
}

QString FunctionModel::duration_Media() const
{
    return m_duration_Media;
}

QString FunctionModel::convertTime(qint64 position)
{
    long seconds = position / 1000;
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    std::string tmp_time = std::string((minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" +
                                       (remainingSeconds < 10 ? "0" : "") + std::to_string(remainingSeconds));
    QString time_had_convert = QString::fromStdString(tmp_time);
    return time_had_convert;
}

void FunctionModel::setCurrentPosition(const QString &newCurrentPosition)
{
    if (m_currentPosition == newCurrentPosition)
        return;
    m_currentPosition = newCurrentPosition;
    emit updateSlider();
    emit currentPositionChanged();
}


void FunctionModel::setDuration_Media(const QString &newDuration_Media)
{
    if (m_duration_Media == newDuration_Media)
        return;
    m_duration_Media = newDuration_Media;
    emit updateDuration();
    emit duration_MediaChanged();
}

bool FunctionModel::running() const
{
    return m_running;
}

void FunctionModel::setRunning(bool newRunning)
{
    if (m_running == newRunning)
        return;
    m_running = newRunning;
    emit runningChanged();
}

bool FunctionModel::start() const
{
    return m_start;
}

void FunctionModel::setstart(bool newStart)
{
    if (m_start == newStart)
        return;
    m_start = newStart;
    emit startChanged();
}

void FunctionModel::initialize_Debug()
{
    QObject::connect(M_Player, &QMediaPlayer::errorOccurred, [](QMediaPlayer::Error error){
        qDebug() << "Media Player Error:" << error;
    });
    QObject::connect(M_Player, &QMediaPlayer::mediaStatusChanged,
                     [](QMediaPlayer::MediaStatus status){
                         qDebug() << "Media Player Status:" << status;
                     });
}
