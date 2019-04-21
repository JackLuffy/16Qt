#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QString>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("guns.db");
    db.open();

    // 设置数据模型
    model = new EditableSqlModel(this);

    // 将视图关联数据模型
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();

    // 设置控制面板的数据与数据库联动
    ids = new QSqlQueryModel(this);
    types = new QSqlQueryModel(this);
    names = new QSqlQueryModel(this);
    prices = new QSqlQueryModel(this);
    remains = new QSqlQueryModel(this);

    types->setQuery("SELECT type FROM guns GROUP BY type");

    ui->comboBox_typeSale->setModel(types);

    connect(ui->comboBox_typeSale, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(updatePanel(QString)));
    connect(ui->comboBox_name, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(updatePanel(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updatePanel(QString s)
{
    // 根据选择的类型修改名称
    if(sender()->objectName() == ui->comboBox_typeSale->objectName())
    {
        names->setQuery(QString("SELECT name FROM guns WHERE type = '%1'").arg(s));
        ui->comboBox_name->setModel(names);
        ui->comboBox_name->setCurrentIndex(0);
    }

    // 根据选择的类型修改名称
    if(sender()->objectName() == ui->comboBox_name->objectName())
    {
        remains->setQuery(QString("SELECT remains FROM guns WHERE name = '%1'").arg(s));
        ui->spinBoxBuyAmount->setRange(1,remains->data(remains->index(0,4)).toInt());
    }

}

