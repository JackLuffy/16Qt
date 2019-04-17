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

    QStringList guangdong, guangxi, hunan, hubei;
    guangdong.append("广州");
    guangdong.append("佛山");
    guangdong.append("潮汕");
    guangxi.append("桂林");
    hunan.append("长沙");
    hunan.append("郴州");
    hubei.append("武汉");

    city << guangdong;
    city << guangxi;
    city << hunan;
    city << hubei;

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

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_2->clear();

    if(arg1 == QString("广东"))
        ui->comboBox_2->addItems(city.at(0));
    if(arg1 == QString("广西"))
        ui->comboBox_2->addItems(city.at(1));
    if(arg1 == QString("湖南"))
        ui->comboBox_2->addItems(city.at(2));
    if(arg1 == QString("湖北"))
        ui->comboBox_2->addItems(city.at(3));
}
