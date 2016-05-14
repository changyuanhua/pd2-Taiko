#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void starttime();
    void keyPressEvent(QKeyEvent*event);
private:
    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    QTimer *timer6;
    QTimer *timer7;
    QTimer *timer9;
    QTimer *timer10;
    QTimer *timer12;
    QTimer *timer13;
    QMediaPlayer *mysound;
    QMediaPlayer *mysound2;
    Ui::MainWindow *ui;
    int xgirl1=800,ygirl1,xgirl2=800,ygirl2,xgirl1_2=800,ygirl1_2,xboy1=800,yboy1,xboy2=800,yboy2,xboy1_2=800,yboy1_2,xsmallgirl=180,ysmallgirl=100,xforevergirl=4400,yforevergirl,mytime;
public slots:
    void girl1();
    void girl1_2();
    void girl2();
    void boy1();
    void boy1_2();
    void boy2();
    void forevergirl();
    void movegirl1();
    void movegirl1_2();
    void movegirl2();
    void moveboy1();
    void moveboy1_2();
    void moveboy2();
    void movesmallgirl();
    void moveforevergirl();
    void object();
    void counttime();
    void restartclicked();
    void endgameclicked();
    void movethebutton2();
    void movethebutton3();
    void movethebutton4();
    void movethebutton();
private slots:
    void on_startbutton_clicked();
    void on_endbutton_clicked();
};

#endif // MAINWINDOW_H
