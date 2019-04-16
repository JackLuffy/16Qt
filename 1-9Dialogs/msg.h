#ifndef MSG_H
#define MSG_H

#include <QWidget>

namespace Ui {
class msg;
}

class msg : public QWidget
{
    Q_OBJECT

public:
    explicit msg(QWidget *parent = 0);
    ~msg();

private slots:

    void on_pushButtonQuestion_clicked();

    void on_pushButtonInfo_clicked();

    void on_pushButtonWarning_clicked();

    void on_pushButtonCritical_clicked();

    void on_pushButtonQuit_clicked();

private:
    Ui::msg *ui;
};

#endif // MSG_H
