#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread = new QThread(this);
    worker = new Worker;

    worker->moveToThread(thread);

    connect(thread, &QThread::started, worker, &Worker::doWork);

    // 🔄 Queued connection (fire & forget)
    connect(worker, &Worker::requestValue, this, &MainWindow::handleQueuedRequest,
            Qt::QueuedConnection);

    // 🔒 Blocking connection (wait for reply)
    connect(worker, &Worker::requestValueWithReply, this, &MainWindow::handleBlockingRequest,
            Qt::BlockingQueuedConnection);

    thread->start();
}

void MainWindow::handleQueuedRequest()
{
    qDebug() << "MainWindow [Queued]: Providing value in thread:" << QThread::currentThread();
    QThread::sleep(2);  // Simulate slow GUI response
}

void MainWindow::handleBlockingRequest(int &value)
{
    qDebug() << "MainWindow [Blocking]: Providing value in thread:" << QThread::currentThread();
    QThread::sleep(2);  // Simulate slow GUI response
    //but here we do some operations and return value
    value = 42;
}

MainWindow::~MainWindow()
{
    thread->quit();
    thread->wait();
    delete ui;
}
