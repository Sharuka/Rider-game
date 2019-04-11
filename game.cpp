#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include "gameover.h"
#include <QGraphicsScene>
#include "button.h"
#include <QBrush>
#include <QMediaPlayer>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,900); // make the scene 800x600 instead of infinity by infinity (default)
       setBackgroundBrush(QBrush(QImage(":/images/images/road.jpg")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,900);


 show();
}

void Game::startGame(){
    // create the player

    rider =new Rider();

   // player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    rider->setPos(463.75,550); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    rider->setFlag(QGraphicsItem::ItemIsFocusable);
    rider->setFocus();
    // add the player to the scene

    // create the score/health
    score = new Score();
    scene->addItem(score);

    score->setPos(score->x()+0,score->y()+50);

    health = new Health();

    connect(this->health,SIGNAL(crashed()),this,SLOT(gameover()));



    //health->setPos(health->x(),health->y()+25);
    //scene->addItem(health);
     scene->addItem(rider);




    timerT = new QTimer();
    QObject::connect(timerT,SIGNAL(timeout()),rider,SLOT(spawnpolice()));
    timerT->start(2000);

    intHealth();

     //play background music
   QMediaPlayer * music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/sounds/sound/sound.mp3"));
   music->play();


    scene->removeItem(playButton);
    scene->removeItem(quitButton);
    scene->removeItem(titleText);

}




void Game::displayMainMenu(){

    titleText = new QGraphicsTextItem(QString("Ghost Rider"));
    QFont titleFont("agency fb",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);


    // create the play button
    playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(startGame()));
    scene->addItem(playButton);

    // create the quit button
    quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);


}

void Game::intHealth()
{

    health0=new QLabel(this);
    health1=new QLabel(this);
    health2=new QLabel(this);
    health3=new QLabel(this);

    QPixmap playpix0(":/images/images/life0.png");
    QPixmap playpix1(":/images/images/life1.png");
    QPixmap playpix2(":/images/images/life2.png");
    QPixmap playpix3(":/images/images/life3.png");

    health0->setPixmap(playpix0);
    health1->setPixmap(playpix1);
    health2->setPixmap(playpix2);
    health3->setPixmap(playpix3);

    health0->setVisible(false);
    health1->setVisible(false);
    health2->setVisible(false);
    health3->setVisible(true);





}

void Game::gameover()
{


    h=h-1;

    if(h==2)
    {
        health2->setVisible(true);
        health3->setVisible(false);
    }
    if(h==1)
    {
        health1->setVisible(true);
        health2->setVisible(false);
    }
    if(h==0)
    {
        health0->setVisible(true);
        health1->setVisible(false);

        //lblGameOver->setVisible(true);

        Gameover *  gameover = new Gameover();
        scene->addItem(gameover);

        timerT->stop();
        timerL->stop();





        scene->removeItem(rider);



    }




}
