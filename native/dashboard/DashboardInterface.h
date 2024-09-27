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
    Q_PROPERTY(int tmp READ tmp WRITE setTmp NOTIFY tmpChanged FINAL)
public:
    explicit DashboardInterface(QObject *parent = nullptr);

    int tmp() const;
    void setTmp(int newTmp);

public slots:
    void onDataReceived(int data) {
        qInfo() << "DashboardInterface::onDataReceived";
        setTmp(data);
    }

signals:
    void tmpChanged();
private:
    int m_tmp;
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
