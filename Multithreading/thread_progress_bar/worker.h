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
    void doWork();  // Slot to start work

signals:
    void progress(int value);  // Signal to send progress
    void finished();           // Signal when done
};


#endif // WORKER_H
