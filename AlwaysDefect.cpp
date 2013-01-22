#include "AlwaysDefect.h"

AlwaysDefect::AlwaysDefect()
{
}

int AlwaysDefect::getAction(Game *game, PlayHist *history, int player)
{
    //No matter what we return action 1
    return 1;
}

QString AlwaysDefect::getName()
{
    return "AD";
}
