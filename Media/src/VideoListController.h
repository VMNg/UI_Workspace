#ifndef VIDEOLISTCONTROLLER_H
#define VIDEOLISTCONTROLLER_H

#include <QObject>
#include <QAbstractListModel>
class Video{
public:
    Video(QString name);
    QString getName() const;
private:
    QString videoName;
};
class VideoListController : public QAbstractListModel
{
    Q_OBJECT
public:
    enum VideoRole{
        nameVideo=Qt::UserRole+1
    };
    explicit VideoListController(QObject *parent = nullptr):QAbstractListModel(parent){
    }
    void addVideo(const Video &video);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
protected:
    QHash<int,QByteArray>roleNames()const;
private:
    QList<Video>listVideo;
signals:
};

#endif // VIDEOLISTCONTROLLER_H
