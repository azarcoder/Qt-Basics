#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QByteArray>
#include <QDataStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);



    m_TcpSocket = new QTcpSocket();

    connect(m_TcpSocket, &QTcpSocket::readyRead, this, &Widget::Read_data_from_socket);

    m_TcpSocket->connectToHost(QHostAddress::LocalHost, 8080);
    m_TcpSocket->open(QIODevice::ReadWrite);
    if(m_TcpSocket->isOpen())
    {
         QMessageBox::information(this, "status", "Socket opened!");
    }
    else
    {
        QMessageBox::information(this, "status", "Socket not opened!");
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_sendBtn_clicked()
{
    if(m_TcpSocket)
    {
        if(m_TcpSocket->isOpen())
        {
            QString writeData = ui->dataLineEdit->text();
            m_TcpSocket->write(writeData.toStdString().c_str());
        }
        else
        {
            QMessageBox::information(this, "Error", m_TcpSocket->errorString());
        }
    }
    else
    {
        QMessageBox::information(this, "Error", m_TcpSocket->errorString());
    }
}

//Read data from server
void Widget::Read_data_from_socket()
{
    if(m_TcpSocket)
    {
        if(m_TcpSocket->isOpen())
        {
            QByteArray data_from_server = m_TcpSocket->readAll();

            QString MessageString = QString::fromStdString(data_from_server.toStdString());
            ui->textEdit->append(MessageString);
        }
        else
        {
            QMessageBox::information(this, "Error", m_TcpSocket->errorString());
        }
    }
    else
    {
        QMessageBox::information(this, "Error", m_TcpSocket->errorString());
    }
}


