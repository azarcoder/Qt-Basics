#include "widget.h"
#include "ui_widget.h"
#include <QPalette>
#include <QDebug>
#include <QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::gray);
    setPalette(pal);

    //custom event filter

    ui->lineEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

//only accepts text not digits
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        static QString digits = QString("1234567890");
        if(digits.indexOf(keyEvent->text())!=-1)
            return true;
    }
    // Call base implementation for unhandled events
    return QObject::eventFilter(watched, event);
}
void Widget::enterEvent(QEvent *event)
{
    qDebug() << "Mouse entered";
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::green);  // FIXED
    setPalette(pal);
    QWidget::enterEvent(event);
}

void Widget::leaveEvent(QEvent *event)
{
    qDebug() << "Mouse left";
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::red);  // FIXED
    setPalette(pal);
    QWidget::leaveEvent(event);
}


void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Widget resized to:" << event->size();
    QWidget::resizeEvent(event);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Pressed at:" << event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Released at:" << event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Moved at:" << event->pos();
}

// --- Key Events ---
void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Pressed:" << event->text() << "Code:" << event->key();
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "Key Released:" << event->text() << "Code:" << event->key();
}

