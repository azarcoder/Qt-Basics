#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QInputDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &Widget::addTask);
    m_Tasks = QVector<Task*>();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add Task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"),&ok);
    if(ok && !name.isEmpty())
    {
        qDebug() << "Add new task";
        Task* task = new Task(name);
        connect(task, &Task::removed, this, &Widget::removeTask);
        connect(task, &Task::statusChanged, this, &Widget::taskStatusChanged);
        m_Tasks.append(task);
        ui->tasklayout->addWidget(task);
        updateStatus();
    }

}

void Widget::removeTask(Task *task)
{
    m_Tasks.removeOne(task);
    ui->tasklayout->removeWidget(task);
    delete task;
    updateStatus();
}

void Widget::taskStatusChanged(Task *task)
{
    updateStatus();
}

void Widget::updateStatus()
{
    int completedCount = 0;
    for(auto t : m_Tasks)
    {
        if(t->isComplated())
            completedCount++;
    }
    int todoCount = m_Tasks.size() - completedCount;
    ui->statusLabel->setText(QString("Status : %1 todo / %2 completed").arg(todoCount).arg(completedCount));
}


