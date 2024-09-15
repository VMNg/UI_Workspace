#ifndef ENGINEMEDIA_H
#define ENGINEMEDIA_H

#include <QObject>
#include <QtMultimedia>
#include <QDebug>
#include <QFile>
#include <random>
using namespace std;

class EngineMedia : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool shuffle READ shuffle WRITE setShuffle NOTIFY shuffleChanged FINAL)
public:
    explicit EngineMedia(QObject *parent = nullptr);
    ~EngineMedia();
    uint shuffle_list(uint begin, uint end);
    void play_media(uint index, QList<QString> listModel);
    bool shuffle() const;
    void handle_suffleMedia();

signals:
    void play();
    void pause();
    void next();
    void previous();
    void shuffer();
    void shuffleChanged();

private slots:
    void on_pushButton_Play_clicked();
    void on_pushButton_Pause_clicked();
    void on_pushButton_Next_clicked();
    void on_pushButton_Previous_clicked();

public slots:
    void setShuffle(bool newShuffle);
    void playClicked();
    void pauseClicked();
    void nextClicked();
    void previousClicked();
    void shufferClicked();
    void handle_mediaStatusChanged(QMediaPlayer::MediaStatus status);

private:
    QMediaPlayer *M_Player;
    QAudioOutput *audioOutput;
    QList<QString> listMedia;
    uint currentIndex{0U};
    bool m_shuffle;
};

#endif // ENGINEMEDIA_H
