#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("枪↓支の嘿市交↑易");

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("guns.db");
    db.open();

    // 初始化控制面板状态
    ui->lineEditPriceTotal->setEnabled(true);
    ui->lineEditPriecPerEach->setEnabled(true);

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

    // 当控制面板上的下拉框、选值框发生变化时，触发槽函数去联动改变其他关联的内容
    connect(ui->comboBox_typeSale, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(updatePanel(QString)));
    connect(ui->comboBox_name, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(updatePanel(QString)));
    connect(ui->spinBoxBuyAmount, SIGNAL(valueChanged(QString)),
            this, SLOT(updatePanel(QString)));

    connect(ui->pushButtonCommit, SIGNAL(clicked(bool)),
            this, SLOT(updateAll()));

    // 初始化类别下拉框
    types->setQuery("SELECT type FROM guns GROUP BY type");
    ui->comboBox_typeSale->setModel(types);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::updatePanel(QString s)
{
    // 类别改变 --> 型号跟着变
    if(sender()->objectName() == ui->comboBox_typeSale->objectName())
    {
        // 获取当前类别的型号
        names->setQuery(QString("SELECT name FROM guns WHERE type = '%1'").arg(s));
        ui->comboBox_name->setModel(names);
        ui->comboBox_name->setCurrentIndex(0);
    }

    // 型号改变 --> 购买数量上限跟着变、单价跟着变、库存展示跟着变
    if(sender()->objectName() == ui->comboBox_name->objectName())
    {
        // 获取当前型号的库存
        remains->setQuery(QString("SELECT remain FROM guns WHERE name = '%1'").arg(s));
        int max = remains->data(remains->index(0,0)).toInt();
        ui->spinBoxBuyAmount->setRange(0, max);
        ui->labelRemain->setText(QString::number(max));

        // 获取当前型号的单价
        prices->setQuery(QString("SELECT price FROM guns WHERE name = '%1'").arg(s));
        ui->lineEditPriecPerEach->setText(QString::number(prices->data(remains->index(0,0)).toInt()));
    }

    // 型号改变 或 购买数量改变 --> 总价跟着变
    if(sender()->objectName() == ui->comboBox_name->objectName() ||
       sender()->objectName() == ui->spinBoxBuyAmount->objectName())
    {
        // 获取当前型号的单价
        QString type  = ui->comboBox_name->currentText();
        prices->setQuery(QString("SELECT price FROM guns WHERE name = '%1'").arg(type));

        // 获取当前购买的数量
        int     amount= ui->spinBoxBuyAmount->value();

        // 计算总价
        float totalAmount = prices->data(remains->index(0,0)).toInt() * amount;
        ui->lineEditPriceTotal->setText(QString::number(totalAmount));
    }
}

void Widget::updateAll()
{
    // 获取当前购买数量
    int amount= ui->spinBoxBuyAmount->value();
    if(amount == 0)
        return;

    // 获取当前型号的单价，并计算总价
    QString type  = ui->comboBox_name->currentText();
    prices->setQuery(QString("SELECT price FROM guns WHERE name = '%1'").arg(type));
    float totalAmount = prices->data(remains->index(0,0)).toInt() * amount;

    // 弹窗提示
    int a = QMessageBox::question(this, "确认交易",
                                  QString("您确认要购买这些枪の支↓吗？ 诚惠￥%1").arg(totalAmount),
                                  QMessageBox::Yes, QMessageBox::No);
    if(a == QMessageBox::No)
        return;
}
