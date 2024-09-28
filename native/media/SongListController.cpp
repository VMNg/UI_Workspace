#include "SongListController.h"

Song::Song(QString name)
{
    songName=name;
}
QString Song::getName() const{
    return songName;
}
void SongListController::addSong(const Song &song)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    listSong<<song;
    endInsertRows();
}
QVariant SongListController::data(const QModelIndex &index, int role) const{
    if(index.row()<0||index.row()>=listSong.count())
        return QVariant();
    const Song &song=listSong[index.row()];
    if(role==nameSong)
        return song.getName();
    return QVariant();
}
int SongListController::rowCount(const QModelIndex &parent) const{
    return listSong.count();
}
QHash<int,QByteArray>SongListController::roleNames()const{
    QHash<int,QByteArray> roles;
    roles[nameSong]="nameSong";
    return roles;
}

bool SongListController::visible() const
{
    return m_visible;
}

void SongListController::setVisible(bool newVisible)
{
    if (m_visible == newVisible)
        return;
    m_visible = newVisible;
    emit visibleChanged();
}

void SongListController::setVisibleUI(bool status)
{
    setVisible(status);
}
