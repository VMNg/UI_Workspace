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
    dataTemperatureChanged(round((newTemperature + m_temperatureSup) / 2.0));
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
    dataTemperatureChanged(round((m_temperature + newTemperatureSup) / 2.0));
}

void FunctionModel::dataTemperatureChanged(int data)
{
    m_priv->sendDataTemp(data);
}

bool FunctionModel::activeRear() const
{
    return m_activeRear;
}

void FunctionModel::setActiveRear(bool newActiveRear)
{
    if (m_activeRear == newActiveRear)
        return;
    m_activeRear = newActiveRear;
    qWarning() << "setActiveRear" << m_activeRear;
    emit activeRearChanged();
    dataActiveRearChanged(newActiveRear);
}

void FunctionModel::dataActiveRearChanged(bool data)
{
    m_priv->sendDataRear(data);
}

bool FunctionModel::activeFront() const
{
    return m_activeFront;
}

void FunctionModel::setActiveFront(bool newActiveFront)
{
    if (m_activeFront == newActiveFront)
        return;
    m_activeFront = newActiveFront;
    qWarning() << "setActiveFront" << m_activeFront;
    emit activeFrontChanged();
    dataActiveFrontChanged(newActiveFront);
}

void FunctionModel::dataActiveFrontChanged(bool data)
{
    m_priv->sendDataFront(data);
}

bool FunctionModel::seatHeaterRStatus() const
{
    return m_seatHeaterRStatus;
}

void FunctionModel::setSeatHeaterRStatus(bool newSeatHeaterRStatus)
{
    if (m_seatHeaterRStatus == newSeatHeaterRStatus)
        return;
    m_seatHeaterRStatus = newSeatHeaterRStatus;
    emit seatHeaterRStatusChanged();
    dataSeatHeaterRStatusChanged(newSeatHeaterRStatus);
}

void FunctionModel::dataSeatHeaterRStatusChanged(bool data)
{
    m_priv->sendDataSeatR(data);
}

bool FunctionModel::seatHeaterLStatus() const
{
    return m_seatHeaterLStatus;
}

void FunctionModel::setSeatHeaterLStatus(bool newSeatHeaterLStatus)
{
    if (m_seatHeaterLStatus == newSeatHeaterLStatus)
        return;
    m_seatHeaterLStatus = newSeatHeaterLStatus;
    emit seatHeaterLStatusChanged();
    dataSeatHeaterLStatusChanged(newSeatHeaterLStatus);
}

void FunctionModel::dataSeatHeaterLStatusChanged(bool data)
{
    m_priv->sendDataSeatL(data);
}

int FunctionModel::fanLv() const
{
    return m_fanLv;
}

void FunctionModel::setFanLv(int newFanLv)
{
    if (m_fanLv == newFanLv)
        return;
    m_fanLv = newFanLv;
    emit fanLvChanged();
    dataFanLvChanged(newFanLv);
}

void FunctionModel::dataFanLvChanged(int data)
{
    m_priv->sendDataFanLv(data);
}
