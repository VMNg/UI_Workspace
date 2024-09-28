#include "FunctionModelAdaptor.h"
#include <QDebug>

FunctionModelAdaptor::FunctionModelAdaptor(QObject *parent) : QDBusAbstractAdaptor(parent){
}

void FunctionModelAdaptor::receiveSongName(const QString &songName) {

    QMetaObject::invokeMethod(parent(), "receiveSongName",Q_ARG(QString, songName));
}

void FunctionModelAdaptor::receiveStatePlay(bool statePlay)
{
    QMetaObject::invokeMethod(parent(), "receiveStatePlay",Q_ARG(bool, statePlay));
}

