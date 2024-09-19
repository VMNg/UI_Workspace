#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QQuickPaintedItem>
#include <QMediaPlayer>
#include <QVideoSink>
#include <QPainter>
#include <QVideoFrame>

class VideoPlayer : public QQuickPaintedItem {
    Q_OBJECT

public:
    VideoPlayer(QMediaPlayer *mediaPlayer = nullptr, QQuickItem *parent = nullptr)
        : QQuickPaintedItem(parent), mp(mediaPlayer ? mediaPlayer : new QMediaPlayer()),
        videoSink(new QVideoSink(this)) {
        qWarning() << "Pointer2" << mp;
        qWarning() << "Sink" << videoSink;


        // Kết nối videoSink với mediaPlayer
        mp->setVideoOutput(videoSink);

        // Kết nối signal khi có frame mới
        connect(videoSink, &QVideoSink::videoFrameChanged, this, &VideoPlayer::onFrameChanged);
        qWarning() << "Step4";
    }

    Q_INVOKABLE void loadVideo(const QString &filePath) {
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
        currentFrame = frame.toImage();  // Lấy hình ảnh từ frame
        update();  // Yêu cầu repaint
    }

private:
    QMediaPlayer *mp;
    QVideoSink *videoSink;
    QImage currentFrame;
};


#endif // VIDEOPLAYER_H
