#ifndef ARENA_H
#define ARENA_H

#include <QList>
#include "Game.h"
#include "PlayHist.h"
#include "StrategyInterface.h"

class Arena
{
public:
    Arena(Game *game, StrategyInterface *strat1, StrategyInterface *strat2);
    void run(int repetitions);
    void run( qreal continue_weight);
    qreal getScore(int player);
    int getRepetitions();

private:
    QList<qreal> player1_score;
    QList<qreal> player2_score;

    StrategyInterface *_strat1;
    StrategyInterface *_strat2;

    PlayHist play_hist;
    Game *_game;

    int _total_repetitions;

    static int repetitions;
    static qreal continue_weight;

};

#endif // ARENA_H
