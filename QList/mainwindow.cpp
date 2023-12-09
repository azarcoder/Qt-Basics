#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QDebug>
#include <QLinkedList>
#include <QMap>
#include<QMapIterator>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList <int> myvar;
    myvar.append(10);
    myvar.append(50);
    myvar.append(40);
    myvar.append(30);
    myvar.append(20);
//    qSort(myvar);//ascending
    //qSort(myvar.begin(),myvar.end(),qGreater<int>());//decending
//    for(int i=0;i<myvar.size();i++)
//        qDebug() << myvar.at(i);
    QVector<int> s(10);
    qCopy(myvar.begin(),myvar.end(),s.begin());
    qFill(s.begin()+6,s.end(),100);

    QList<int>::const_iterator it= qFind(myvar.begin(),myvar.end(),300);
    if(it!=myvar.end())
    {
        qDebug() << "found:"<< *it;
    }
    else
    {
        qDebug() << "not found!";
    }


    //for(int i=0;i<s.size();i++)
            //qDebug() << s.at(i);


    /*
    QLinkedList <int> myvar;
    // Adding elements to the linked list
    myvar << 1 << 2 << 3 << 4;
    myvar.removeLast();
    for(auto &i : myvar)
    {
        qDebug() << i;
    }
    */
    /*
    QMap<int,QString> emp;
    emp.insert(1,"azar");
    emp.insert(2,"kailsh");
    QMapIterator<int,QString> it(emp);
    while(it.hasNext())
    {
        it.next();
        qDebug() << it.key() << ":" << it.value();
    }*/



}

MainWindow::~MainWindow()
{
    delete ui;
}

