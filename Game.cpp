#include "Game.h"
#include <QList>
#include <QDebug>

Game::Game()
{
    initialize(2,2);
}

Game::Game(int rows, int columns)
{
    initialize(rows, columns);
}

void Game::initialize(int rows, int columns)
{
    _rows = rows;
    _columns = columns;
    _max_index = getIndex(rows - 1, columns - 1);

    player1_payoffs = new QList<int>;
    player2_payoffs = new QList<int>;

    for(int y=0; y < rows; y++ ) {
        for( int x=0; x < columns; x++ ) {
            player1_payoffs->append(0);
            player2_payoffs->append(0);
        }
    }
}

void Game::setPayoff(int row, int column, int player, int value)
{
    Q_ASSERT(player > 0 && player < 3);

    if ( player == 1 ) {
        player1_payoffs->insert(getIndex(row, column), value);
    } else if ( player == 2 ) {
        player2_payoffs->insert(getIndex(row, column), value);
    }
}

int Game::getPayoff(int row, int column, int player)
{
    Q_ASSERT(player > 0 && player < 3);

    if ( player == 1 ) {
        return player1_payoffs->value(getIndex(row, column), 0);
    } else if ( player == 2 ) {
        return player2_payoffs->value(getIndex(row, column), 0);
    }
}

int Game::getIndex(int row, int column)
{
    Q_ASSERT(row < _rows);
    Q_ASSERT(column < _columns);
    return row * _columns + column;
}
