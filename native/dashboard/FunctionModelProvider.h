#ifndef FUNCTIONMODELPROVIDER_H
#define FUNCTIONMODELPROVIDER_H

#include <QObject>

class FunctionModelProvider : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.toanvv11.vn")
    Q_PROPERTY(QString songReceive READ songReceive WRITE setSongReceive NOTIFY songReceiveChanged)
    Q_PROPERTY(bool statePlay READ statePlay WRITE setStatePlay NOTIFY statePlayChanged)
public:
    explicit FunctionModelProvider(QObject *parent = nullptr);
    QString songReceive() const;
    void setSongReceive(const QString &newSongReceive);

    bool statePlay() const;
    void setStatePlay(bool newStatePlay);

public slots:
    void receiveSongName(const QString &songName);
    void receiveStatePlay(bool statePlay);
signals:
    void songReceiveChanged();
    void statePlayChanged();

private:
    QString m_songReceive{};
    bool m_statePlay;
};

#endif // FUNCTIONMODELPROVIDER_H
