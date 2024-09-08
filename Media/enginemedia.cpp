#include "enginemedia.h"

EngineMedia::EngineMedia(QObject *parent) : QObject(parent) {
    M_Player = new QMediaPlayer(this);
}


EngineMedia::~EngineMedia()
{
    if(M_Player != nullptr){
        delete M_Player;
        M_Player = nullptr;
    }
}
