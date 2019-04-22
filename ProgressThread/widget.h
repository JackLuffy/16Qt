#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "worker.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Worker *worker;

private slots:
    void progress();
};

#endif // WIDGET_H
