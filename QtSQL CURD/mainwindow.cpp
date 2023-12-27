#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    // Create a QSqlDatabase object
    m_DB_Connection = QSqlDatabase::addDatabase("QSQLITE");


    m_DB_Connection.setDatabaseName(QCoreApplication::applicationDirPath()+"mydatabase.db");
    if (m_DB_Connection.open()) {
        qDebug() << "Database connected successfully!";
    }
    else {
        qDebug() << "database is not connected";
        qDebug() << "Error : " << m_DB_Connection.lastError();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    m_DB_Connection.close();
}


void MainWindow::on_pushButton_Insert_clicked()
{
    // Open the database connection
    m_DB_Connection.open();

    // Start a transaction
    m_DB_Connection.transaction();

    // Create a QSqlQuery object and bind values
    QSqlQuery query(m_DB_Connection);
    query.prepare("INSERT INTO students (id,name,city) VALUES(:id, :name, :city)");
    query.bindValue(":id",ui->lineEdit_Id->text().toInt());
    query.bindValue(":name",ui->lineEdit_Name->text());
    query.bindValue(":city",ui->lineEdit_City->text());

    if (query.exec()) {
        m_DB_Connection.commit();
        QMessageBox::information(this,"status","Inserted successfully!");
    }
    else {
        QMessageBox::critical(this,"Error","Inserted failed! " + query.lastError().text() );
        m_DB_Connection.close();
    }

    // Close the database connection
    m_DB_Connection.close();
}


void MainWindow::on_pushButton_View_clicked()
{
    m_DB_Connection.open();
    m_DB_Connection.transaction();
    qint8 No_of_rows_to_display = 10;
    QSqlQuery query(m_DB_Connection);
    query.prepare("SELECT * FROM students");
    if (query.exec()) {
        ui->tableWidget->setRowCount(No_of_rows_to_display);
        qint16 iRowCount = 0;
        while (query.next()) {
            ui->tableWidget->setItem(iRowCount, 0, new QTableWidgetItem(QString(query.value("id").toString())));
            ui->tableWidget->setItem(iRowCount, 1, new QTableWidgetItem(QString(query.value("name").toString())));
            ui->tableWidget->setItem(iRowCount, 2, new QTableWidgetItem(QString(query.value("city").toString())));
            iRowCount += 1;
        }
    }
    m_DB_Connection.commit();
    m_DB_Connection.close();
}


void MainWindow::on_pushButton_Update_clicked()
{
    m_DB_Connection.open();
    m_DB_Connection.transaction();

    QSqlQuery query(m_DB_Connection);
    query.prepare("UPDATE students SET name=:name,city=:city WHERE id=:id");
    query.bindValue(":id",ui->lineEdit_Id->text().toInt());
    query.bindValue(":name",ui->lineEdit_Name->text());
    query.bindValue(":city",ui->lineEdit_City->text());

    if (query.exec()) {
        m_DB_Connection.commit();
        QMessageBox::information(this,"status","updated successfully!");
    }
    else {
        QMessageBox::critical(this,"Error","updation failed! " + query.lastError().text() );
        m_DB_Connection.close();
    }
    m_DB_Connection.close();
}


void MainWindow::on_pushButton_Del_clicked()
{
    m_DB_Connection.open();
    m_DB_Connection.transaction();
    QSqlQuery query(m_DB_Connection);
    query.prepare("DELETE FROM students WHERE id=:id");
    query.bindValue(":id",ui->lineEdit_Id->text().toInt());
    if (query.exec()) {
        m_DB_Connection.commit();
        QMessageBox::information(this,"status","deleted successfully!");
    }
    else {
        QMessageBox::critical(this,"Error","deletion failed! " + query.lastError().text() );
        m_DB_Connection.close();
    }
    m_DB_Connection.close();

}

