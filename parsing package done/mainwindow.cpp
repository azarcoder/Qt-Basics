#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCryptographicHash>
#include <QRandomGenerator>
#include <QByteArray>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    quint8  arr_uc_Buffer_data[100];
    quint8 us_Buffer_data_Size  = 0;

    for(int i=0; i < 55; i++)
    {
        arr_uc_Buffer_data[i] = qrand();
    }

    us_Buffer_data_Size = 55;

    Transmit_Data(arr_uc_Buffer_data, us_Buffer_data_Size);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Transmit_Data(void *in_vp_BufferData, quint8 in_ucDataSize)
{


    quint8 *pc_buffer = 0;
    quint8 arr[512];
    pc_buffer = (quint8 *)in_vp_BufferData;
    memset(&mS_Packet, 0, sizeof(mS_Packet));

    //structure member value assign
    mS_Packet.us_Header_ID=1001;
    mS_Packet.us_Cmd_Id = 100;
    mS_Packet.us_datasize = in_ucDataSize
            ;
    //copy the pc_buffer data to structure array data
    memcpy(mS_Packet.arr_uc_data, pc_buffer, in_ucDataSize);

    mS_Packet.us_checksum = qChecksum((char *)pc_buffer, mS_Packet.us_datasize);

    //copying structure data to array
    memcpy(arr, &mS_Packet, sizeof(arr));

    //qDebug()<<"CheckSum Data"<<mS_Packet.us_checksum;
    //for(auto Index=0; Index < 264; Index++)
        //qDebug("%x", arr[Index]);
        //qDebug() << Index <<":" << arr[Index];

    Parsing_Data(arr, sizeof(mS_Packet));
    qDebug() << "Header Id:" << mS_Packet.us_Header_ID << "Received Id:" << mS_Res_Packet.us_Header_ID;
    qDebug() << "Command Id:" << mS_Packet.us_Cmd_Id << "Received Command Id:" << mS_Res_Packet.us_Cmd_Id;
    qDebug() << "datasize:" << mS_Packet.us_datasize << "Received datasize:" << mS_Res_Packet.us_datasize;
    qDebug() << "data:";
    for(auto Index=0; Index < mS_Packet.us_datasize; Index++)
        qDebug()<<mS_Packet.arr_uc_data[Index];
    qDebug() << "Received:";
    for(auto Index=0; Index < mS_Packet.us_datasize; Index++)
        qDebug()<<mS_Res_Packet.arr_uc_data[Index];
    qDebug() << "checksum:" << mS_Packet.us_checksum << "Received checksum:" << mS_Res_Packet.us_checksum;




}

void MainWindow::Parsing_Data(uint8_t *in_pucBuffer, uint16_t in_Buffer_Data_Size)
{
    memset(&mS_Res_Packet,0,sizeof(mS_Packet));
    uint8_t arr[512];

    //parsing
    uint16_t readIndex = 0;
    uint16_t ParseIndex = 0;
    uint16_t iLoopCount=0;
    uint8_t state=0;

    while(iLoopCount<in_Buffer_Data_Size)
    {
        switch(state)
        {
            /* Header */
            case 0:
                readIndex++;
                if(readIndex == sizeof(mS_Res_Packet.us_Header_ID))
                {
                    memcpy(&mS_Res_Packet.us_Header_ID, &in_pucBuffer[ParseIndex], sizeof(mS_Res_Packet.us_Header_ID));

                    if(mS_Res_Packet.us_Header_ID == mS_Packet.us_Header_ID)
                    {
                        ParseIndex += sizeof(mS_Res_Packet.us_Header_ID);
                        state =1;
                    }

                }
            break;

            /* command Id*/
            case 1:
                memcpy(&mS_Res_Packet.us_Cmd_Id,&in_pucBuffer[ParseIndex],sizeof(mS_Res_Packet.us_Cmd_Id));
                ParseIndex += sizeof(mS_Res_Packet.us_Cmd_Id);
                state = 2;
            break;

            /* Datasize */
            case 2:
                memcpy(&mS_Res_Packet.us_datasize,&in_pucBuffer[ParseIndex],sizeof(mS_Res_Packet.us_datasize));
                ParseIndex += sizeof(mS_Res_Packet.us_datasize);
                state = 3;
            break;

            /*Array of data*/
            case 3:
                for(auto Index=0;Index<mS_Res_Packet.us_datasize;Index++)
                {
                    arr[Index] = in_pucBuffer[ParseIndex];
                    ParseIndex++;
                }
                memcpy(mS_Res_Packet.arr_uc_data,arr,sizeof(arr));
                state = 4;
            break;

            /*checksum*/
            case 4:
                ParseIndex = sizeof(mS_Packet)-2;
                memcpy(&mS_Res_Packet.us_checksum,&in_pucBuffer[ParseIndex],sizeof(mS_Res_Packet.us_checksum));
              //  qDebug() << "Header Id:" << mS_Packet.us_Header_ID << "Received Id:" << mS_Res_Packet.us_Header_ID;
            break;

            default:
                state = 0;
                readIndex = 0;
                ParseIndex=0;
                break;
            }
            iLoopCount++;
        }

    }



