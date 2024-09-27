#ifndef CLIMATEENGINE_H
#define CLIMATEENGINE_H

#include <QObject>
#include <QQmlEngine>
#include "FunctionModel.h"

class ClimateEngine : public QObject
{
    Q_OBJECT
public:
    explicit ClimateEngine(QObject *parent = nullptr);
    ~ClimateEngine();
    int doInitialize();
    void registerQMLModules();

signals:
};

#endif // CLIMATEENGINE_H
