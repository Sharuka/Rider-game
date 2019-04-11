#include "gameover.h"
#include <QGraphicsScene>
#include <QKeyEvent>


Gameover::Gameover(QGraphicsItem *parent): QGraphicsPixmapItem(parent){


    setPixmap(QPixmap("::/images/images/gameover.png"));

    setPos(110,100);
}
