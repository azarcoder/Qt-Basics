#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QDebug>
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::fromM2()
{
    qDebug() << "Hi i am from Mainwindow 2";
}
