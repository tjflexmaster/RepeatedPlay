#include "Arena.h"
#include <QDebug>

Arena::Arena(Game *game, StrategyInterface *strat1, StrategyInterface *strat2)
{
    _game = game;
    _strat1 = strat1;
    _strat2 = strat2;
}

void Arena::run(int repetitions)
{
    _total_repetitions = repetitions;
    int i = 0;
    while ( i < repetitions ) {
        int p1_action = _strat1->getAction(_game, &play_hist, 1);
        int p2_action = _strat2->getAction(_game, &play_hist, 2);

        //Add this action to the history
        play_hist.addAction(p1_action, p2_action);

//        qDebug() << "P1A: " << p1_action << " P2A: " << p2_action;
        //Add up the players score
        player1_score.append(_game->getPayoff(p1_action, p2_action, 1));
        player2_score.append(_game->getPayoff(p1_action, p2_action, 2));

        i++;
    }

}


void Arena::run(qreal continue_weight)
{
    int threshold = qRound(continue_weight * 100);
    int random = 0;
    int i = 0;
    qreal player1_sum = 0;
    qreal player2_sum = 0;
    while ( random < threshold ) {
        int p1_action = _strat1->getAction(_game, &play_hist, 1);
        int p2_action = _strat2->getAction(_game, &play_hist, 2);

        //Add this action to the history
        play_hist.addAction(p1_action, p2_action);

        player1_sum += _game->getPayoff(p1_action, p2_action, 1);
        player2_sum += _game->getPayoff(p1_action, p2_action, 2);
//        qDebug() << "P1 Sum: " << player1_sum;
        random = qrand() % 100 + 1;
        i++;
    }
//    qDebug() << "Norm Sum: " << (player1_sum / i) << " denom:" << i;
    player1_score.append( qreal(player1_sum / i) );
    player2_score.append( qreal(player2_sum / i) );
    _total_repetitions = i;
}

qreal Arena::getScore(int player)
{
    Q_ASSERT(player > 0 && player < 3);
    qreal sum = 0;
    if ( player == 1 ) {
        foreach(qreal s, player1_score) {
            sum += s;
        }
    } else {
        foreach(qreal s, player2_score) {
            sum += s;
        }
    }
    return sum;
}

int Arena::getRepetitions()
{
    return _total_repetitions;
}
