#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRandomGenerator>
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

    Transmit_data(arr_uc_Buffer_data, us_Buffer_data_Size);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Transmit_data(void *in_vp_BufferData, quint8 in_ucDataSize)
{
    quint8 *pc_buffer = 0;
    quint8 arr[512];
    quint16 us_Transmit_Data_Size = 0, us_Tx_Frame_Index = 0;
    pc_buffer = (quint8*) in_vp_BufferData;
    memset(&mS_Packet, 0, sizeof(mS_Packet));
    mS_Packet.us_Header_ID = 1001;
    mS_Packet.us_Cmd_Id = 100;
    mS_Packet.us_datasize = in_ucDataSize;
    memcpy(mS_Packet.arr_uc_data, pc_buffer, mS_Packet.us_datasize);
    mS_Packet.us_checksum = qChecksum((char*)pc_buffer,mS_Packet.us_datasize);
    memset(&mS_Res_Packet, 0, sizeof(mS_Packet));

    //parsing
    memcpy(&arr[us_Tx_Frame_Index], &mS_Packet.us_Header_ID, sizeof (mS_Packet.us_Header_ID));
    us_Transmit_Data_Size += sizeof (mS_Packet.us_Header_ID);//2
    us_Tx_Frame_Index += sizeof (mS_Packet.us_Header_ID);//2

    memcpy(&arr[us_Tx_Frame_Index], &mS_Packet.us_Cmd_Id, sizeof (mS_Packet.us_Cmd_Id));
    us_Transmit_Data_Size += sizeof (mS_Packet.us_Cmd_Id);//2
    us_Tx_Frame_Index += sizeof (mS_Packet.us_Cmd_Id);//2

    memcpy(&arr[us_Tx_Frame_Index], &mS_Packet.us_datasize, sizeof (mS_Packet.us_datasize));
    us_Transmit_Data_Size += sizeof (mS_Packet.us_datasize);//2
    us_Tx_Frame_Index += sizeof (mS_Packet.us_datasize);//2

    memcpy(&arr[us_Tx_Frame_Index], &mS_Packet.arr_uc_data, mS_Packet.us_datasize);
    us_Transmit_Data_Size += mS_Packet.us_datasize;//55
    us_Tx_Frame_Index += mS_Packet.us_datasize;//55

    memcpy(&arr[us_Tx_Frame_Index], &mS_Packet.us_checksum, sizeof(mS_Packet.us_checksum));
    us_Transmit_Data_Size += sizeof(mS_Packet.us_checksum);

        for(auto iLoopCount = 0; iLoopCount < us_Transmit_Data_Size; iLoopCount++)
        {
//            qDebug() << "LoopCount:" << iLoopCount+1;
//              qDebug("%d",arr[iLoopCount]);
            Parsing_data(&arr[iLoopCount],sizeof(arr[iLoopCount]));
        }


}

void MainWindow::Parsing_data(uint8_t *in_pucBuffer, uint16_t in_Buffer_Data_Size)
{
//    qDebug() << "Data:" << *in_pucBuffer << " " << "size:" << sizeof(in_Buffer_Data_Size);

    uint8_t *pc_buffer;
    uint16_t readIndex = 0;
    static uint16_t ParseIndex = 0;
    uint16_t iLoopCount = 0;
    static uint8_t state = 0;

    while(iLoopCount < in_Buffer_Data_Size)
    {
        switch (state) {

        /* Header */

        case 0:
            pc_buffer = (uint8_t* )&mS_Res_Packet.us_Header_ID;
            memcpy(&pc_buffer[ParseIndex], &in_pucBuffer[readIndex], 1);
            ParseIndex++;
            if(ParseIndex == sizeof(mS_Res_Packet.us_Header_ID))
            {
               if(mS_Res_Packet.us_Header_ID == mS_Packet.us_Header_ID)
                {
                    state =1;
                    ParseIndex=0;
                }
                qDebug() <<"Header id:" <<mS_Res_Packet.us_Header_ID << "state:"<<state;
            }
        break;


        /* Cmd Id: */

        case 1:
            pc_buffer = (uint8_t* )&mS_Res_Packet.us_Cmd_Id;
            memcpy(&pc_buffer[ParseIndex], &in_pucBuffer[readIndex], 1);
            ParseIndex++;
            if(ParseIndex == sizeof(mS_Res_Packet.us_Cmd_Id))
            {
                if(mS_Res_Packet.us_Cmd_Id == mS_Packet.us_Cmd_Id)
                {
                    state = 2;
                    ParseIndex = 0;
                }
                qDebug() <<"cmd id:" <<mS_Res_Packet.us_Cmd_Id << "state:"<<state ;
            }

        break;

        /*data size*/
        case 2:
            pc_buffer = (uint8_t*) &mS_Res_Packet.us_datasize;
            memcpy(&pc_buffer[ParseIndex], &in_pucBuffer[readIndex], 1);
            ParseIndex++;
            if(ParseIndex == sizeof(mS_Res_Packet.us_datasize))
            {
                if(mS_Res_Packet.us_datasize == mS_Packet.us_datasize)
                {
                    state = 3;
                    ParseIndex = 0;
                }
                qDebug() <<"data size:" <<mS_Res_Packet.us_datasize << "state:"<<state;
            }

         break;

        /* Array of data */
        case 3:
            pc_buffer = (uint8_t*) &mS_Res_Packet.arr_uc_data;
            memcpy(&pc_buffer[ParseIndex], &in_pucBuffer[readIndex], 1);
            ParseIndex++;
            if(ParseIndex == mS_Res_Packet.us_datasize)
            {
                state = 4;
                ParseIndex = 0;
            }
            break;

        /* checksum */
        case 4:
            pc_buffer = (uint8_t*) &mS_Res_Packet.us_checksum;
            memcpy(&pc_buffer[ParseIndex], &in_pucBuffer[readIndex], 1);
            ParseIndex++;
            if(ParseIndex == sizeof(mS_Res_Packet.us_checksum))
            {
                ParseIndex=0;
                if(mS_Res_Packet.us_checksum == mS_Packet.us_checksum)
                {
                    qDebug() << "Checksum verified!, data are same!";
                }
            }
            qDebug() <<"data size:" <<mS_Res_Packet.us_checksum << "state:"<<state;
            break;
        }
        iLoopCount++;
    }
}

