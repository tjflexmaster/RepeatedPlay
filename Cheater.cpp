#include "Cheater.h"
#include <QDebug>

Cheater::Cheater()
{
    /*
      Strategy 0 = D*
      Strategy 1 = C*
      Strategy 2 = DC*
      */

    //Initial Strategy is D*
    _strategy = 0;
}

int Cheater::getAction(Game *game, PlayHist *history, int player)
{
    int other_player = ((player + 2) % 2 ) + 1;
    int my_action = history->getLastAction(player);
    int other_action = history->getLastAction(other_player);
    int action_num = history->totalActions();

//    qDebug() << "Strategy:" << _strategy << " ActionNum: " << action_num;
    //At round 3 I can some of the strategies I am facing
    if ( action_num == 3 ) {
        int first = history->getFirstAction(other_player);
        int second = history->getSecondToLastAction(other_player);
        int third = history->getLastAction(other_player);

        if ( first == 0 && second == 1 && third == 1 ) {
//            qDebug() << "Always Coop";
            _strategy = 1;
        } else if ( first == 0 && second == 0 && third == 1 ) {
//            qDebug() << "Always Switch";
            _strategy = 2;
        }
    } else if ( action_num == 5 && _strategy == 1 ) {
//        qDebug() << "Turn 5";
        int fourth = history->getSecondToLastAction(other_player);
        int fifth = history->getLastAction(other_player);

        if ( fourth == 1 && fifth == 0 ) {
            //Tit for Tat
//            qDebug() << "Always Coop";
            _strategy = 1; //Always Cooperate
        } else {
            //Never Forgive or Random
//            qDebug() << "Always Defect";
            _strategy = 0; //Always Defect
        }
    }

    if ( _strategy == 2 ) {
        //Do the opposite as last time
        return ((other_action + 3) % 2 );
    } else if ( _strategy == 1 ) {
        return 0;
    } else {
        return 1;
    }

}

QString Cheater::getName()
{
    return "Custom";
}

void Cheater::reset()
{
    _strategy = 0;
}
