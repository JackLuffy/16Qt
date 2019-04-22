#include "udpclient.h"
#include <QMessageBox>
#include <QHostAddress>

UdpClient::UdpClient(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("UDP Client"));

    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);

    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);

    connect(CloseBtn,SIGNAL(clicked()),this,SLOT(close()));

    // 创建 UDP 套接字，并绑定默认本机 IP 和端口50001
    udpSocket = new QUdpSocket(this);
    if(!udpSocket->bind(50001))
    {
        QMessageBox::information(this, "地址绑定失败", udpSocket->errorString());
        return;
    }

    // 当有数据来是，自动触发槽函数
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
}

UdpClient::~UdpClient()
{
    
}

void UdpClient::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        ReceiveTextEdit->insertPlainText(msg);
    }
}
