#include "RepeatedPlay.h"
#include "ui_repeatedplay.h"
#include "PrisonerDilema.h"
#include "StrategyInterface.h"
#include "AlwaysDefect.h"
#include "NeverForgive.h"
#include "TitForTat.h"
#include "TitForTwoTat.h"
#include "AlwaysCooperate.h"
#include "RandomStrategy.h"
#include "Pavlov.h"
#include "WSLS.h"
#include "NeverForgiveUnprovoked.h"
#include <QList>
#include "Arena.h"
#include "Game.h"
#include <QInputDialog>
#include <QDebug>
#include "BarGraphWidget.h"

RepeatedPlay::RepeatedPlay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RepeatedPlay)
{
    ui->setupUi(this);

    //connect button
    connect(ui->start_button, SIGNAL(clicked()), this, SLOT(play()));
    connect(ui->infinite_btn, SIGNAL(clicked()), this, SLOT(playInfinite()));

    //Setup Game
    //PLayer 1 payoff
    _game.setPayoff(0,0,1,3);
    _game.setPayoff(0,1,1,1);
    _game.setPayoff(1,0,1,5);
    _game.setPayoff(1,1,1,2);

    //Player 2 payoff
    _game.setPayoff(0,0,2,3);
    _game.setPayoff(0,1,2,5);
    _game.setPayoff(1,0,2,1);
    _game.setPayoff(1,1,2,2);
//    Game *s_game = qobject_cast<Game*>( new PrisonerDilema());

    //Create Strategies
    _strategies.append( qobject_cast<StrategyInterface*>(new AlwaysDefect()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new NeverForgive()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new TitForTat()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new TitForTwoTat()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new AlwaysCooperate()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new RandomStrategy()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new Pavlov()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new WSLS()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new NeverForgiveUnprovoked()) );

}

RepeatedPlay::~RepeatedPlay()
{
    delete ui;
    foreach(StrategyInterface* p1, _strategies) {
        delete p1;
    }
}


void RepeatedPlay::play()
{
    ui->results_list->clear();
    int iterations = QInputDialog::getInteger(this, "Count", "Iterations:", 40, 1, 1000);
    int repetition = QInputDialog::getInteger(this, "Count", "Repetitions:", 5, 1, 1000);
    foreach(StrategyInterface* p1, _strategies) {
        int i=1;
        int sum = 0;
        while ( i <= iterations ) {
            foreach(StrategyInterface* p2, _strategies) {
                Arena arena(&_game, p1, p2);
                arena.run(repetition);
                p1->reset();
                p2->reset();
//                ui->results_list->addItem( QString("%1 vs %2 :: (%3, %4)").arg(p1->getName()).arg(p2->getName()).arg(arena.getScore(1)).arg(arena.getScore(2)) );
                sum += arena.getScore(1);
            }
            i++;
        }
        qreal result = qreal(sum / iterations);
        ui->results_list->addItem( QString("Total for %1 is: %2").arg(p1->getName()).arg(result) );
    }
}

void RepeatedPlay::playInfinite()
{
    ui->results_list->clear();
    int iterations = QInputDialog::getInteger(this, "Count", "Iterations:", 40, 1, 1000);
    double chance = QInputDialog::getDouble(this, "Chance", "Chance:", 0.75, 0.01, 1.00,2);
    foreach(StrategyInterface* p1, _strategies) {
        int i=1;
        qreal sum = 0;
        while ( i <= iterations ) {
            qreal temp_sum = 0;
            foreach(StrategyInterface* p2, _strategies) {
                Arena arena(&_game, p1, p2);
                arena.run( qreal(chance) );
//                ui->results_list->addItem( QString("%1 vs %2 :: (%3, %4)").arg(p1->getName()).arg(p2->getName()).arg(arena.getScore(1)).arg(arena.getScore(2)) );
                temp_sum += arena.getScore(1);
//                qDebug() << p1->getName() << ":" << arena.getScore(1);
//                qDebug() << "Game Score:" << arena.getScore(1);
            }
            sum += temp_sum;// / _strategies.count();
            i++;
        }
        qreal result = qreal(sum / iterations );
        ui->results_list->addItem( QString("Total for %1 is: %2").arg(p1->getName()).arg(result) );
    }
}
