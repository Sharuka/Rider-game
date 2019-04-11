#include "line.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "game.h"

extern Game * game;

Line::Line(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position

         setPos(510,-50);



    // drew the rect
    setPixmap(QPixmap(":/res/images/images/grassline.png"));
    setTransformOriginPoint(50,50);
        setRotation(180);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(100);
}

void Line::move(){
    // move enemy down
    setPos(x(),y()+20);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 2000){
        //decrease the health
        //game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
