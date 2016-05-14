#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTime>
#include <stdlib.h>
#include <QKeyEvent>
#include <QMediaPlayer>

//initial t(time),score
int t=30;
int score=0;
int c=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}
//to start the game
void MainWindow::on_startbutton_clicked()
{
    mysound =new QMediaPlayer();
    mysound->setMedia(QUrl("qrc:/sounds/mysound.mp3"));
    mysound->play();
    //count the time
    starttime();
    //call for girl and boy
    object();
    //move firth background to the where i can't see
    QPoint z(800,0);
    ui->startbutton->move(z);
    ui->endbutton->move(z);
    ui->startgame->move(z);
}
//to end the game
void MainWindow::on_endbutton_clicked()
{
    //close all the game
    this->close();
}
//to restart the game
void MainWindow::restartclicked()
{
    //initial t and score
    t=31;
    score=0;
    mysound =new QMediaPlayer();
    mysound->setMedia(QUrl("qrc:/sounds/mysound.mp3"));
    mysound->play();
    //count the time
    starttime();
    //call for girl and boy
    object();
    //move firth background to the where i can't see
    QPoint z(800,0);
    ui->startbutton->move(z);
    ui->endbutton->move(z);
    ui->startgame->move(z);
}
//to end the game
void MainWindow::endgameclicked()
{
    //close all the game
    this->close();
}
//use timer to call counttime function every second
void MainWindow::starttime()
{
    timer = new QTimer ();
    connect (timer,SIGNAL(timeout()),this,SLOT(counttime()));
    timer->start(1000);
}
//like the drum,call those function to make objects move
void MainWindow::object()
{
    girl1();
    girl2();
    girl1_2();
    boy1();
    boy2();
    boy1_2();
    forevergirl();
}
//move girl label every 0.05sec
void MainWindow::girl1()
{
    xgirl1=(rand()%90)*10+800;
    ygirl1=180;
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(movegirl1()));
    timer2->start(50);
    ui->setupUi(this);
}
//if girl label's position x < -50,label move to x > 800
void MainWindow::movegirl1()
{
    xgirl1=xgirl1-10;
    QPoint z(xgirl1,ygirl1);
    ui->girl1->move(z);
    if(xgirl1<-50)
    {
        xgirl1=(rand()%90)*10+800;
    }
}
//move girl label every 0.05sec
void MainWindow::girl2()
{
    xgirl2=(rand()%90)*10+900;
    ygirl2=180;
    timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(movegirl2()));
    timer3->start(50);
    ui->setupUi(this);
}
//if girl label's position x < -50,label move to x > 900
void MainWindow::movegirl2()
{
    xgirl2=xgirl2-10;
    QPoint z(xgirl2,ygirl2);
    ui->girl2->move(z);
    if(xgirl2<-50)
    {
        xgirl2=(rand()%90)*10+900;
        //when xgirl2==xgirl1,change xgirl2;
        while(xgirl2==xgirl1)
        {
            xgirl2=(rand()%90)*10+900;
        }        
    }
}
//move girl label every 0.05sec
void MainWindow::girl1_2()
{
    xgirl1_2=(rand()%90)*10+1200;
    ygirl1_2=180;
    timer4 = new QTimer(this);
    connect(timer4,SIGNAL(timeout()),this,SLOT(movegirl1_2()));
    timer4->start(50);
    ui->setupUi(this);
}
//if girl label's position x < -50,label move to x > 1200
void MainWindow::movegirl1_2()
{
    xgirl1_2=xgirl1_2-10;
    QPoint z(xgirl1_2,ygirl1_2);
    ui->girl1_2->move(z);
    if(xgirl1_2<-50)
    {        
       xgirl1_2=(rand()%90)*10+1200;
       while(xgirl1_2==xgirl1||xgirl1_2==xgirl2)
       {
           xgirl1_2=(rand()%90)*10+1200;
       }
    }
}
//move boy label every 0.05sec
void MainWindow::boy1()
{
    xboy1=(rand()%90)*10+1000;
    yboy1=180;
    timer5 = new QTimer(this);
    connect(timer5,SIGNAL(timeout()),this,SLOT(moveboy1()));
    timer5->start(50);
    ui->setupUi(this);
}
//if boy label's position x < -50,label move to x > 1000
void MainWindow::moveboy1()
{
    xboy1=xboy1-10;
    QPoint z(xboy1,yboy1);
    ui->boy1->move(z);
    if(xboy1<-50)
    {
        xboy1=(rand()%90)*10+1000;
        while(xboy1==xgirl1||xboy1==xgirl2||xboy1==xgirl1_2)
        {
            xboy1=(rand()%90)*10+1000;
        }
    }
}
//move boy label every 0.05sec
void MainWindow::boy2()
{
    xboy2=(rand()%90)*10+1100;
    yboy2=180;
    timer6 = new QTimer(this);
    connect(timer6,SIGNAL(timeout()),this,SLOT(moveboy2()));
    timer6->start(50);
    ui->setupUi(this);
}
//if boy label's position x < -50,label move to x > 1100
void MainWindow::moveboy2()
{
    xboy2=xboy2-10;
    QPoint z(xboy2,yboy2);
    ui->boy2->move(z);
    if(xboy2<-50)
    {
        xboy2=(rand()%90)*10+1100;
        while(xboy2==xgirl1||xboy2==xgirl2||xboy2==xgirl1_2||xboy2==xboy1)
        {
            xboy2=(rand()%90)*10+1100;
        }
    }
}
//move boy label every 0.05sec
void MainWindow::boy1_2()
{
    xboy1_2=(rand()%90)*10+1300;
    yboy1_2=180;
    timer7 = new QTimer(this);
    connect(timer7,SIGNAL(timeout()),this,SLOT(moveboy1_2()));
    timer7->start(50);
    ui->setupUi(this);
}
//if boy label's position x < -50,label move to x > 1300
void MainWindow::moveboy1_2()
{
    xboy1_2=xboy1_2-10;
    QPoint z(xboy1_2,yboy1_2);
    ui->boy1_2->move(z);
    if(xboy1_2<-50)
    {
        xboy1_2=(rand()%90)*10+1300;
        while(xboy1_2==xgirl1||xboy1_2==xgirl2||xboy1_2==xgirl1_2||xboy1_2==xboy1||xboy1_2==xboy2)
        {
            xboy1_2=(rand()%90)*10+1300;
        }
    }
}
//count the time and move the object i don't need and stop the object and the time
//show the pushbutton ,when click the button ,call the function i click
void MainWindow::counttime()
{
    t=t-1;
    ui-> mytime ->setText(QString::number(t));
    QPoint z(800,0);
    if(t==0)
    {
        ui->girl1->move(z);
        timer2->stop();    
        ui->girl2->move(z);
        timer3->stop();
        ui->girl1_2->move(z);
        timer4->stop();
        ui->boy1->move(z);
        timer5->stop();
        ui->boy2->move(z);
        timer6->stop();
        ui->boy1_2->move(z);
        timer7->stop();
        ui->drum->move(z);
        ui->button1->move(z);
        ui->button2->move(z);
        ui->s1->move(z);
        ui->s2->move(z);
        ui->k1->move(z);
        ui->k2->move(z);
        ui->space1->move(z);
        ui->space2->move(z);
        ui->playdrum->move(z);
        ui->smallgirl->move(z);
        ui->blue->move(z);
        ui->forevergirl->move(z);
        ui->good->move(z);
        ui->great->move(z);
        ui->hithit->move(z);
        timer->stop();
        timer13->stop();
        mysound->stop();
        connect(ui->restart,SIGNAL(clicked()),this,SLOT(restartclicked()));
        connect(ui->endgame,SIGNAL(clicked()),this,SLOT(endgameclicked()));
    }
}
void MainWindow::forevergirl()
{
    xforevergirl=4400;
    yforevergirl=150;
    timer13 = new QTimer(this);
    connect(timer13,SIGNAL(timeout()),this,SLOT(moveforevergirl()));
    timer13->start(50);
    ui->setupUi(this);
}

