#include <QCoreApplication>
#include "worker.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker t1(1);
    Worker t2(2);

    t1.start();
    t2.start();

    t1.wait();
    t2.wait();

    qDebug() << "Final Counter:" << Worker::sharedCounter;

    return a.exec();
}
