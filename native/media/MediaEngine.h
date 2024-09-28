#ifndef ENGINEMEDIA_H
#define ENGINEMEDIA_H

#include <QObject>
#include <QQmlApplicationEngine>

class EngineMedia : public QObject
{
    Q_OBJECT
public:
    explicit EngineMedia(QObject *parent = nullptr);
    ~EngineMedia();
private:
    QQmlApplicationEngine m_qmlEngine;
};

#endif // ENGINEMEDIA_H