void MainWindow::moveforevergirl()
{
    xforevergirl=xforevergirl-10;
    QPoint z(xforevergirl,yforevergirl);
    ui->blue->move(z);
    ui->forevergirl->move(z);
    if(xforevergirl<=150&&xforevergirl>-150)
    {
        ui->hithit->move(QPoint(150,0));
    }
    if(xforevergirl==150)
    {
        ui->hithit->move(QPoint(800,0));
    }
}

//calculate the score
void MainWindow::keyPressEvent(QKeyEvent*event)
{
    //當時間>0可以執行下列動作
    if(t>0)
    {
        //按下s後會做的動作
        if(event->key()== Qt::Key_S)
        {
            //發出鼓聲
            QMediaPlayer *mysound =new QMediaPlayer();
            mysound->setMedia(QUrl("qrc:/sounds/don.mp3"));
            mysound->play();
            int drum=30;
            int num=0;
            //顯示大寫s ,表示按s按鍵
            ui->s1->move(QPoint(-50,280));
            //當在60和10之間的範圍按下按鍵
            if(xgirl1<61&&xgirl1>9)
            {
                //分數+1
                score=score+1;
                ui->score->setText(QString::number(score));
                //顯示有吃到的圖
                ui->button1->move(QPoint(-150,250));
                //在40和20之間的範圍按下按鍵
                if(xgirl1<=40&&xgirl1>=20)
                {
                   //分數再+1
                   score=score+1;
                   num=1;
                   ui->score->setText(QString::number(score));
                }
                //在30按下按鍵
                if(drum==xgirl1)
                {
                    xsmallgirl=180;
                    //分數再+2
                    score=score+2;
                    ui->score->setText(QString::number(score));
                    //顯示小初音
                    timer12 = new QTimer(this);
                    connect(timer12,SIGNAL(timeout()),this,SLOT(movesmallgirl()));
                    timer12->start(100);
                }
                if(num==0)
                {
                    ui->good->move(QPoint(100,250));
                }
                if(num==1)
                {
                    ui->great->move(QPoint(100,250));
                }
                //移動girl(消除)
                xgirl1=(rand()%90)*10+800;
            }
            else if(xgirl2<61&&xgirl2>9)
            {
                score=score+1;
                ui->score->setText(QString::number(score));
                ui->button1->move(QPoint(-150,150));
                if(xgirl2<=40&&xgirl2>=20)
                {
                   //分數再+1
                   score=score+1;
                   num=1;
                   ui->score->setText(QString::number(score));
                }
                if(drum==xgirl2)
                {
                    xsmallgirl=180;
                    score=score+2;
                    ui->score->setText(QString::number(score));
                    timer12 = new QTimer(this);
                    connect(timer12,SIGNAL(timeout()),this,SLOT(movesmallgirl()));
                    timer12->start(100);
                }
                if(num==0)
                {
                    ui->good->move(QPoint(100,250));
                }
                if(num==1)
                {
                    ui->great->move(QPoint(100,250));
                }
                xgirl2=(rand()%90)*10+900;
            }
            else if(xgirl1_2<61&&xgirl1_2>9)
            {
                score=score+1;
                ui->score->setText(QString::number(score));                
                ui->button1->move(QPoint(-150,150));
                if(xgirl1_2<=40&&xgirl1_2>=20)
                {
                   //分數再+1
                   score=score+1;
                   num=1;
                   ui->score->setText(QString::number(score));
                }
                if(drum==xgirl1_2)
                {
                    xsmallgirl=180;
                    score=score+2;
                    ui->score->setText(QString::number(score));
                    timer12 = new QTimer(this);
                    connect(timer12,SIGNAL(timeout()),this,SLOT(movesmallgirl()));
                    timer12->start(100);
                }
                if(num==0)
                {
                    ui->good->move(QPoint(100,250));
                }
                if(num==1)
                {
                    ui->great->move(QPoint(100,250));
                }
                xgirl1_2=(rand()%90)*10+1200;
            }
            QTimer *timer8 = new QTimer(this);
            connect(timer8,SIGNAL(timeout()),this,SLOT(movethebutton()));
            timer8->setSingleShot(true);
            timer8->start(125);
            QTimer *timer11 = new QTimer(this);
            connect(timer11,SIGNAL(timeout()),this,SLOT(movethebutton4()));
            timer11->setSingleShot(true);
            timer11->start(75);
            QTimer *timer13 = new QTimer(this);
            connect(timer13,SIGNAL(timeout()),this,SLOT(movethebutton5()));
            timer13->setSingleShot(true);
            timer13->start(75);

        }
        else if(event->key()== Qt::Key_K)
        {
            QMediaPlayer *mysound =new QMediaPlayer();
            mysound->setMedia(QUrl("qrc:/sounds/don.mp3"));
            mysound->play();
            int drum2=30;
            int num=0;
            ui->k1->move(QPoint(-50,280));
            if(xboy1<61&&xboy1>9)
            {
                 score=score+1;
                 ui->score->setText(QString::number(score));                 
                 ui->button1->move(QPoint(-150,250));
                 if(xboy1<=40&&xboy1>=20)
                 {
                    //分數再+1
                    score=score+1;
                    num=1;
                    ui->score->setText(QString::number(score));
                 }
                 if(drum2==xboy1)
                 {
                     xsmallgirl=180;
                     score=score+2;
                     ui->score->setText(QString::number(score));
                     timer12 = new QTimer(this);
                     connect(timer12,SIGNAL(timeout()),this,SLOT(movesmallgirl()));
                     timer12->start(100);
                 }
                 if(num==0)
                 {
                     ui->good->move(QPoint(100,250));
                 }
                 if(num==1)
                 {
                     ui->great->move(QPoint(100,250));
                 }
                 xboy1=(rand()%90)*10+1000;
            }
            else if(xboy2<61&&xboy2>19)
            {
                 score=score+1;
                 ui->score->setText(QString::number(score));                 
                 ui->button1->move(QPoint(-150,250));
                 if(xboy2<=40&&xboy2>=20)
                 {
                    //分數再+1
                    score=score+1;
                    num=1;
                    ui->score->setText(QString::number(score));
                 }
                 if(drum2==xboy2)
                 {
                     xsmallgirl=180;
                     score=score+2;
                     ui->score->setText(QString::number(score));
                     timer12 = new QTimer(this);
                     connect(timer12,SIGNAL(timeout()),this,SLOT(movesmallgirl()));
                     timer12->start(100);
                 }
                 if(num==0)
                 {
                     ui->good->move(QPoint(100,250));
                 }
                 if(num==1)
                 {
                     ui->great->move(QPoint(100,250));
                 }
                 xboy2=(rand()%90)*10+1100;
            }
            else if(xboy1_2<61&&xboy1_2>9)
            {
                 score=score+1;
                 ui->score->setText(QString::number(score));
                 ui->button1->move(QPoint(-150,250));
                 if(xboy1_2<=40&&xboy1_2>=20)
                 {
                     //分數再+1
                     score=score+1;
                     num=1;
                     ui->score->setText(QString::number(score));
                 }
                 if(drum2==xboy1_2)
                 {
                     xsmallgirl=180;
                     score=score+2;
                     ui->score->setText(QString::number(score));
                     timer12 = new QTimer(this);
                     connect(timer12,SIGNAL(timeout()),this,SLOT(movesmallgirl()));
                     timer12->start(100);
                 }
                 if(num==0)
                 {
                     ui->good->move(QPoint(100,250));
                 }
                 if(num==1)
                 {
                     ui->great->move(QPoint(100,250));
                 }
                 xboy1_2=(rand()%90)*10+1300;
            }
            QTimer *timer8 = new QTimer(this);
            connect(timer8,SIGNAL(timeout()),this,SLOT(movethebutton()));
            timer8->setSingleShot(true);
            timer8->start(125);
            QTimer *timer11 = new QTimer(this);
            connect(timer11,SIGNAL(timeout()),this,SLOT(movethebutton3()));
            timer11->setSingleShot(true);
            timer11->start(75);
            QTimer *timer13 = new QTimer(this);
            connect(timer13,SIGNAL(timeout()),this,SLOT(movethebutton5()));
            timer13->setSingleShot(true);
            timer13->start(125);
        }
        else if(event->key()== Qt::Key_Space)
        {
            QMediaPlayer *mysound =new QMediaPlayer();
            mysound->setMedia(QUrl("qrc:/sounds/don.mp3"));
            mysound->play();
            ui->space1->move(QPoint(-200,280));
            if(xforevergirl<61&&xforevergirl>-600)
            {
                score=score+1;
                ui->score->setText(QString::number(score));
                ui->button1->move(QPoint(-150,150));
            }
            QTimer *timer8 = new QTimer(this);
            connect(timer8,SIGNAL(timeout()),this,SLOT(movethebutton()));
            timer8->setSingleShot(true);
            timer8->start(75);
            QTimer *timer11 = new QTimer(this);
            connect(timer11,SIGNAL(timeout()),this,SLOT(movethebutton2()));
            timer11->setSingleShot(true);
            timer11->start(75);
        }
    }
}
//小初音
void MainWindow::movesmallgirl()
{
    c=c+1;
    xsmallgirl=xsmallgirl+20;
    if(c%2==0)
    {
      ysmallgirl=100;
    }
    if(c%2==1)
    {
      ysmallgirl=80;
    }
    QPoint z(xsmallgirl,ysmallgirl);
    ui->smallgirl->move(z);
    if(xsmallgirl>=800)
    {
       timer12->stop();      
    }
}
void MainWindow::movethebutton5()
{
    if(t>0)
    {
        ui->great->move(QPoint(-50,250));
        ui->good->move(QPoint(-50,250));
    }
}
//s
void MainWindow::movethebutton4()
{
    if(t>0)
    {
        ui->s1->move(QPoint(210,280));
    }
}
//k
void MainWindow::movethebutton3()
{
    if(t>0)
    {
        ui->k1->move(QPoint(270,280));
    }
}
//space
void MainWindow::movethebutton2()
{
    if(t>0)
    {
        ui->space1->move(QPoint(330,280));
    }
}
//button
void MainWindow::movethebutton()
{
    if(t>0)
    {
        ui->button1->move(QPoint(0,150));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
