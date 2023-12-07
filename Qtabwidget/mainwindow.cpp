#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}


void MainWindow::on_pushButton_clicked()
{
//    ui->tabWidget->addTab(new QWidget(),"Java");
    ui->tabWidget->addTab(new Form(),"Myform");

    //set index current when adding new tab
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

    //add widget name by count
    //ui->tabWidget->addTab(new QWidget(),QString("Tab %0").arg(ui->tabWidget->count()+1;

}

