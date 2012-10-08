#include <QtGui/QApplication>
#include "RepeatedPlay.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RepeatedPlay w;
    w.show();
    
    return a.exec();
}
