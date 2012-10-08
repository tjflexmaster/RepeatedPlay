#include "NeverForgiveUnprovoked.h"
#include "Arena.h"
#include <QDebug>

NeverForgiveUnprovoked::NeverForgiveUnprovoked()
{
    provoked = false;
}

int NeverForgiveUnprovoked::getAction(Game *game, PlayHist *history, int player)
{
    int other_player = ((player + 2) % 2 ) + 1;
    int my_action = history->getLastAction(player);
    int other_action = history->getLastAction(other_player);
    if ( other_action == 1 && !provoked ) {
//        qDebug() << "Unprovoked Defect " << my_action << " " << other_action;
        provoked = false;
        return 1;
    } else if ( other_action == 1 && provoked ) {
//        qDebug() << "Provoked Defect " << my_action << " " << other_action;
        provoked = false;
        return 0;
    } else if ( other_action == 0 && !provoked ) {
        //Provoke them 90% of the time
        if ( qrand() % 2 == 0 ) {
//            qDebug() << "Unprovoked Cooperate Defect " << my_action << " " << other_action;
            provoked = true;
            return 1;
        } else {
//            qDebug() << "Unprovoked Cooperate Coop " << my_action << " " << other_action;
            return 0;
        }
        return 0;
    } else if ( other_action == 0 && provoked ) {
//        qDebug() << "Provoked Cooperate " << my_action << " " << other_action;
        return 1;
    } else {
//        qDebug() << "Initial Action " << my_action << " " << other_action;
        return 0;
    }
}

QString NeverForgiveUnprovoked::getName()
{
    return "Never Forgive Unprovoked";
}

void NeverForgiveUnprovoked::reset()
{
    provoked = false;
}
