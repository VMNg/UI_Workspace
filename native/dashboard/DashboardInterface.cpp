#include "DashboardInterface.h"

DashboardInterface::DashboardInterface(QObject *parent)
    : QObject{parent}
{
    new DashboardInterfaceAdaptor(this);
    QDBusConnection::sessionBus().registerObject("/DashboardAdapter", this);
}

int DashboardInterface::tmp() const
{
    return m_tmp;
}

void DashboardInterface::setTmp(int newTmp)
{
    if (m_tmp == newTmp)
        return;
    m_tmp = newTmp;
    emit tmpChanged();
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
