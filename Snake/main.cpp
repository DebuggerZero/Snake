#include "Game/GameView/gstartwidght.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GStartWidght w;
    w.show();
    return a.exec();
}
