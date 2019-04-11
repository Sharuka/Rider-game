#ifndef GAMEOVER_H
#define GAMEOVER_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsScene>


class Gameover: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Gameover(QGraphicsItem * parent=0);




public slots:

private:
    //QMediaPlayer * gameOversound ;



};

#endif // GAMEOVER_H
