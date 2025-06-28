#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QObject>

class Worker : public QThread
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
public slots:
    void doWork();  // Start job
signals:
    void requestValue();      // No return (for QueuedConnection)
    void requestValueWithReply(int& result);  // Pass by ref (for BlockingQueuedConnection)
};

#endif // WORKER_H
