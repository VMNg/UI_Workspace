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
    Q_PROPERTY(bool rearStatus READ rearStatus WRITE setRearStatus NOTIFY rearStatusChanged FINAL)
    Q_PROPERTY(bool frontStatus READ frontStatus WRITE setFrontStatus NOTIFY frontStatusChanged FINAL)
    Q_PROPERTY(bool seatHeaterRStatus READ seatHeaterRStatus WRITE setSeatHeaterRStatus NOTIFY seatHeaterRStatusChanged FINAL)
    Q_PROPERTY(bool seatHeaterLStatus READ seatHeaterLStatus WRITE setSeatHeaterLStatus NOTIFY seatHeaterLStatusChanged FINAL)
    Q_PROPERTY(int fanLv READ fanLv WRITE setFanLv NOTIFY fanLvChanged FINAL)
public:
    explicit DashboardInterface(QObject *parent = nullptr);

    int temp() const;
    void setTemp(int newTemp);

    bool rearStatus() const;
    void setRearStatus(bool newRearStatus);

    bool frontStatus() const;
    void setFrontStatus(bool newFrontStatus);

    bool seatHeaterRStatus() const;
    void setSeatHeaterRStatus(bool newSeatHeaterRStatus);

    bool seatHeaterLStatus() const;
    void setSeatHeaterLStatus(bool newSeatHeaterLStatus);

    int fanLv() const;
    void setFanLv(int newFanLv);

public slots:
    void onDataTempReceived(int data) {
        qInfo() << "DashboardInterface::onDataRearReceived";
        setTemp(data);
    }
    void onDataRearReceived(bool rear) {
        qInfo() << "DashboardInterface::onDataRearReceived";
        setRearStatus(rear);
    }
    void onDataFrontReceived(bool front) {
        qInfo() << "DashboardInterface::onDataFrontReceived";
        setFrontStatus(front);
    }
    void onDataSeatRReceived(bool seatHeaterRStatus) {
        qInfo() << "DashboardInterface::onDataSeatRReceived";
        setSeatHeaterRStatus(seatHeaterRStatus);
    }
    void onDataSeatLReceived(bool seatHeaterLStatus) {
        qInfo() << "DashboardInterface::onDataSeatLReceived";
        setSeatHeaterLStatus(seatHeaterLStatus);
    }
    void onDataFanLvReceived(int fanLv) {
        qInfo() << "DashboardInterface::onDataFanLvReceived";
        setFanLv(fanLv);
    }



signals:
    void tempChanged();
    void rearStatusChanged();
    void frontStatusChanged();
    void seatHeaterRStatusChanged();
    void seatHeaterLStatusChanged();
    void fanLvChanged();

private:
    int m_temp;
    bool m_rearStatus = false;
    bool m_frontStatus = false;
    bool m_seatHeaterRStatus = false;
    bool m_seatHeaterLStatus = false;
    int m_fanLv = -1;
};

class DashboardInterfaceAdaptor : public QDBusAbstractAdaptor
{
    friend class DashboardInterface;
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","dashboard.climte.media")
public:
    explicit DashboardInterfaceAdaptor(DashboardInterface *parent);

public slots:
    void onDataTempReceived(int temp);
    void onDataRearReceived(bool rear);
    void onDataFrontReceived(bool front);
    void onDataSeatLReceived(bool seatL);
    void onDataSeatRReceived(bool seatR);
    void onDataFanLvReceived(int fanLv);
private :
    DashboardInterface *m_parent;
};
#endif // DASHBOARDINTERFACE_H
