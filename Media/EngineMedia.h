#ifndef ENGINEMEDIA_H
#define ENGINEMEDIA_H

#include <QObject>
#include <QtMultimedia>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QStringList>
#include <QList>
#include <QString>
#include <QVideoWidget>
#include <QVideoSink>
#include <QPainter>
#include <QVideoFrame>
#include <QQuickPaintedItem>

#include <random>
#include <iostream>
#include <iomanip>
#include <sstream>

// #include "Media/src/VideoPlayer.h"

using namespace std;

class EngineMedia : public QQuickPaintedItem
{
    Q_OBJECT
    Q_DISABLE_COPY(EngineMedia)
    Q_PROPERTY(bool shuffle READ shuffle WRITE setShuffle NOTIFY shuffleChanged FINAL)
    Q_PROPERTY(QString currentPosition READ currentPosition WRITE setCurrentPosition NOTIFY currentPositionChanged FINAL)
    Q_PROPERTY(QString duration_Media READ duration_Media WRITE setDuration_Media NOTIFY duration_MediaChanged FINAL)
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged FINAL)
public:
    explicit EngineMedia(QQuickPaintedItem *parent = nullptr);
    ~EngineMedia();
    uint shuffle_list(uint begin, uint end);
    void play_media(uint index, QList<QString> listModel);
    bool shuffle() const;
    void handle_suffleMedia();
    void addSong(const QStringList& listSongs, QList<QString>& list, QString urlPath);
    void initialize();
    void setCurrentPosition(const QString &newCurrentPosition);
    QString currentPosition() const;
    QString convertTime(qint64 position);
    QString duration_Media() const;
    void setDuration_Media(const QString &newDuration_Media);
    bool running() const;
    void setRunning(bool newRunning);

signals:
    void play();
    void pause();
    void next();
    void previous();
    void shuffer();
    void shuffleChanged();
    void currentPositionChanged();
    void duration_MediaChanged();
    void updateSlider();
    void updateDuration();
    void runningChanged();

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
    void playAtIndex(uint index);
    void setPosition(qreal position);
    void setVolume(float volume);
    void setPlayBackMedia(qreal rate);
    void setTypeMedia(bool type);
    uint64_t getDurationForSlider();
    uint64_t getPositionForSlider();
protected:
    void paint(QPainter *painter) override {
        if (!currentFrame.isNull()) {
            painter->drawImage(boundingRect(), currentFrame);
        }
    }
private slots:
    void onFrameChanged(const QVideoFrame &frame) {
        qWarning() << "updateFrame";
        currentFrame = frame.toImage();
        update();
    }

private:
    QImage currentFrame;
    QVideoSink *videoSink;
    QMediaPlayer *M_Player;
    QAudioOutput *audioOutput;
    // VideoPlayer *videoPlayer;
    QList<QString> listMedia;
    QList<QString> listVideo;
    uint currentIndex{0U};
    const QString urlSong = "/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Music/";
    const QString urlVideo = "/home/fr/Documents/workspace/UI_Workspace/UI_Workspace/Media/Video/";
    bool m_shuffle;
    QString m_currentPosition = "NA::NA";
    QString m_duration_Media = "NA::NA";
    uint64_t duration_slider = 0;
    uint64_t position_slider = 0;
    bool m_running = false;
    bool typeSong = true;
};

#endif // ENGINEMEDIA_H
