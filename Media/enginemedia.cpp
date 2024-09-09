#include "enginemedia.h"

EngineMedia::EngineMedia(QObject *parent) : QObject(parent) {
    qInfo("Initialize media");
    M_Player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    M_Player->setAudioOutput(audioOutput);
    const QUrl url = QUrl("qrc:/Music/24H.mp3");
    M_Player->setSource(url);
    // M_Player->setSource(QUrl::fromLocalFile(("/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/24H.mp3")));
    audioOutput->setVolume(1);
    QObject::connect(M_Player, &QMediaPlayer::errorOccurred, [](QMediaPlayer::Error error){
        qDebug() << "Media Player Error:" << error;
    });
    QObject::connect(M_Player, &QMediaPlayer::mediaStatusChanged,
            [](QMediaPlayer::MediaStatus status){
        qDebug() << "Media Player Status:" << status;
    });
    connect(this, &EngineMedia::play, this, &EngineMedia::on_pushButton_Play_clicked);
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

void EngineMedia::on_pushButton_Play_clicked()
{
    qWarning("BBBBBB");
    M_Player->play();
}

void EngineMedia::on_pushButton_Pause_clicked()
{
    M_Player->pause();
}

void EngineMedia::on_pushButton_Next_clicked()
{

}

void EngineMedia::on_pushButton_Previous_clicked()
{

}

void EngineMedia::on_pushButton_Shuffer_clicked()
{

}

void EngineMedia::playClicked()
{
    qWarning("AAAAA");
    emit play();
}

void EngineMedia::pauseClicked()
{

}

void EngineMedia::nextClicked()
{

}

void EngineMedia::previousClicked()
{

}

void EngineMedia::shufferClicked()
{

}


