#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "mainwindow2.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setObjectName("gg");
//    connect(this, SIGNAL(right()),this, SLOT(ss1()));
    connect(this, SIGNAL(wrong()),this, SLOT(ss2()));

    //creating obj for mainwindow2
    MainWindow2 *m2 = new MainWindow2;
    connect(this,SIGNAL(right()),m2,SLOT(fromM2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    emit right();
}
void MainWindow::ss1()
{
    qDebug() << "right emitted";
}
void MainWindow::ss2()
{
    qDebug() << "wrong emitted";
}


void MainWindow::on_pushButton_2_clicked()
{
    emit wrong();
}

