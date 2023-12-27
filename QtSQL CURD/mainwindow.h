#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Insert_clicked();

    void on_pushButton_View_clicked();

    void on_pushButton_Update_clicked();

    void on_pushButton_Del_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_DB_Connection; //DB connection obj
};
#endif // MAINWINDOW_H
