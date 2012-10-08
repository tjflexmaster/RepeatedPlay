#include "PrisonerDilema.h"
#include <QDebug>

PrisonerDilema::PrisonerDilema() : Game(2,2)
{
    //PLayer 1 payoff
    setPayoff(0,0,1,3);
    setPayoff(0,1,1,1);
    setPayoff(1,0,1,5);
    setPayoff(1,1,1,2);

    //Player 2 payoff
    setPayoff(0,0,2,3);
    setPayoff(0,1,2,5);
    setPayoff(1,0,2,1);
    setPayoff(1,1,2,2);

}
