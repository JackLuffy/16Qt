#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <QMouseEvent>
#include <QWidget>
#include <QTimer>
#include <QPalette>
#include <QPoint>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent=0);

    void mousePressEvent(QMouseEvent *me);
    void mouseReleaseEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);

private slots:
    void showTime();

private:
    QTimer *t;
    QPalette *p;

    QPoint pos;
    bool pressed;
};

#endif // DIGITALCLOCK_H
