#ifndef TITFORTAT_H
#define TITFORTAT_H

#include <QObject>
#include "StrategyInterface.h"

class TitForTat : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)

public:
    TitForTat();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // TITFORTAT_H
