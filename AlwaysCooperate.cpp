#include "AlwaysCooperate.h"

AlwaysCooperate::AlwaysCooperate()
{
}

int AlwaysCooperate::getAction(Game *game, PlayHist *history, int player)
{
    return 0;
}

QString AlwaysCooperate::getName()
{
    return "Always Cooperate";
}
