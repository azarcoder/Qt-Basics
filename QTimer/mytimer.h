#ifndef MYTIMER_H
#define MYTIMER_H
#include <QtCore>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    QTimer *timer;
private slots:
    void Myslot();
};

#endif // MYTIMER_H
