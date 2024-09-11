#include "VideoListController.h"

Video::Video(QString name)
{
    videoName=name;
}
QString Video::getName() const{
    return videoName;
}
void VideoListController::addVideo(const Video &song)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    listVideo<<song;
    endInsertRows();
}
QVariant VideoListController::data(const QModelIndex &index, int role) const{
    if(index.row()<0||index.row()>=listVideo.count())
        return QVariant();
    const Video &song=listVideo[index.row()];
    if(role==nameVideo)
        return song.getName();
    return QVariant();
}
int VideoListController::rowCount(const QModelIndex &parent) const{
    return listVideo.count();
}
QHash<int,QByteArray>VideoListController::roleNames()const{
    QHash<int,QByteArray> roles;
    roles[nameVideo]="nameVideo";
    return roles;
}
