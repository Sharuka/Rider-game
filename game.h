#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <rider.h>
#include "score.h"
#include "health.h"
#include <QLabel>
#include <QTimer>
#include "gameover.h"
#include "button.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    \
    void displayMainMenu();

    QGraphicsScene * scene;
    Button* playButton;
    Button* quitButton;
    Rider * rider;
    QLabel * health0;
    QLabel * health1;
    QLabel * health2;
    QLabel * health3;
    Score * score;
    QTimer * timerT ;
    QTimer * timerL;
    QGraphicsTextItem* titleText;
    //Gameover *gameover;

   QLabel *lblGameOver;
    int h=3;


    Health * health;


    void intHealth();


 public slots:

    void startGame();
    void gameover();
};

#endif // GAME_H
