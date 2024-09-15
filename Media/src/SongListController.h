#ifndef SONGLISTCONTROLLER_H
#define SONGLISTCONTROLLER_H

#include <QObject>
#include <QAbstractListModel>
#include <QDir>
class Song{
public:
    Song(QString name);
    QString getName() const;
private:
    QString songName;
};

class SongListController:public QAbstractListModel
{
    Q_OBJECT
public:
    enum SongRole{
        nameSong=Qt::UserRole+1
    };
    explicit SongListController(QObject *parent=nullptr):QAbstractListModel(parent){
    }
    void addSong(const Song &song);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
protected:
    QHash<int,QByteArray>roleNames()const;
private:
    QList<Song>listSong;
};

#endif // SONGLISTCONTROLLER_H
