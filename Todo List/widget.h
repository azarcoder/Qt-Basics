#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void addTask();
    void removeTask(Task *task);
    void taskStatusChanged(Task *task);

private:
    Ui::Widget *ui;
    QVector<Task*> m_Tasks;
    void updateStatus();

};
#endif // WIDGET_H
