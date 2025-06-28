// mythread.cpp
#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent)
    : QThread(parent)
{
}

void MyThread::run()
{
    for (int i = 0; i < 5; ++i) {
        qDebug() << "Running in thread:" << QThread::currentThread();
        QThread::sleep(1);  // Simulate heavy work
    }
}
