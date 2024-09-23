#ifndef RENDERVIDEO_H
#define RENDERVIDEO_H

#include <QQuickPaintedItem>
#include <QMediaPlayer>
#include <QVideoSink>
#include <QPainter>
#include <QVideoFrame>
#include "FunctionModel.h"

class RenderVideo : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(FunctionModel* funcModel READ funcModel WRITE setFuncModel NOTIFY funcModelChanged)
public:
    RenderVideo(QQuickItem *parent = nullptr);
    FunctionModel* funcModel();
    void setFuncModel(FunctionModel* engine);
signals:
    void funcModelChanged();
protected:
    void paint(QPainter *painter) override;
private slots:
    void onFrameChanged(const QVideoFrame &frame);
private:
    QImage currentFrame;
    FunctionModel *m_funcModel = nullptr;
};

#endif // RENDERVIDEO_H
