#include "ClimateInterface.h"


ClimateInterface::ClimateInterface(QObject *parent)
: QDBusAbstractInterface("com.example.climate.adapter", "/DashboardAdapter", "dashboard.climte.media", QDBusConnection::sessionBus(), parent)
{

}


void ClimateInterface::sendDataTemp(int data){
    asyncCall("onDataReceived",data);
    qWarning() << "sender : " << data;
}
