#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QThread;
class Worker;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void handleQueuedRequest();
    void handleBlockingRequest(int& value);

private:
    Ui::MainWindow *ui;
    QThread* thread;
    Worker* worker;
};
#endif // MAINWINDOW_H
