#include "mainwindow.h"

#include <QApplication>
#include <QTimer>

void mytime();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}

