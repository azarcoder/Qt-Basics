#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread* thread = new QThread;
    worker* worker_thread = new worker;

    worker_thread->moveToThread(thread);

    connect(thread, &QThread::started, worker_thread, &worker::doWork);
    connect(worker_thread, &worker::destroyed, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

