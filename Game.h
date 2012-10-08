#ifndef GAME_H
#define GAME_H

#include <QList>

class Game
{

public:
    Game();
    Game(int rows, int columns);

    void setPayoff(int row, int column, int player, int value);
    int getPayoff(int row, int column, int player);

private:
    QList<int> *player1_payoffs;
    QList<int> *player2_payoffs;

    void initialize(int rows, int columns);
    int getIndex(int row, int column);
    int _max_index;
    int _rows;
    int _columns;
};

#endif // GAME_H
