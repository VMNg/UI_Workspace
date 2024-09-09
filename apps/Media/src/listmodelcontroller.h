#ifndef LISTMODELCONTROLLER_H
#define LISTMODELCONTROLLER_H

#include <QObject>

class ListModelController : public QObject
{
    Q_OBJECT
public:
    explicit ListModelController(QObject *parent = nullptr);

signals:
};

#endif // LISTMODELCONTROLLER_H
