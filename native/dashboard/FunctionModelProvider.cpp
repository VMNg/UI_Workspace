#include "FunctionModelProvider.h"
#include <QDebug>
FunctionModelProvider::FunctionModelProvider(QObject *parent)
    : QObject{parent},m_songReceive{"24H.mp3"},m_statePlay{false}
{}

QString FunctionModelProvider::songReceive() const
{
    return m_songReceive;
}

void FunctionModelProvider::setSongReceive(const QString &newSongReceive)
{
    if (m_songReceive == newSongReceive)
        return;
    m_songReceive = newSongReceive;
    emit songReceiveChanged();
}

void FunctionModelProvider::receiveSongName(const QString &songName)
{
    setSongReceive(songName);
}

void FunctionModelProvider::receiveStatePlay(bool statePlay)
{
    setStatePlay(statePlay);
}

bool FunctionModelProvider::statePlay() const
{
    return m_statePlay;
}

void FunctionModelProvider::setStatePlay(bool newStatePlay)
{
    if (m_statePlay == newStatePlay)
        return;
    m_statePlay = newStatePlay;
    emit statePlayChanged();
}
