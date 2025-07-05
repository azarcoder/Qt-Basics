#include "mylineedit.h"
#include <QPalette>

MyLineEdit::MyLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Base, Qt::lightGray);  // default
    setPalette(pal);
}

void MyLineEdit::focusInEvent(QFocusEvent *event)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Base, Qt::yellow);
    setPalette(pal);
    QLineEdit::focusInEvent(event);
}

void MyLineEdit::focusOutEvent(QFocusEvent *event)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Base, Qt::lightGray);
    setPalette(pal);
    QLineEdit::focusOutEvent(event);
}
