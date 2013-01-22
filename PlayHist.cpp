#include "PlayHist.h"
#include <QList>

PlayHist::PlayHist()
{
    player1_hist = new QList<int>();
    player2_hist = new QList<int>();
}

QList<int>* PlayHist::getAllHist(int player)
{
    Q_ASSERT(player > 0 && player < 3);

    if ( player == 1 ) {
        return player1_hist;
    } else {
        return player2_hist;
    }
}

int PlayHist::getFirstAction(int player)
{
    Q_ASSERT(player > 0 && player < 3);

    if ( player == 1 ) {
        if ( player1_hist->isEmpty() ) {
            return -1;
        } else {
            return player1_hist->first();
        }
    } else {
        if ( player2_hist->isEmpty() ) {
            return -1;
        } else {
            return player2_hist->first();
        }
    }
}

int PlayHist::getLastAction(int player)
{
    Q_ASSERT(player > 0 && player < 3);

    if ( player == 1 ) {
        if ( player1_hist->isEmpty() ) {
            return -1;
        } else {
            return player1_hist->last();
        }
    } else {
        if ( player2_hist->isEmpty() ) {
            return -1;
        } else {
            return player2_hist->last();
        }
    }
}

int PlayHist::getSecondToLastAction(int player)
{
    Q_ASSERT(player > 0 && player < 3);
    if ( player == 1 ) {
        if ( player1_hist->isEmpty() || player1_hist->count() < 2 ) {
            return -1;
        } else {
            return player1_hist->value(player1_hist->count() - 1, -1);
        }
    } else {
        if ( player2_hist->isEmpty() || player2_hist->count() < 2 ) {
            return -1;
        } else {
            return player2_hist->value(player2_hist->count() - 1, -1);
        }
    }
}

void PlayHist::addAction(int player1_action, int player2_action)
{
    player1_hist->append(player1_action);
    player2_hist->append(player2_action);

}

int PlayHist::totalActions()
{
    return player1_hist->count();
}
