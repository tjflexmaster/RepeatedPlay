#ifndef PAVLOV_H
#define PAVLOV_H

#include <QObject>
#include "StrategyInterface.h"

class Pavlov : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    Pavlov();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // PAVLOV_H
