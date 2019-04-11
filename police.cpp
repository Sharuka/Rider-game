#include "police.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
#include <typeinfo>

extern Game * game;

Police::Police(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 4;


    if(random_number==0)
    {
         setPos(35.25,0);

    }
    if(random_number==1)
    {
         setPos(160.75,0);
    }
    if(random_number==2)
    {
         setPos(330.25,0);
    }
    if(random_number==3)
    {
         setPos(443.75,0);
    }




    // drew the rect
    setPixmap(QPixmap(":/images/images/police.png"));
    setTransformOriginPoint(50,50);
        setRotation(180);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(20);
}

void Police::move(){




    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();


    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Rider)){


            // increase the score

            game->health->decrease();




            // remove them from the scene (still on the heap)


            scene()->removeItem(this);



            // delete them from the heap to save memory

            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }




    // move enemy down
    setPos(x(),y()+20);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 1000){
        //decrease the health
       game->score->increase();

        scene()->removeItem(this);
        delete this;
    }
}
