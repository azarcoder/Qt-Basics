/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *removeBtn;
    QPushButton *editBtn;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName(QString::fromUtf8("Task"));
        Task->resize(502, 43);
        verticalLayout = new QVBoxLayout(Task);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        removeBtn = new QPushButton(Task);
        removeBtn->setObjectName(QString::fromUtf8("removeBtn"));

        gridLayout->addWidget(removeBtn, 0, 3, 1, 1);

        editBtn = new QPushButton(Task);
        editBtn->setObjectName(QString::fromUtf8("editBtn"));

        gridLayout->addWidget(editBtn, 0, 2, 1, 1);

        checkBox = new QCheckBox(Task);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QDialog *Task)
    {
        Task->setWindowTitle(QApplication::translate("Task", "Dialog", nullptr));
        removeBtn->setText(QApplication::translate("Task", "Remove", nullptr));
        editBtn->setText(QApplication::translate("Task", "Edit", nullptr));
        checkBox->setText(QApplication::translate("Task", "Buy Milk", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
