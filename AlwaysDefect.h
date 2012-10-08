#ifndef ALWAYSDEFECT_H
#define ALWAYSDEFECT_H

#include "StrategyInterface.h"
#include <QObject>

class AlwaysDefect : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    AlwaysDefect();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // ALWAYSDEFECT_H
