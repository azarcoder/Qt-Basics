#include "semworker.h"
#include <QDebug>
#include <QThread>

QSemaphore SemWorker::sem(2); // allow only 2 threads at once

SemWorker::SemWorker(int id, QObject *parent)
    : QThread(parent), workerId(id)
{
}

void SemWorker::run()
{
    qDebug() << "Worker" << workerId << "waiting for permit...";

    sem.acquire();  // try to enter
    qDebug() << "Worker" << workerId << "entered critical section.";

    QThread::sleep(2); // simulate work

    qDebug() << "Worker" << workerId << "leaving.";
    sem.release();  // exit critical section
}
