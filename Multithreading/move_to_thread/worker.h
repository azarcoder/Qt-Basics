#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QObject>

class worker : public QThread
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);
public slots:
    void doWork();  // This will run in the thread
};

#endif // WORKER_H
