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
    void sendDataTemp(int temp);
    void sendDataRear(bool rear);
    void sendDataFront(bool front);
    void sendDataSeatR(bool seatR);
    void sendDataSeatL(bool seatL);
    void sendDataFanLv(int fanLv);

signals:


private:
};

#endif // CLIMATEINTERFACE_H
