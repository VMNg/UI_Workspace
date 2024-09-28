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
public:
    explicit FunctionModel(QObject *parent = nullptr);
    static FunctionModel* initialize(QObject* parent = nullptr);
    static FunctionModel& getInstance();

    int temperature() const;
    Q_INVOKABLE void setTemperature(int newTemperature);
    int temperatureSup() const;
    Q_INVOKABLE void setTemperatureSup(int newTemperatureSup);
    void dataTemperatureChanged(int data);

signals:
    void temperatureChanged();
    void temperatureSupChanged();


private:
    int m_temperature;
    int m_temperatureSup;
    ClimateInterface* m_priv = new ClimateInterface() ;

};

#endif // FUNCTIONMODEL_H
