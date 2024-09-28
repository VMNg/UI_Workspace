#include "MediaEngine.h"
#include "FunctionModel.h"
#include "RenderVideo.h"

EngineMedia::EngineMedia(QObject *parent) : QObject(parent), m_qmlEngine(this){
    qmlRegisterSingletonInstance<FunctionModel>("MDA.Models",1,0,"FunctionModel",FunctionModel::initialize(this));
    qmlRegisterType<RenderVideo>("RenderVideo", 1, 0, "VideoRender");
    m_qmlEngine.load(u"qrc:/PBL/Main.qml"_qs);
}

EngineMedia::~EngineMedia()
{

}
