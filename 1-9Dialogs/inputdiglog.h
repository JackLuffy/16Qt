#ifndef INPUTDIGLOG_H
#define INPUTDIGLOG_H

#include <QWidget>

namespace Ui {
class inputDiglog;
}

class inputDiglog : public QWidget
{
    Q_OBJECT

public:
    explicit inputDiglog(QWidget *parent = 0);
    ~inputDiglog();

private slots:

    void on_pushButton_ChangeName_clicked();

    void on_pushButton_ChangeSex_clicked();

    void on_pushButton_ChangeAge_clicked();

    void on_pushButton_ChangeScore_clicked();

private:
    Ui::inputDiglog *ui;
};

#endif // INPUTDIGLOG_H
