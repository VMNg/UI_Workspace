#ifndef CLIMATEADAPTOR_H
#define CLIMATEADAPTOR_H

#include <QObject>
#include <QDBusAbstractAdaptor>
#include <QDBusConnection>

class ClimateAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
public:
    explicit ClimateAdaptor(QObject *parent = nullptr);

public slots:
    void sendDataTemperature(int data);

signals:
    void dataSent(int data);
};

#endif // CLIMATEADAPTOR_H
