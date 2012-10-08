#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H

#include <QObject>
#include "StrategyInterface.h"

class RandomStrategy : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    RandomStrategy();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // RANDOMSTRATEGY_H
