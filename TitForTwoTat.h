#ifndef TITFORTWOTAT_H
#define TITFORTWOTAT_H

#include <QObject>
#include "StrategyInterface.h"

class TitForTwoTat : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    TitForTwoTat();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // TITFORTWOTAT_H
