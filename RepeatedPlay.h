#ifndef REPEATEDPLAY_H
#define REPEATEDPLAY_H

#include "Game.h"
#include "Arena.h"
#include <QList>
#include "StrategyInterface.h"
#include <QMainWindow>

namespace Ui {
class RepeatedPlay;
}

class RepeatedPlay : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RepeatedPlay(QWidget *parent = 0);
    ~RepeatedPlay();

private slots:
    void play();
    void playInfinite();
    
private:
    Ui::RepeatedPlay *ui;

    Game _game;
    QList<StrategyInterface*> _strategies;

};

#endif // REPEATEDPLAY_H
