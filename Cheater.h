#ifndef CHEATER_H
#define CHEATER_H
#include <QObject>
#include "StrategyInterface.h"

class Cheater : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)

public:
    Cheater();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
    void reset();

    int _strategy;
};

#endif // CHEATER_H
