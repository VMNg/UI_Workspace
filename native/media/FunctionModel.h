#ifndef FUNCTIONMODEL_H
#define FUNCTIONMODEL_H

#include <QObject>
#include <QtMultimedia>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QStringList>
#include <QList>
#include <QString>
#include <QVideoSink>
#include <QPainter>
#include <QVideoFrame>
#include <QQuickPaintedItem>
#include <random>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#include "SongListController.h"
#include "VideoListController.h"

class FunctionModel : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    Q_PROPERTY(SongListController* listSongController READ listSongController WRITE setListSongController NOTIFY listSongControllerChanged)
    Q_PROPERTY(VideoListController* listVideoController READ listVideoController WRITE setListVideoController NOTIFY listVideoControllerChanged)
    Q_PROPERTY(bool shuffle READ shuffle WRITE setShuffle NOTIFY shuffleChanged FINAL)
    Q_PROPERTY(QString currentPosition READ currentPosition WRITE setCurrentPosition NOTIFY currentPositionChanged FINAL)
    Q_PROPERTY(QString duration_Media READ duration_Media WRITE setDuration_Media NOTIFY duration_MediaChanged FINAL)
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged FINAL)
    Q_PROPERTY(bool start READ start WRITE setstart NOTIFY startChanged FINAL)
public:
    // Singleton pattern
    static FunctionModel* initialize(QObject *parent);
    static FunctionModel& getInstance();
    FunctionModel(const FunctionModel&) = delete;
    FunctionModel& operator=(const FunctionModel&) = delete;

    SongListController* listSongController() const;
    void setListSongController(SongListController* newListSongController);
    VideoListController* listVideoController() const;
    void setListVideoController(VideoListController* newListVideoController);

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
    bool start() const;
    void setstart(bool newStart);
    void initialize_Debug();
signals:
    void listSongControllerChanged();
    void listVideoControllerChanged();
    void EngineFrameChanged(const QVideoFrame &frame);
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
    void nextMedia();
    void previousMedia();
    void startChanged();
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
    explicit FunctionModel(QObject *parent = nullptr);
    ~FunctionModel();
private:
    SongListController* m_listSongController = nullptr;
    VideoListController* m_listVideoController = nullptr;
    QImage currentFrame;
    QVideoSink *videoSink;
    QMediaPlayer *M_Player;
    QAudioOutput *audioOutput;
    QList<QString> listMedia;
    QList<QString> listVideo;
    uint currentIndex{0U};
    const QString urlSong = "/native/media/Music/";
    const QString urlVideo = "/native/media/Video/";
    bool m_shuffle;
    QString m_currentPosition = "NA::NA";
    QString m_duration_Media = "NA::NA";
    uint64_t duration_slider = 0;
    uint64_t position_slider = 0;
    bool m_running = false;
    bool typeSong = true;
    bool m_start = false;
};

#endif // FUNCTIONMODEL_H
