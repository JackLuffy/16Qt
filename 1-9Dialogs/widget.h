#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_file_clicked();

    void on_pushButton_color_clicked();

    void on_pushButton_font_clicked();

    void on_pushButton_input_clicked();

    void on_pushButton_msg_clicked();

    void on_pushButton_custom_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
