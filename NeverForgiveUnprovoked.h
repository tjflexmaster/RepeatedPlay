#ifndef NEVERFORGIVEUNPROVOKED_H
#define NEVERFORGIVEUNPROVOKED_H

#include <QObject>
#include "StrategyInterface.h"

class NeverForgiveUnprovoked : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    NeverForgiveUnprovoked();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
    void reset();

private:
    bool provoked;
    bool infinite;
    int total_plays;
    double probability;
};

#endif // NEVERFORGIVEUNPROVOKED_H
