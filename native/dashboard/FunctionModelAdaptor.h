#ifndef FUNCTIONMODELADAPTOR_H
#define FUNCTIONMODELADAPTOR_H

#include <QObject>
#include <QDBusInterface>
#include <QDBusAbstractAdaptor>
#include <QDBusConnection>

class FunctionModelAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.toanvv11.vn")
public:
    explicit FunctionModelAdaptor(QObject *parent);
public slots:
    void receiveSongName(const QString &songName);
    void receiveStatePlay(bool statePlay);
signals:
};

#endif // FUNCTIONMODELADAPTOR_H
