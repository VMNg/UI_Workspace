#include "FunctionModel.h"

static FunctionModel* g_singleton = nullptr;

FunctionModel::FunctionModel(QObject *parent)
    : QObject{parent}
{
    m_temperature = 20;
    m_temperatureSup = 20;
}

FunctionModel *FunctionModel::initialize(QObject *parent)
{
    if (g_singleton == nullptr) {
        g_singleton = new FunctionModel(parent);
    }
    return g_singleton;

}

FunctionModel &FunctionModel::getInstance()
{
    if (g_singleton == nullptr) {
        qCritical("FunctionModel has not been initialized yet");
    }

    return *g_singleton;
}


int FunctionModel::temperature() const
{
    return m_temperature;
}

void FunctionModel::setTemperature(int newTemperature)
{
    if (m_temperature == newTemperature)
        return;
    m_temperature = newTemperature;
    emit temperatureChanged();
    dataTemperatureChanged(newTemperature);
}

int FunctionModel::temperatureSup() const
{
    return m_temperatureSup;
}

void FunctionModel::setTemperatureSup(int newTemperatureSup)
{
    if (m_temperatureSup == newTemperatureSup)
        return;
    m_temperatureSup = newTemperatureSup;
    emit temperatureSupChanged();
}

void FunctionModel::dataTemperatureChanged(int data)
{
    m_priv->sendDataTemp(data);
}
