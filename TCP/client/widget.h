#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_sendBtn_clicked();
    void Read_data_from_socket();

private:
    Ui::Widget *ui;
    QTcpSocket *m_TcpSocket;
};
#endif // WIDGET_H
