#include "TitForTwoTat.h"

TitForTwoTat::TitForTwoTat()
{
}

int TitForTwoTat::getAction(Game *game, PlayHist *history, int player)
{
    int other_player = ((player + 2) % 2 ) + 1;
    int my_action = history->getLastAction(player);
    int other_action = history->getLastAction(other_player);
    int other_action2 = history->getSecondToLastAction(other_player);
    if ( other_action2 == 1 && other_action == 1 ) {
        return 1;
    } else {
        return 0;
    }
}

QString TitForTwoTat::getName()
{
    return "Tf2T";
}
