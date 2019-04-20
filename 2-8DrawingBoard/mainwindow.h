#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QWidget>
#include <QToolButton>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPoint>
#include "drawarea.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void choseStyle(int index);
    void choseColor();

private:
    Ui::MainWindow *ui;

    QLabel *lineStyleLabel;
    QComboBox *lineStyleComboBox;

    QLabel *lineWidthLabel;
    QSpinBox *lineWidthSpinBox;

    QToolButton *paletteToolBtn;
    QToolButton *clearToolBtn;

    drawArea *dArea;
};

#endif // MAINWINDOW_H
