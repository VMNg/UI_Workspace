#ifndef ENGINEMEDIA_H
#define ENGINEMEDIA_H

#include <QObject>
#include <QtMultimedia>
#include <QDebug>
#include <QFile>

class EngineMedia : public QObject
{
    Q_OBJECT
public:
    explicit EngineMedia(QObject *parent = nullptr);
    ~EngineMedia();

signals:
    void play();
    void pause();
    void next();
    void previous();
    void shuffer();

private slots:
    void on_pushButton_Play_clicked();
    void on_pushButton_Pause_clicked();
    void on_pushButton_Next_clicked();
    void on_pushButton_Previous_clicked();
    void on_pushButton_Shuffer_clicked();

public slots:
    void playClicked();
    void pauseClicked();
    void nextClicked();
    void previousClicked();
    void shufferClicked();

private:
    QMediaPlayer *M_Player;
    QAudioOutput *audioOutput;
};

#endif // ENGINEMEDIA_H
