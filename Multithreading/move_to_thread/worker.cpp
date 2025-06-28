#include "worker.h"
#include <QDebug>
worker::worker(QObject *parent) : QThread(parent)
{

}

void worker::doWork()
{
    for (int i = 0; i < 5; ++i) {
        qDebug() << "Worker is working in thread:" << QThread::currentThread();
        QThread::sleep(1);
    }
}
