#include "RenderVideo.h"

RenderVideo::RenderVideo(QQuickItem *parent) : QQuickPaintedItem(parent) {
    setFlag(ItemHasContents, true);
}
FunctionModel* RenderVideo::funcModel(){
    return m_funcModel;
}
void RenderVideo::setFuncModel(FunctionModel* engine) {
    if (m_funcModel != engine) {
        m_funcModel = engine;
        emit funcModelChanged();
        connect(m_funcModel, &FunctionModel::EngineFrameChanged, this, &RenderVideo::onFrameChanged);
    }
}
void RenderVideo::paint(QPainter *painter){
    if (!currentFrame.isNull()) {
        painter->drawImage(boundingRect(), currentFrame);
    }
}
void RenderVideo::onFrameChanged(const QVideoFrame &frame) {
    currentFrame = frame.toImage();
    update();
}
