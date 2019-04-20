#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPixmap>
#include <QKeyEvent>
#include <QPoint>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    // 复写绘图事件
    void paintEvent(QPaintEvent *e);

    // 复写键盘事件
    void keyPressEvent(QKeyEvent *e);

private:
    void drawGrid();
    void drawHead();

    QPoint point;
};

#endif // WIDGET_H
