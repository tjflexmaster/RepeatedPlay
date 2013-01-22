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
#include "Cheater.h"
#include <qmath.h>
#include <QFile>
#include <QTextStream>

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

    //Create Strategies
    _strategies.append( qobject_cast<StrategyInterface*>(new AlwaysDefect()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new RandomStrategy()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new AlwaysCooperate()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new TitForTat()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new TitForTwoTat()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new Pavlov()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new WSLS()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new NeverForgive()) );
//    _strategies.append( qobject_cast<StrategyInterface*>(new NeverForgiveUnprovoked()) );
    _strategies.append( qobject_cast<StrategyInterface*>(new Cheater()));

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
        int sum = 0;
        qreal variance_sum = 0;

        foreach(StrategyInterface* p2, _strategies) {

            if ( p1 == p2 )
                continue;
            qreal temp_sum = 0;
            qreal temp_variance = 0;
            int i=1;
            while ( i <= iterations ) {
                Arena arena(&_game, p1, p2);
                arena.run(repetition);
                p1->reset();
                p2->reset();

                temp_sum += arena.getScore(1);
                temp_variance += qPow(arena.getScore(1), 2);
                i++;
            }
            qreal result = (qreal) temp_sum / (qreal) iterations;
            qreal variance = (temp_variance / (qreal) iterations) - qPow( result, 2);
            ui->results_list->addItem( QString("%1 vs %2 :: (%3, %4)").arg(p1->getName()).arg(p2->getName()).arg(result).arg(variance) );

            sum += result;
            variance_sum += qPow(result, 2);
        }


        qreal result = (qreal) sum / (qreal) (_strategies.count() - 1);
        qreal variance = (variance_sum / (qreal) (_strategies.count() - 1)) - qPow( result, 2);
        ui->results_list->addItem( QString("Average Total for %1 is: %2").arg(p1->getName()).arg(result) );
        ui->results_list->addItem( QString("Variance for %1 is: %2").arg(p1->getName()).arg(variance));
    }
}

void RepeatedPlay::playInfinite()
{
    ui->results_list->clear();
    int iterations = QInputDialog::getInteger(this, "Count", "Iterations:", 40, 1, 1000);
    double chance = QInputDialog::getDouble(this, "Chance", "Chance:", 0.75, 0.01, 1.00,2);
    QFile file("C://Users//TJ-Asus//Documents//repeated_play.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    QList<QString> test;

    foreach(StrategyInterface* p1, _strategies) {

        qreal sum = 0;
        qreal variance_sum = 0;
        qreal round = 0;
        out << QString("\\textbf{%1} ").arg(p1->getName());
            foreach(StrategyInterface* p2, _strategies) {
                if ( p1 == p2 ) {
                    out << " & -";
                    continue;
                }

                int i=0;
                qreal temp_sum = 0;
                qreal temp_variance = 0;
                int temp_rounds = 0;
                while ( i < iterations ) {

                    Arena arena(&_game, p1, p2);
                    arena.run( qreal(chance) );

//                    if ( p1->getName() == "Custom" && p2->getName() == "PV")
//                        qDebug() << arena.getScore(1) << " " << arena.getRepetitions();
                    temp_sum += arena.getScore(1);
                    temp_variance += qPow(arena.getScore(1), 2);
                    temp_rounds += arena.getRepetitions();
                    p1->reset();
                    p2->reset();
                    i++;
                }
                round += temp_rounds / (qreal) iterations;
                qreal result = temp_sum / (qreal) iterations;
                qreal variance = (temp_variance / (qreal) iterations) - qPow( result, 2);
                sum += result;
                variance_sum += qPow(result, 2);
                ui->results_list->addItem( QString("%1 vs %2 :: (%3)").arg(p1->getName()).arg(p2->getName()).arg(result) );
                out << QString(" & %1").arg(QString::number( result, 'f', 3 ) );
            }
            out << "\\\\\n \\hline\n";

        qreal round_avg = round / (qreal) _strategies.count() ;
        qreal result = (qreal) sum / (qreal) _strategies.count() ;
        qreal variance = (variance_sum / (qreal) _strategies.count() ) - qPow(result,2);
        ui->results_list->addItem( QString("Total for %1 is: %2").arg(p1->getName()).arg(result) );

        test.append(QString("\\textbf{%1} & %2 & %3 & %4 \\\\ \n \\hline \n").arg(p1->getName()).arg(QString::number( result, 'f', 3 )).arg(QString::number( variance, 'f', 3 )).arg(QString::number( round_avg, 'f', 3 )));

    }

    out << "\n\n";

    foreach(QString i, test) {
        out << i;
    }

    out << "\n\n testing";
    file.close();
}
