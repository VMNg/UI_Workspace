#include "ClimateInterface.h"


ClimateInterface::ClimateInterface(QObject *parent)
: QDBusAbstractInterface("com.example.climate.adapter", "/DashboardAdapter", "dashboard.climte.media", QDBusConnection::sessionBus(), parent)
{

}


void ClimateInterface::sendDataTemp(int temp){
    asyncCall("onDataTempReceived",temp);
    qWarning() << "sender Temp: " << temp;
}

void ClimateInterface::sendDataRear(bool rear){
    asyncCall("onDataRearReceived",rear);
    qWarning() << "sender Rear: " << rear;
}

void ClimateInterface::sendDataFront(bool front){
    asyncCall("onDataFrontReceived",front);
    qWarning() << "sender Front: " << front;
}

void ClimateInterface::sendDataSeatR(bool seatR){
    asyncCall("onDataSeatRReceived",seatR);
    qWarning() << "sender SeatR: " << seatR;
}

void ClimateInterface::sendDataSeatL(bool seatL){
    asyncCall("onDataSeatLReceived",seatL);
    qWarning() << "sender SeatL: " << seatL;
}

void ClimateInterface::sendDataFanLv(int fanLv){
    asyncCall("onDataFanLvReceived",fanLv);
    qWarning() << "sender FanLv: " << fanLv;
}


