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
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged FINAL)
public:
    enum SongRole{
        nameSong=Qt::UserRole+1
    };
    explicit SongListController(QObject *parent=nullptr):QAbstractListModel(parent){
    }
    void addSong(const Song &song);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    bool visible() const;
    void setVisible(bool newVisible);

public slots:
    void setVisibleUI(bool status);
    QString getSongName(int idx){
        return listSong[idx].getName();
    }
signals:
    void visibleChanged();

protected:
    QHash<int,QByteArray>roleNames()const;
private:
    QList<Song>listSong;
    bool m_visible = true;
};

#endif // SONGLISTCONTROLLER_H
