#include "worker.h"
#include <QDebug>
#include <QThread>
Worker::Worker(QObject *parent) : QThread(parent)
{

}
/*
One worker thread does work.

It asks the main GUI thread for a value.

In one case, it uses QueuedConnection (non-blocking).

In another, it uses BlockingQueuedConnection (blocking the worker until GUI replies).
*/

void Worker::doWork()
{
    qDebug() << "Worker thread:" << QThread::currentThread();

    // QueuedConnection: Fire and forget
    emit requestValue();
    qDebug() << "Worker: Done with QueuedConnection";

    // BlockingQueuedConnection: Wait for reply
    int value = -1;
    emit requestValueWithReply(value);
    qDebug() << "Worker: Got value with BlockingQueuedConnection =" << value;
}
