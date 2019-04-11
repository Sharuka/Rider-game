#include "rider.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include <QMediaPlayer>

Rider::Rider(QGraphicsItem *parent): QGraphicsPixmapItem(parent){


    //setgraphic



    setPixmap(QPixmap(":/images/images/mybike.png"));
}

void Rider::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() >75)
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x()<430)
        setPos(x()+20,y());
    }


}

void Rider::spawnpolice(){
   //  create an Taxt
   police = new Police();
    scene()->addItem(police);
}





