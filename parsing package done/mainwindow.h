#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct
{
    uint16_t us_Header_ID;
    uint16_t us_Cmd_Id;
    uint16_t us_datasize;
    uint8_t  arr_uc_data[256];
    uint16_t us_checksum;

}S_Packet;

typedef struct
{
    uint16_t us_Header_ID;
    uint16_t us_Cmd_Id;
    uint16_t us_datasize;
    uint8_t  arr_uc_data[256];
    uint16_t us_checksum;

}S_Res_Packet;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    S_Packet mS_Packet;
    S_Res_Packet mS_Res_Packet;
private slots:
    void Transmit_Data(void *in_vp_BufferData,quint8 in_ucDataSize);
    void Parsing_Data(uint8_t *in_pucBuffer, uint16_t in_Buffer_Data_Size);
};
#endif // MAINWINDOW_H
