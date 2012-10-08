#ifndef WSLS_H
#define WSLS_H

#include <QObject>
#include "StrategyInterface.h"

class WSLS : public QObject, public StrategyInterface
{
    Q_OBJECT
    Q_INTERFACES(StrategyInterface)
public:
    WSLS();

    int getAction(Game *game, PlayHist *history, int player);
    QString getName();
};

#endif // WSLS_H
