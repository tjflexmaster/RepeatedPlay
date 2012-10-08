#ifndef STRATEGYINTERFACE_H
#define STRATEGYINTERFACE_H
#include <QObject>
#include "Game.h"
#include "PlayHist.h"

class StrategyInterface
{
public:
    StrategyInterface();

    virtual int getAction(Game *game, PlayHist *history, int player) = 0;
    virtual QString getName() = 0;
    virtual void reset();
};
Q_DECLARE_INTERFACE(StrategyInterface, "StrategyInterface")

#endif // STRATEGYINTERFACE_H
