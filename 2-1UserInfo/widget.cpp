#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QDebug>
#include <QSize>
#include <QStringList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setFixedSize(50, 50);

    QPixmap pix(":/b/11.png");
    ui->label->setPixmap(pix.scaled(50, 50));

    QStringList provices;
    provices.append("湖南");
    provices.append("湖北");
    ui->comboBox->addItems(provices);

    connect(ui->listWidget, SIGNAL(currentRowChanged(int)),
            ui->stackedWidget, SLOT(setCurrentIndex(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QPixmap pix(":/b/22.png");

    QSize s = ui->label->size();
    ui->label->setPixmap(pix.scaled(s));

    qDebug() << "xx";
}
