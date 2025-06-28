#include "worker.h"

Worker::Worker(QObject *parent) : QThread(parent)
{

}

void Worker::doWork()
{
    for (int i = 0; i <= 100; ++i) {
        QThread::sleep(1);  // Simulate long task (1 sec per step)
        emit progress(i);   // Send progress
    }
    emit finished();        // Done
}
