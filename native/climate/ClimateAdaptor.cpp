#include "ClimateAdaptor.h"

ClimateAdaptor::ClimateAdaptor(QObject *parent)
    : QDBusAbstractAdaptor{parent}
{
    QDBusConnection::sessionBus().registerService("com.example.Climate");
    QDBusConnection::sessionBus().registerObject("/climate", this);
}

void ClimateAdaptor::sendDataTemperature(int data)
{
    emit dataSent(data);
}
