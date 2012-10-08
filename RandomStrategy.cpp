#include "RandomStrategy.h"

RandomStrategy::RandomStrategy()
{
}

int RandomStrategy::getAction(Game *game, PlayHist *history, int player)
{
    return qrand() % 2;
}

QString RandomStrategy::getName()
{
    return "Random Strategy";
}
