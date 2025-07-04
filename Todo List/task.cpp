#include "task.h"
#include "ui_task.h"
#include <QInputDialog>
#include <QDebug>

Task::Task(QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);

    connect(ui->removeBtn, &QPushButton::clicked, this, [this, name]() {
        qDebug() << "Trying to remove " <<
                    [](const QString& taskName) -> QString {
            return "----------------- " + taskName.toUpper();
        }(name);
        emit removed(this);
    });

    connect(ui->checkBox, &QCheckBox::toggled, this, &Task::checked);

}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString &name)
{
    ui->checkBox->setText(name);
}

QString Task::name() const
{
    return ui->checkBox->text();
}

bool Task::isComplated() const
{
    return ui->checkBox->isChecked();
}

void Task::on_editBtn_clicked()
{
    bool ok;
    QString value = QInputDialog::getText(this,
                                          tr("Edit Task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          this->name(),&ok);
    if(ok && !value.isEmpty())
    {
        setName(value);
    }
}



void Task::checked(bool checked)
{
    QFont font(ui->checkBox->font());
    font.setStrikeOut(checked);
    ui->checkBox->setFont(font);
    emit statusChanged(this);
}

