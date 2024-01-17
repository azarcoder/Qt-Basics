#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrintDialog>
#include <QPainter>
#include <QPrintPreviewDialog>
#include <QTextCursor>
#include <QTextFrame>
qint8 g_tableRowCount = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_printer = new QPrinter;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_insert_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    QString items = ui->lineEdit_product->text() + "    "  +  ui->lineEdit_qty->text() + "    " + "Rs."+ui->lineEdit_price->text()+"\n";
    cursor.insertText(items);
    cursor.movePosition(QTextCursor::Down);
    cursor.insertBlock();

    /***************** FOOTER ******************
    // Create a frame format for the footer
    QTextFrameFormat frameFormat;
    frameFormat.setBottomMargin(10); // Adjust the margin as needed

    // Create a frame for the footer using the frame format
    QTextFrame *footerFrame = cursor.insertFrame(frameFormat);

    // Move the cursor to the end of the footer frame
    QTextCursor frameCursor = footerFrame->lastCursorPosition();

    // Insert the footer text into the frame
    frameCursor.insertText("Thanks for the business! come again :)");

    // Optionally, move the cursor to a new line after the inserted footer
    frameCursor.movePosition(QTextCursor::End);
    frameCursor.insertBlock();
  */

}


void MainWindow::on_pushButton_print_clicked()
{
    QPrintDialog printDialog(m_printer, this);
//    if(printDialog.exec() == QDialog::Accepted)
//    {
//        QPainter painter (m_printer);
//    }
    if(printDialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(m_printer);
}

