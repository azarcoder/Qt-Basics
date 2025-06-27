#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->listWidget->addItem("my item");

    QListWidgetItem *listItem = new QListWidgetItem;
    listItem->setText("my data");
    listItem->setData(100, 1000);//like 100 is a like a key and 1000 is actual data.
    ui->listWidget->addItem(listItem);
    qDebug() << listItem->data(100);

    QTreeWidgetItem *treeItem = new QTreeWidgetItem;
    treeItem->setText(0, "My test item");
    ui->treeWidget->addTopLevelItem(treeItem);

    QTreeWidgetItem *treeItem2 = new QTreeWidgetItem;
    treeItem2->setText(0, "My test item");
    treeItem->addChild(treeItem2);

    QTableWidgetItem *tableItem = new QTableWidgetItem;
    tableItem->setText("testing 1");
    ui->tableWidget->setItem(0, 0, tableItem);

    QTableWidgetItem *tableItem2 = new QTableWidgetItem;
    tableItem2->setText("testing 2");
    ui->tableWidget->setItem(1, 2, tableItem2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Question dialog");
    msgBox.setText("Shall we continue this?");
    QPushButton *yesBtn =  msgBox.addButton("Seriously Yes!", QMessageBox::YesRole);
     QPushButton *noBtn = msgBox.addButton("Well no thanks!", QMessageBox::NoRole);
    QPixmap myIcon(":/images/icon/icon contact.png");
    QPixmap scaledIcon = myIcon.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    msgBox.setIconPixmap(scaledIcon);
    msgBox.exec();

    if(msgBox.clickedButton() == (QAbstractButton*) yesBtn)
    {
        QMessageBox::information(this, "info", "yes clicked!");
    }
    else if(msgBox.clickedButton() == (QAbstractButton*) noBtn)
    {
        QMessageBox::information(this, "info", "no clicked!");
    }

}

