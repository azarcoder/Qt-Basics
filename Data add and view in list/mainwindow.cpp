#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Enter your name");
    ui->lineEdit_3->setPlaceholderText("Enter your city");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->addItem("Name:"+ui->lineEdit->text());
    QDate dob = ui->dateEdit->date();
    QString date = dob.toString("dd/MM/yyyy");
    ui->listWidget->addItem("DOB: "+date);
    ui->listWidget->addItem("City: "+ui->lineEdit_3->text());

    //Gender
    if(ui->radioButton->isChecked())
        ui->listWidget->addItem("Gender :"+ui->radioButton->text());
    else if(ui->radioButton_2->isChecked())
        ui->listWidget->addItem("Gender :"+ui->radioButton_2->text());
    else if(ui->radioButton_3->isChecked())
        ui->listWidget->addItem("Gender :"+ui->radioButton_3->text());

    //course
    ui->listWidget->addItem("Course: "+ui->comboBox->currentText());

    //education
    QString s="Education : ";
    if(ui->checkBox->isChecked())
        s+=ui->checkBox->text()+" ";
    if(ui->checkBox_2->isChecked())
        s+=ui->checkBox_2->text()+" ";
    if(ui->checkBox_3->isChecked())
        s+=ui->checkBox_3->text()+" ";
    ui->listWidget->addItem(s);


}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
}

