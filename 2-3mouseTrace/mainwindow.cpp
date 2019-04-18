#include "mainwindow.h"
#include <QToolTip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("鼠标跟踪器");

    statusLabel = new QLabel;
    statusLabel->setText("");
    statusLabel->setFixedWidth(150);

    mouseLabel = new QLabel;
    mouseLabel->setText("");

    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addWidget(mouseLabel);

    setMouseTracking(true);
    resize(600, 400);

}

MainWindow::~MainWindow()
{

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *me)
{
    mouseLabel->setText("双击");
}

void MainWindow::mouseMoveEvent(QMouseEvent *me)
{
    QString pos;
    pos.sprintf("(%d, %d)", me->x(),me->y());

    statusLabel->setText(QString("当前位置:") + pos);

    QToolTip::showText(QPoint(me->x()+10, me->y()+50), pos);
}

void MainWindow::mousePressEvent(QMouseEvent *me)
{
    QString s;
    s += "按下";
    switch(me->button())
    {
    case Qt::LeftButton:
        s += "左键";
        break;
    case Qt::RightButton:
        s += "右键";
        break;
    case Qt::MidButton:
        s += "中建";
        break;
    }
    mouseLabel->setText(s);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *me)
{
    mouseLabel->setText("松开");
}
