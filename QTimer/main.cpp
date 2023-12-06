#include "mainwindow.h"
#include "mytimer.h"
//#include <QApplication>
#include<QtCore>
#include<QCoreApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
      QCoreApplication a(argc,argv);
//    MainWindow w;
//    w.show();
        MyTimer timer;
    return a.exec();
}
