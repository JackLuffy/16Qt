#include "widget.h"
#include "ui_widget.h"
#include "inputdiglog.h"
#include "msg.h"

#include <QFileDialog>
#include <QRegExp>
#include <QDebug>

#include <QColorDialog>
#include <QColor>
#include <QPalette>

#include <QFont>
#include <QFontDialog>

#include <QEventLoop>

#include <QMessageBox>
#include <QPixmap>
#include <QShortcut>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->frame->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_file_clicked()
{
    QString filter;
    filter += "所有(*);;";
    filter += "源码(*.c *.cpp *.h);;";
    filter += "图片(*.jpg *.png);;";

    QString name;
    name = QFileDialog::getOpenFileName(this, "选择文件", "/", filter);
    if(name.isNull())
        return;

    ui->lineEdit_file->setText(name.mid(name.indexOf(QRegExp("/[^/]*$"), 0)+1));
}

void Widget::on_pushButton_color_clicked()
{
    QColor c = QColorDialog::getColor(Qt::blue);
    if(!c.isValid())
        return;

    ui->frame->setPalette(QPalette(c));
}

void Widget::on_pushButton_font_clicked()
{
    QFont f;
    bool ok;
    f = QFontDialog::getFont(&ok, this);
    if(!ok)
        return;

    ui->lineEdit_font->setFont(f);
}

void Widget::on_pushButton_input_clicked()
{
    inputDiglog *input = new inputDiglog(NULL);
    input->show();

    QEventLoop eloop;
    eloop.exec();
}

void Widget::on_pushButton_msg_clicked()
{
    msg *m = new msg(NULL);
    m->show();

    QEventLoop eloop;
    eloop.exec();
}

void Widget::on_pushButton_custom_clicked()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setWindowTitle("自定义消息框");

    QPushButton *btnYes = msgBox->addButton("是",QMessageBox::ActionRole);
    QPushButton *btnNo  = msgBox->addButton("否",QMessageBox::ActionRole);

    msgBox->setText("生存还是毁灭？");
    QPixmap *pix = new QPixmap("flower.jpg");
    msgBox->setIconPixmap(pix->scaled(QSize(40, 40)));

    QShortcut *key = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(key, SIGNAL(activated()), btnYes, SLOT(click()));

    msgBox->exec();
}
