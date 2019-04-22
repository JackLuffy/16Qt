#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>
#include <QDesktopWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 准备数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("guns.db");
    db.open();

    // 用数据库中的数据，填充plainModel
    plainModel = new QSqlQueryModel(this);
    plainModel->setQuery("SELECT * FROM guns");
    plainModel->setHeaderData(0, Qt::Horizontal, "序号");
    plainModel->setHeaderData(1, Qt::Horizontal, "类别");
    plainModel->setHeaderData(2, Qt::Horizontal, "型号");
    plainModel->setHeaderData(3, Qt::Horizontal, "价格");
    plainModel->setHeaderData(4, Qt::Horizontal, "库存");
    plainModel->setHeaderData(5, Qt::Horizontal, "备注");

    myModel = new mySqlModel(this);
    myModel->setQuery("SELECT * FROM guns");
    myModel->setHeaderData(0, Qt::Horizontal, "序号");
    myModel->setHeaderData(1, Qt::Horizontal, "类别");
    myModel->setHeaderData(2, Qt::Horizontal, "型号");
    myModel->setHeaderData(3, Qt::Horizontal, "价格");
    myModel->setHeaderData(4, Qt::Horizontal, "库存");
    myModel->setHeaderData(5, Qt::Horizontal, "备注");


    // 关联视图与模型
    ui->tableView->setModel(plainModel);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setColumnWidth(0, 60);
    ui->tableView->setColumnWidth(5, 60);

    ui->tableView_2->setModel(myModel);
    ui->tableView_2->verticalHeader()->hide();
    ui->tableView_2->setColumnWidth(0, 60);
    ui->tableView_2->setColumnWidth(5, 60);

    // 调整大小和位置
    this->resize(600, 500);
    int x = (QApplication::desktop()->width() - width()) / 2;
    int y = (QApplication::desktop()->height()-height()) / 2;
    this->move(x, y);
}

Widget::~Widget()
{
    delete ui;
}
