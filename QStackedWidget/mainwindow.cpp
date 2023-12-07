#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(pagewidget2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pagewidget1()
{
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(pagewidget2()));
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::pagewidget2()
{
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(pagewidget1()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(pagewidget3()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void MainWindow::pagewidget3()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(pagewidget2()));
}

