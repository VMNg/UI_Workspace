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
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged FINAL)
public:
    enum VideoRole{
        nameVideo=Qt::UserRole+1
    };
    explicit VideoListController(QObject *parent = nullptr):QAbstractListModel(parent){
    }
    void addVideo(const Video &video);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    bool visible() const;
    void setVisible(bool newVisible);

public slots:
    void setVisibleUI(bool status);

protected:
    QHash<int,QByteArray>roleNames()const;
private:
    QList<Video>listVideo;
    bool m_visible = false;

signals:
    void visibleChanged();
};

#endif // VIDEOLISTCONTROLLER_H
