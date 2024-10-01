#ifndef FUNCTIONMODEL_H
#define FUNCTIONMODEL_H

#include <QObject>
#include "ClimateInterface.h"

class ClimateEngine;
class FunctionModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged FINAL)
    Q_PROPERTY(int temperatureSup READ temperatureSup WRITE setTemperatureSup NOTIFY temperatureSupChanged FINAL)
    Q_PROPERTY(bool activeRear READ activeRear WRITE setActiveRear NOTIFY activeRearChanged FINAL)
    Q_PROPERTY(bool activeFront READ activeFront WRITE setActiveFront NOTIFY activeFrontChanged FINAL)
    Q_PROPERTY(bool seatHeaterRStatus READ seatHeaterRStatus WRITE setSeatHeaterRStatus NOTIFY seatHeaterRStatusChanged FINAL)
    Q_PROPERTY(bool seatHeaterLStatus READ seatHeaterLStatus WRITE setSeatHeaterLStatus NOTIFY seatHeaterLStatusChanged FINAL)
    Q_PROPERTY(int fanLv READ fanLv WRITE setFanLv NOTIFY fanLvChanged FINAL)
public:
    explicit FunctionModel(QObject *parent = nullptr);
    static FunctionModel* initialize(QObject* parent = nullptr);
    static FunctionModel& getInstance();

    int temperature() const;
    Q_INVOKABLE void setTemperature(int newTemperature);
    int temperatureSup() const;
    Q_INVOKABLE void setTemperatureSup(int newTemperatureSup);
    void dataTemperatureChanged(int data);

    bool activeRear() const;
    void setActiveRear(bool newActiveRear);
    void dataActiveRearChanged(bool data);

    bool activeFront() const;
    void setActiveFront(bool newActiveFront);
    void dataActiveFrontChanged(bool data);

    bool seatHeaterRStatus() const;
    void setSeatHeaterRStatus(bool newSeatHeaterRStatus);
    void dataSeatHeaterRStatusChanged(bool data);

    bool seatHeaterLStatus() const;
    void setSeatHeaterLStatus(bool newSeatHeaterLStatus);
    void dataSeatHeaterLStatusChanged(bool data);

    int fanLv() const;
    void setFanLv(int newFanLv);
    void dataFanLvChanged(int data);
signals:
    void temperatureChanged();

    void temperatureSupChanged();

    void activeRearChanged();

    void activeFrontChanged();

    void seatHeaterRStatusChanged();

    void seatHeaterLStatusChanged();

    void fanLvChanged();

private:
    int m_temperature;
    int m_temperatureSup;
    ClimateInterface* m_priv = new ClimateInterface() ;

    bool m_activeRear = false;
    bool m_activeFront = false;
    bool m_seatHeaterRStatus = false;
    bool m_seatHeaterLStatus = false;
    int m_fanLv;
};

#endif // FUNCTIONMODEL_H
