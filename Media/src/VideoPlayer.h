// #ifndef VIDEOPLAYER_H
// #define VIDEOPLAYER_H

// #include <QQuickPaintedItem>
// #include <QMediaPlayer>
// #include <QVideoSink>
// #include <QPainter>
// #include <QVideoFrame>

// class VideoPlayer : public QQuickPaintedItem {
//     Q_OBJECT
//     Q_DISABLE_COPY(VideoPlayer)

// public:
//     VideoPlayer(QMediaPlayer *mediaPlayer = nullptr, QQuickItem *parent = nullptr)
//         : QQuickPaintedItem(parent), mp(mediaPlayer ? mediaPlayer : new QMediaPlayer()),
//         videoSink(new QVideoSink(this)) {

//         qWarning() << "create QMediaPlayer:" << mp;
//         qWarning() << "create Sink:" << videoSink;

//         // Kết nối videoSink với mediaPlayer
//         mp->setVideoOutput(videoSink);

//         // Kết nối signal khi có frame mới
//         connect(videoSink, &QVideoSink::videoFrameChanged, this, &VideoPlayer::onFrameChanged);
//     }

//     Q_INVOKABLE void loadVideo(const QString &filePath) {
//         qWarning() << "load Video" << mp;
//         mp->setSource(QUrl::fromLocalFile(filePath));
//         mp->play();
//         qWarning() << "Played";
//     }

// protected:
//     void paint(QPainter *painter) override {
//         if (!currentFrame.isNull()) {
//             painter->drawImage(boundingRect(), currentFrame);
//         }
//     }

// private slots:
//     void onFrameChanged(const QVideoFrame &frame) {
//         qWarning() << "updateFrame";
//         currentFrame = frame.toImage();
//         update();
//     }

// private:
//     QMediaPlayer *mp;
//     QVideoSink *videoSink;
//     QImage currentFrame;
// };


// #endif // VIDEOPLAYER_H

#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QQuickPaintedItem>
#include <QMediaPlayer>
#include <QVideoSink>
#include <QPainter>
#include <QVideoFrame>

class VideoPlayer : public QQuickPaintedItem {
    Q_OBJECT
    Q_DISABLE_COPY(VideoPlayer)

public:
    static VideoPlayer* instance() {
        static VideoPlayer instance; // Đối tượng duy nhất
        return &instance;
    }

    // Constructor
    VideoPlayer(QMediaPlayer *mediaPlayer = nullptr, QQuickItem *parent = nullptr)
        : QQuickPaintedItem(parent), mp(mediaPlayer ? mediaPlayer : new QMediaPlayer()),
        videoSink(new QVideoSink(this)) {

        qWarning() << "create QMediaPlayer:" << mp;
        qWarning() << "create Sink:" << videoSink;

        mp->setVideoOutput(videoSink);
        connect(videoSink, &QVideoSink::videoFrameChanged, this, &VideoPlayer::onFrameChanged);
    }

    Q_INVOKABLE void loadVideo(const QString &filePath) {
        qWarning() << "load Video" << mp;
        mp->setSource(QUrl::fromLocalFile(filePath));
        mp->play();
        qWarning() << "Played";
    }

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
    QMediaPlayer *mp;
    QVideoSink *videoSink;
    QImage currentFrame;
};

#endif // VIDEOPLAYER_H

