#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected slots:
    void sendTcpData();

private:
    // 定义一个服务器连接的套接字
    QTcpSocket *socket;

    QLineEdit *lineEdit;
    QPushButton *btn;

    QHBoxLayout *layout;
};

#endif // WIDGET_H
