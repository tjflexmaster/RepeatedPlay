#ifndef NEVERFORGIVE_H
#define NEVERFORGIVE_H

#include <QObject>
#include "StrategyInterface.h"

class NeverForgive : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    NeverForgive();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // NEVERFORGIVE_H
