// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread = new MyThread(this);
    thread->start(); // This calls run() in a new thread
}

MainWindow::~MainWindow()
{
    thread->quit();
    thread->wait();
    delete ui;
}
