#ifndef CLIMATEINTERFACE_H
#define CLIMATEINTERFACE_H

#include <QObject>
#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusArgument>
#include <QDBusConnectionInterface>
#include <QDBusAbstractInterface>

class ClimateInterface : public QDBusAbstractInterface
{
    Q_OBJECT
public:
    explicit ClimateInterface(QObject *parent = nullptr);

public slots:
    void sendDataTemp(int srcImg);

signals:


private:
};

#endif // CLIMATEINTERFACE_H
