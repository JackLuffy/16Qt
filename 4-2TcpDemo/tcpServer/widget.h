#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

#include <QPlainTextEdit>
#include <QPushButton>
#include <QLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    // 定义一个TCP服务器，内部已经有监听套接（即专用于接收连接的套接字）
    // 可以直接通过listen完成套接字创建、地址绑定、监听状态的设置等动作
    QTcpServer server;

    // 定义一个连接套接字（即直接跟客户端相连的，专用于接收数据的套接字）
    QTcpSocket *socket;

protected slots:
    void newConnection();
    void tcpData();
    void btnClickSlot();

private:
    QPlainTextEdit *text;
    QPushButton *btn;
    QVBoxLayout *layout;
    bool isListening;

    static int clientNum;
};
#endif // WIDGET_H
