#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set progress bar range
    ui->progressBar->setRange(0, 10);

    thread = new QThread(this);
    worker = new Worker();

    worker->moveToThread(thread);

    connect(thread, &QThread::started, worker, &Worker::doWork);
    //Qt automatically decided Queued Connection
    connect(worker, &Worker::progress, ui->progressBar, &QProgressBar::setValue);
    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &QObject::deleteLater);
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);

    thread->start();  // Start the thread
}

MainWindow::~MainWindow()
{
    delete ui;
}

