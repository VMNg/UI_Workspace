#ifndef ENGINEMEDIA_H
#define ENGINEMEDIA_H

#include <QObject>
#include <QtMultimedia/QMediaPlayer>

class EngineMedia : public QObject
{
    Q_OBJECT
public:
    explicit EngineMedia(QObject *parent = nullptr);
    ~EngineMedia();

private:
    QMediaPlayer *M_Player;
};

#endif // ENGINEMEDIA_H
