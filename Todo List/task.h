#ifndef TASK_H
#define TASK_H

#include <QDialog>

namespace Ui {
class Task;
}

class Task : public QDialog
{
    Q_OBJECT

public:
    explicit Task(QString name, QWidget *parent = nullptr);
    ~Task();

    void setName(const QString &name);
    QString name() const;
    bool isComplated() const;

signals:
    void removed(Task* task);
    void statusChanged(Task *task);


private slots:
    void on_editBtn_clicked();
    void checked(bool checked);

private:
    Ui::Task *ui;
};

#endif // TASK_H
