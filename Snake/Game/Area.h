#ifndef AREA_H
#define AREA_H

#include <QVector>
#include "Snake.h"
#include "Food.h"
#include "Utility/utility.h"
#include "Archive/archive.h"

class Area
{
public:
    Area();

    ~Area();

    static const int WIDTH = 30;
    static const int HEIGHT = 30;

    Utility::Direction direction;

    QVector<QVector<int>> gameMap;

    void initGame();

    bool gameOver();

    void createFood();

    int getScore();

    int getBestScore();

private:
    Utility _utility;

    Archive _archive;

    Snake *snake = new Snake();

    Food *food = new Food();
};

#endif // AREA_H
