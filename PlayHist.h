#ifndef PLAYHIST_H
#define PLAYHIST_H

#include <QList>

class PlayHist
{
public:
    PlayHist();

    QList<int>* getAllHist(int player);
    int getLastAction(int player);
    int getSecondToLastAction(int player);
    int getFirstAction(int player);
    void addAction(int player1_action, int player2_action);
    int totalActions();

private:
    QList<int> *player1_hist;
    QList<int> *player2_hist;
};

#endif // PLAYHIST_H
