#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList() << "column 1" << "column 2");
    Addroot1("name","city");
    Addroot2("name","age");
    Addroot3("name","salary");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Addroot1(QString name, QString description)
{
    QTreeWidgetItem *p = new QTreeWidgetItem(ui->treeWidget);
    p->setText(0,name);
    p->setText(1,description);
    Addchild(p,"azar","trichy");
}
void MainWindow::Addroot2(QString name, QString description)
{
    QTreeWidgetItem *p = new QTreeWidgetItem(ui->treeWidget);
    p->setText(0,name);
    p->setText(1,description);
    Addchild(p,"azar","21");
}
void MainWindow::Addroot3(QString name, QString description)
{
    QTreeWidgetItem *p = new QTreeWidgetItem(ui->treeWidget);
    p->setText(0,name);
    p->setText(1,description);
    Addchild(p,"azar","50000");
}
void MainWindow::Addchild(QTreeWidgetItem *parent, QString name, QString description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,description);
    parent->addChild(itm);
}
