#include "EngineMedia.h"

EngineMedia::EngineMedia(QObject *parent) : QObject(parent) {
    qInfo("Initialize media");

    //Get list songs
    QDir dirSong("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music");
    QStringList listSongs = dirSong.entryList(QStringList()<<"*.mp3"<<"*.MP3",QDir::Files);
    EngineMedia::addSong(listSongs);
    EngineMedia::initialize();
    //Debug error
    QObject::connect(M_Player, &QMediaPlayer::errorOccurred, [](QMediaPlayer::Error error){
        qDebug() << "Media Player Error:" << error;
    });
    QObject::connect(M_Player, &QMediaPlayer::mediaStatusChanged,
                     [](QMediaPlayer::MediaStatus status){
                         qDebug() << "Media Player Status:" << status;
                     });
    QObject::connect(M_Player, &QMediaPlayer::mediaStatusChanged,
                     this,  &EngineMedia::handle_mediaStatusChanged);
}

EngineMedia::~EngineMedia()
{
    qInfo("Destroy media");
    if(M_Player != nullptr){
        delete M_Player;
        M_Player = nullptr;
    }
    if(audioOutput != nullptr){
        delete audioOutput;
        audioOutput = nullptr;
    }
}

uint EngineMedia::shuffle_list(uint begin, uint end)
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

void EngineMedia::play_media(uint index, QList<QString> listModel)
{
    M_Player->setSource(QUrl::fromLocalFile((listModel[index])));
    M_Player->play();
}

void EngineMedia::handle_mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::MediaStatus::EndOfMedia){
        if(m_shuffle == true){
            handle_suffleMedia();
        } else{
            on_pushButton_Next_clicked();
        }
    }
}

void EngineMedia::on_pushButton_Play_clicked()
{
    M_Player->play();
}

void EngineMedia::on_pushButton_Pause_clicked()
{
    M_Player->pause();
}

void EngineMedia::on_pushButton_Next_clicked()
{
    if(currentIndex < listMedia.size() - 1){
        currentIndex += 1U;
    } else {
        currentIndex = 0U;
    }
    play_media(currentIndex, listMedia);
}

void EngineMedia::on_pushButton_Previous_clicked()
{
    if(currentIndex > 0){
        currentIndex -= 1U;
    } else {
        currentIndex = listMedia.size() - 1;
    }
    play_media(currentIndex, listMedia);
}

void EngineMedia::playClicked()
{
    emit play();
}

void EngineMedia::pauseClicked()
{
    emit pause();
}

void EngineMedia::nextClicked()
{
    emit next();
}

void EngineMedia::previousClicked()
{
    emit previous();
}

void EngineMedia::shufferClicked()
{
    emit shuffer();
}


bool EngineMedia::shuffle() const
{
    return m_shuffle;
}

void EngineMedia::setShuffle(bool newShuffle)
{
    if (m_shuffle == newShuffle)
        return;
    m_shuffle = newShuffle;
    emit shuffleChanged();
}

void EngineMedia::handle_suffleMedia()
{
    uint random_idx;
    do {
        (random_idx = shuffle_list(0, (listMedia.size() - 1)));
    } while(random_idx == currentIndex);
    play_media(random_idx, listMedia);
}

void EngineMedia::addSong(const QStringList& listSongs)
{
    foreach (QString filename, listSongs) {
        listMedia.append(urlSong + filename);
    }
}

void EngineMedia::initialize()
{
    M_Player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    M_Player->setAudioOutput(audioOutput);
    M_Player->setSource(QUrl::fromLocalFile((listMedia[currentIndex])));
    audioOutput->setVolume(1);

    //Connect slot,signal
    connect(this, &EngineMedia::play, this, &EngineMedia::on_pushButton_Play_clicked);
    connect(this, &EngineMedia::pause, this, &EngineMedia::on_pushButton_Pause_clicked);
    connect(this, &EngineMedia::next, this, &EngineMedia::on_pushButton_Next_clicked);
    connect(this, &EngineMedia::previous, this, &EngineMedia::on_pushButton_Previous_clicked);
    connect(M_Player, &QMediaPlayer::positionChanged, this, [&](qint64 position){
        position_slider = position;
        QString current_position = convertTime(position);
        EngineMedia::setCurrentPosition(current_position);
    });
    connect(M_Player, &QMediaPlayer::durationChanged, this, [&](qint64 dur) {
        duration_slider = dur;
        setDuration_Media(convertTime(dur));
    });
    // connect(this, &EngineMedia::shuffer, this, &EngineMedia::on_pushButton_Shuffer_clicked);
}

void EngineMedia::playAtIndex(uint index)
{
    if((index < 0) ||  (index > (listMedia.size() -1))){
        return;
    } else{
        play_media(index, listMedia);
    }
}

uint64_t EngineMedia::getDurationForSlider()
{
    return duration_slider;
}

uint64_t EngineMedia::getPositionForSlider()
{
    return position_slider;
}

void EngineMedia::setPosition(qreal position)
{
    M_Player->setPosition(position);
}

QString EngineMedia::convertTime(qint64 position)
{
    long seconds = position / 1000;
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    std::string tmp_time = std::string((minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" +
                           (remainingSeconds < 10 ? "0" : "") + std::to_string(remainingSeconds));
    QString time_had_convert = QString::fromStdString(tmp_time);
    return time_had_convert;
}

void EngineMedia::setCurrentPosition(const QString &newCurrentPosition)
{
    if (m_currentPosition == newCurrentPosition)
        return;
    m_currentPosition = newCurrentPosition;
    emit updateSlider();
    emit currentPositionChanged();
}


QString EngineMedia::currentPosition() const
{
    return m_currentPosition;
}

QString EngineMedia::duration_Media() const
{
    return m_duration_Media;
}

void EngineMedia::setDuration_Media(const QString &newDuration_Media)
{
    if (m_duration_Media == newDuration_Media)
        return;
    m_duration_Media = newDuration_Media;
    emit updateDuration();
    emit duration_MediaChanged();
}
