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

DashboardInterfaceAdaptor::DashboardInterfaceAdaptor(DashboardInterface *parent)
: QDBusAbstractAdaptor(parent), m_parent(parent)
{
}

void DashboardInterfaceAdaptor::onDataReceived(int data)
{
    qInfo() << "DashboardInterfaceAdaptor::onDataReceived";
    m_parent->onDataReceived(data);
}
