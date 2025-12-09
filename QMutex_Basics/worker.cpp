#include "worker.h"
#include <QDebug>

int Worker::sharedCounter = 0;
QMutex Worker::mutex;

Worker::Worker(int id, QObject *parent) : QThread(parent), workerId(id)
{

}

void Worker::run()
{
    for (int i = 0; i < 100; ++i)
    {
        mutex.lock();
        ++sharedCounter;  // critical section
        mutex.unlock();
        qDebug() << "worker id : " << workerId;
    }

    qDebug() << "Worker" << workerId << "finished.";
}
