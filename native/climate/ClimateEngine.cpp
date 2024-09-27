#include "ClimateEngine.h"

ClimateEngine::ClimateEngine(QObject *parent)
    : QObject{parent}
{}

ClimateEngine::~ClimateEngine()
{

}

int ClimateEngine::doInitialize()
{
    registerQMLModules();
    return 0;
}

void ClimateEngine::registerQMLModules()
{
    qmlRegisterSingletonInstance<FunctionModel>("Climate.Models",1,0,"FunctionModel",FunctionModel::initialize(this));
}
