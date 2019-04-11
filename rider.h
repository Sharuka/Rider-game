#ifndef RIDER_H
#define RIDER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <police.h>


class Rider:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Rider(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

    Police * police;



public slots:
    void spawnpolice();




};


#endif // RIDER_H
