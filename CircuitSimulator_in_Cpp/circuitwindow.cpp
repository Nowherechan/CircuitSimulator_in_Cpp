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
#include <QAction>
#include <QList>
#include <QListIterator>

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

    //单选设置
    connect(this, &CircuitWindow::select, [=](){
        QList<QAction *> actlist = ui->toolBarComponent->actions();
        foreach(QAction* i, actlist) {
            i->setChecked(false);
        }
    });

    //工具栏按钮设置
    ui->actionSelect->setChecked(true);
    connect(ui->actionSelect, &QAction::triggered, [=](){
        emit select(Select);
        ui->actionSelect->setChecked(true);
        ui->Map->select(Select);
    });

    //分模式运行
    switch (mod) {
    case Digital:
        //工具栏添加元件
        ui->toolBarComponent->addAction(ui->actionAnd);
        connect(ui->actionAnd, &QAction::triggered, [=](){
            emit select(And);
            ui->actionAnd->setChecked(true);
            ui->Map->select(And);
        });
        ui->toolBarComponent->addAction(ui->actionOr);
        connect(ui->actionOr, &QAction::triggered, [=](){
            emit select(Or);
            ui->actionOr->setChecked(true);
            ui->Map->select(Or);
        });
        ui->toolBarComponent->addAction(ui->actionNon);
        connect(ui->actionNon, &QAction::triggered, [=](){
            emit select(Non);
            ui->actionNon->setChecked(true);
            ui->Map->select(Non);
        });
        break;

    case Analog:
        //工具栏添加元件
        break;

    default:
        break;
    }
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
