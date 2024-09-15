#include "enginemedia.h"

EngineMedia::EngineMedia(QObject *parent) : QObject(parent) {
    qInfo("Initialize media");

    //Get list media
    listMedia.append("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/Intro_Outro_Music.mp3");
    listMedia.append("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/24H.mp3");
    listMedia.append("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/Dung_Lam_Trai_Tim_Anh_Dau.mp3");
    listMedia.append("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/Exit_sign.mp3");
    listMedia.append("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/Khong_the_say_HieuT2.mp3");
    listMedia.append("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/Thu_toi_Dat_G.mp3");


    //Initialize Media
    M_Player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    M_Player->setAudioOutput(audioOutput);

    //Xam` LOZZZZ
    // QUrl url = QUrl("qrc:/Music/24H.mp3");
    // M_Player->setSource(QUrl(url));

    M_Player->setSource(QUrl::fromLocalFile((listMedia[currentIndex])));
    audioOutput->setVolume(1);

    //Connect slot,signal
    connect(this, &EngineMedia::play, this, &EngineMedia::on_pushButton_Play_clicked);
    connect(this, &EngineMedia::pause, this, &EngineMedia::on_pushButton_Pause_clicked);
    connect(this, &EngineMedia::next, this, &EngineMedia::on_pushButton_Next_clicked);
    connect(this, &EngineMedia::previous, this, &EngineMedia::on_pushButton_Previous_clicked);
    // connect(this, &EngineMedia::shuffer, this, &EngineMedia::on_pushButton_Shuffer_clicked);


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
