#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QMutex>

class Worker : public QThread
{
    Q_OBJECT
public:
    explicit Worker(int id, QObject *parent = nullptr);
    static int sharedCounter;     // shared resource
    static QMutex mutex;          // mutex to protect counter

protected:
    void run() override;

private:
    int workerId;
};

#endif // WORKER_H
