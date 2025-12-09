#ifndef SEMWORKER_H
#define SEMWORKER_H

#include <QThread>
#include <QSemaphore>

class SemWorker : public QThread
{
    Q_OBJECT

public:
    SemWorker(int id, QObject *parent = nullptr);

    static QSemaphore sem;   // semaphore shared by all threads

protected:
    void run() override;

private:
    int workerId;
};

#endif // SEMWORKER_H
