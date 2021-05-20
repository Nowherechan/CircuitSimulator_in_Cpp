/**
  * circuitwindow.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     a window contains map of circuit.
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     1.Add components' button
  *     2.Connect oscillograph.(QtChart or QWT or QCustomerPlot)
  */
#include "circuitwindow.h"
#include "ui_circuitwindow.h"
#include <QPainter>
#include <QDebug>

CircuitWindow::CircuitWindow(QWidget *parent, circuit_Mod mod) :
    QMainWindow(parent),
    ui(new Ui::CircuitWindow)
{
    ui->setupUi(this);
    current_Mod = mod;

    //退出按钮
    connect(ui->actionExit, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    connect(ui->actionReturn, &QAction::triggered, [=](){
        emit turn_Back();
    });

    //工具栏添加元件
}

CircuitWindow::~CircuitWindow()
{
    delete ui;
}

//绘制背景图片
void CircuitWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QString pix_Background = ":/src/bg_basic.png";   //背景图片路径
    QPixmap pixmap_Background;
    bool ret = pixmap_Background.load(pix_Background);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }
    painter.drawPixmap(0, 0, this->width(), this->height(), pix_Background);
}
