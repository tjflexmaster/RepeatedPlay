#include "WSLS.h"

WSLS::WSLS()
{
}

int WSLS::getAction(Game *game, PlayHist *history, int player)
{
    int other_player = ((player + 2) % 2 ) + 1;
    int my_action = history->getLastAction(player);
    int other_action = history->getLastAction(other_player);
    if ( other_action == 0 ) {
        return my_action;
    } else if ( other_action == 1 ) {
        return (my_action + 3) % 2;
    } else {
        return 0;
    }
}

QString WSLS::getName()
{
    return "WSLS";
}
