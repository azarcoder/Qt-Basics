#include <QCoreApplication>
#include "semworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SemWorker w1(1), w2(2), w3(3), w4(4), w5(5);

    w1.start();
    w2.start();
    w3.start();
    w4.start();
    w5.start();

    w1.wait();
    w2.wait();
    w3.wait();
    w4.wait();
    w5.wait();

    return a.exec();
}
