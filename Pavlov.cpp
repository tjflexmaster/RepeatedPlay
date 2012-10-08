#include "Pavlov.h"

Pavlov::Pavlov()
{
}

int Pavlov::getAction(Game *game, PlayHist *history, int player)
{
    int other_player = ((player + 2) % 2 ) + 1;
    int my_action = history->getLastAction(player);
    int other_action = history->getLastAction(other_player);
    if ( other_action != my_action ) {
        return 1;
    } else {
        return 0;
    }
}

QString Pavlov::getName()
{
    return "Pavlov";
}
