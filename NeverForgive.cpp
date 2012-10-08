#include "NeverForgive.h"
#include <QDebug>

NeverForgive::NeverForgive()
{
}

int NeverForgive::getAction(Game *game, PlayHist *history, int player)
{
    int other_player = ((player + 2) % 2 ) + 1;
    int my_action = history->getLastAction(player);
    int other_action = history->getLastAction(other_player);
    if ( my_action == 1 || other_action == 1 ) {
//        qDebug() << "NF: defect " << " p1:" << my_action << " p2:" << other_action;
        return 1;
    } else {
//        qDebug() << "NF: cooperate " << " p1:" << my_action << " p2:" << other_action;
        return 0;
    }
}

QString NeverForgive::getName()
{
    return "Never Forgive";
}
