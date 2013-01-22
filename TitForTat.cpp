#include "TitForTat.h"
#include <QDebug>

TitForTat::TitForTat()
{
}

int TitForTat::getAction(Game *game, PlayHist *history, int player)
{
    int other_player = ((player + 2) % 2 ) + 1;
//    qDebug() << "Player:" << player << " Other P:" << other_player;
    int my_action = history->getLastAction(player);
    int other_action = history->getLastAction(other_player);
//    qDebug() << "Other Player:" << other_action << " Me:" << my_action;
    if ( other_action == 1 ) {
        return 1;
    } else {
        return 0;
    }
}

QString TitForTat::getName()
{
    return "TfT";
}
