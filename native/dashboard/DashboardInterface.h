#ifndef DASHBOARDINTERFACE_H
#define DASHBOARDINTERFACE_H

#include <QObject>
#include <QDBusAbstractAdaptor>
#include <QDBusConnection>
#include <QDebug>
#include <qdebug.h>
#include "iostream"

class DashboardInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int temp READ temp WRITE setTemp NOTIFY tempChanged FINAL)
public:
    explicit DashboardInterface(QObject *parent = nullptr);

    int temp() const;
    void setTemp(int newTemp);

public slots:
    void onDataReceived(int data) {
        qInfo() << "DashboardInterface::onDataReceived";
        setTemp(data);
    }

signals:
    void tempChanged();
private:
    int m_temp;
};

class DashboardInterfaceAdaptor : public QDBusAbstractAdaptor
{
    friend class DashboardInterface;
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","dashboard.climte.media")
public:
    explicit DashboardInterfaceAdaptor(DashboardInterface *parent);

public slots:
    void onDataReceived(int data);
private :
    DashboardInterface *m_parent;
};
#endif // DASHBOARDINTERFACE_H
