#ifndef ALWAYSCOOPERATE_H
#define ALWAYSCOOPERATE_H

#include <QObject>
#include "StrategyInterface.h"

class AlwaysCooperate : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    AlwaysCooperate();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // ALWAYSCOOPERATE_H
