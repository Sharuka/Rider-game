#ifndef POLICE_H
#define POLICE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Police: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Police(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // POLICE_H
