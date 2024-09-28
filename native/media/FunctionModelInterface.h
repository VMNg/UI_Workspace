#ifndef FUNCTIONMODELINTERFACE_H
#define FUNCTIONMODELINTERFACE_H

#include <QObject>
#include <QDBusAbstractInterface>
#include "FunctionModel.h"
class FunctionModelInterface:public QDBusAbstractInterface
{
    Q_OBJECT
public:
    explicit FunctionModelInterface(QObject *parent);
public slots:
    Q_INVOKABLE void sendSongName(QString& songName);
    Q_INVOKABLE void sendPlayState(bool statePlay);
};

#endif // FUNCTIONMODELINTERFACE_H
