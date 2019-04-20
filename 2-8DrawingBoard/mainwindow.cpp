#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QColorDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化基本元素
    lineStyleLabel = new QLabel("线条风格: ", this);

    lineStyleComboBox = new QComboBox(this);
    lineStyleComboBox->addItem("实线", static_cast<int>(Qt::SolidLine));
    lineStyleComboBox->addItem("虚线", static_cast<int>(Qt::DashLine));
    lineStyleComboBox->addItem("点线", static_cast<int>(Qt::DotLine));
    lineStyleComboBox->addItem("点虚线", static_cast<int>(Qt::DashDotLine));
    lineStyleComboBox->addItem("点点虚线", static_cast<int>(Qt::DashDotDotLine));

    lineWidthLabel = new QLabel("线宽: ", this);
    lineWidthSpinBox = new QSpinBox(this);
    lineWidthSpinBox->setRange(1, 10);
    lineWidthSpinBox->setValue(2);

    paletteToolBtn = new QToolButton(this);
    paletteToolBtn->setIcon(QIcon(":/palette.png"));

    clearToolBtn = new QToolButton(this);
    clearToolBtn->setIcon(QIcon(":/clear.png"));

    // 将基本元素添加到默认工具栏
    ui->mainToolBar->addWidget(lineStyleLabel);
    ui->mainToolBar->addWidget(lineStyleComboBox);

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(lineWidthLabel);
    ui->mainToolBar->addWidget(lineWidthSpinBox);

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(paletteToolBtn);
    ui->mainToolBar->addWidget(clearToolBtn);

    // 固定工具栏
    ui->mainToolBar->setMovable(false);

    // 设置中央编辑区
    dArea = new drawArea;
    dArea->setAutoFillBackground(true);
    QPalette p;
    p.setColor(QPalette::Background, Qt::white);
    dArea->setPalette(p);
    this->setCentralWidget(dArea);

    // 关联工具栏的信号与编辑区的槽函数
    connect(this->lineStyleComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(choseStyle(int)));
    connect(this->lineWidthSpinBox, SIGNAL(valueChanged(int)),
            dArea, SLOT(setPenWidth(int)));
    connect(this->paletteToolBtn, SIGNAL(clicked(bool)),
            this, SLOT(choseColor()));
    connect(this->clearToolBtn, SIGNAL(clicked(bool)),
            dArea, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::choseStyle(int index)
{
    dArea->setPenStyle(lineStyleComboBox->itemData(index).toInt());
}

void MainWindow::choseColor()
{
    QColor c = QColorDialog::getColor();
    if(!c.isValid())
        return;

    dArea->setPenColor(c);
}
