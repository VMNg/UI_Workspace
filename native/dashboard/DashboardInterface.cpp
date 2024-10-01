#include "DashboardInterface.h"

DashboardInterface::DashboardInterface(QObject *parent)
    : QObject{parent}
{
    new DashboardInterfaceAdaptor(this);
    QDBusConnection::sessionBus().registerObject("/DashboardAdapter", this);
    m_temp = 20;
}

int DashboardInterface::temp() const
{
    return m_temp;
}

void DashboardInterface::setTemp(int newTemp)
{
    if (m_temp == newTemp)
        return;
    m_temp = newTemp;
    emit tempChanged();
    qWarning() << "nhan duoc" << newTemp;
}

bool DashboardInterface::rearStatus() const
{
    return m_rearStatus;
}

void DashboardInterface::setRearStatus(bool newRearStatus)
{
    if (m_rearStatus == newRearStatus)
        return;
    m_rearStatus = newRearStatus;
    emit rearStatusChanged();
    qWarning() << "nhan duoc rear" << newRearStatus;
}

bool DashboardInterface::frontStatus() const
{
    return m_frontStatus;
}

void DashboardInterface::setFrontStatus(bool newFrontStatus)
{
    if (m_frontStatus == newFrontStatus)
        return;
    m_frontStatus = newFrontStatus;
    emit frontStatusChanged();
}

bool DashboardInterface::seatHeaterRStatus() const
{
    return m_seatHeaterRStatus;
}

void DashboardInterface::setSeatHeaterRStatus(bool newSeatHeaterRStatus)
{
    if (m_seatHeaterRStatus == newSeatHeaterRStatus)
        return;
    m_seatHeaterRStatus = newSeatHeaterRStatus;
    emit seatHeaterRStatusChanged();
}

bool DashboardInterface::seatHeaterLStatus() const
{
    return m_seatHeaterLStatus;
}

void DashboardInterface::setSeatHeaterLStatus(bool newSeatHeaterLStatus)
{
    if (m_seatHeaterLStatus == newSeatHeaterLStatus)
        return;
    m_seatHeaterLStatus = newSeatHeaterLStatus;
    emit seatHeaterLStatusChanged();
}

int DashboardInterface::fanLv() const
{
    return m_fanLv;
}

void DashboardInterface::setFanLv(int newFanLv)
{
    if (m_fanLv == newFanLv)
        return;
    m_fanLv = newFanLv;
    qWarning() << "Nhan dc fan lv" << newFanLv;
    emit fanLvChanged();
}



DashboardInterfaceAdaptor::DashboardInterfaceAdaptor(DashboardInterface *parent)
: QDBusAbstractAdaptor(parent), m_parent(parent)
{
}

void DashboardInterfaceAdaptor::onDataTempReceived(int temp)
{
    m_parent->onDataTempReceived(temp);
}

void DashboardInterfaceAdaptor::onDataRearReceived(bool rear)
{
    m_parent->onDataRearReceived(rear);
}

void DashboardInterfaceAdaptor::onDataFrontReceived(bool front)
{
    m_parent->onDataFrontReceived(front);
}

void DashboardInterfaceAdaptor::onDataSeatRReceived(bool seatR)
{
    m_parent->onDataSeatRReceived(seatR);
}

void DashboardInterfaceAdaptor::onDataSeatLReceived(bool seatL)
{
    m_parent->onDataSeatLReceived(seatL);
}

void DashboardInterfaceAdaptor::onDataFanLvReceived(int fanLv)
{
    m_parent->onDataFanLvReceived(fanLv);
}

