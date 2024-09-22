#ifndef RENDERVIDEO_H
#define RENDERVIDEO_H

#include <QQuickPaintedItem>
#include <QMediaPlayer>
#include <QVideoSink>
#include <QPainter>
#include <QVideoFrame>
#include <Media/EngineMedia.h>

class RenderVideo : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(EngineMedia* mediaEngine READ mediaEngine WRITE setMediaEngine NOTIFY mediaEngineChanged)

public:
    RenderVideo(QQuickItem *parent = nullptr) : QQuickPaintedItem(parent) {
        setFlag(ItemHasContents, true);
    }

    EngineMedia* mediaEngine() const {
        return m_mediaEngine;
    }

    void setMediaEngine(EngineMedia* engine) {
        if (m_mediaEngine != engine) {
            m_mediaEngine = engine;
            emit mediaEngineChanged();
            connect(m_mediaEngine, &EngineMedia::EngineFrameChanged, this, &RenderVideo::onFrameChanged);
        }
    }

signals:
    void mediaEngineChanged();

protected:
    void paint(QPainter *painter) override {
        if (!currentFrame.isNull()) {
            painter->drawImage(boundingRect(), currentFrame);
        }
    }

private slots:
    void onFrameChanged(const QVideoFrame &frame) {
        currentFrame = frame.toImage();
        update();
    }

private:
    QImage currentFrame;
    EngineMedia *m_mediaEngine = nullptr;
};

#endif // RENDERVIDEO_H
