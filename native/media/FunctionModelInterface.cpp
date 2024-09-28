#include "FunctionModelInterface.h"

FunctionModelInterface::FunctionModelInterface(QObject *parent):
    QDBusAbstractInterface("com.toanvv.vn","/ToanVV11","com.toanvv11.vn",QDBusConnection::sessionBus(),parent)
{

}

void FunctionModelInterface::sendSongName(QString &songName)
{
    asyncCall("receiveSongName",songName);
}

void FunctionModelInterface::sendPlayState(bool statePlay)
{
    asyncCall("receiveStatePlay",statePlay);
}

