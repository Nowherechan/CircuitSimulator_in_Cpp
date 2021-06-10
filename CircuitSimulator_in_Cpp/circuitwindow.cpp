/**
  * circuitwindow.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     a window contains map of circuit.
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  * ~   1.Add components' button
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
    setWindowTitle("Circuit Simulator");

    QString pix_Icon = ":/src/icon.png";

    //加载图标
    QPixmap pixmap_Icon;
    bool ret_Icon = pixmap_Icon.load(pix_Icon);
    if(!ret_Icon)
    {
        qDebug() << "图片加载失败";
        return;
    }
    setWindowIcon(QIcon(pixmap_Icon));

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

    ui->actionRun->setChecked(false);
    connect(ui->actionRun, &QAction::triggered, [=](){
        emit select(Run);
        ui->actionRun->setChecked(true);
        ui->Map->select(Run);
    });

    ui->actionWire->setChecked(false);
    connect(ui->actionWire, &QAction::triggered, [=](){
        emit select(Wire);
        ui->actionWire->setChecked(true);
        ui->Map->select(Wire);
    });

    //分模式运行
    switch (mod) {
    case Digital:
        //工具栏添加元件
        ui->toolBarComponent->addAction(ui->actionHighLevel);
        connect(ui->actionHighLevel, &QAction::triggered, [=](){
            emit select(HighLevel);
            ui->actionHighLevel->setChecked(true);
            ui->Map->select(HighLevel);
        });

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

        ui->toolBarComponent->addAction(ui->actionNand);
        connect(ui->actionNand, &QAction::triggered, [=](){
            emit select(Nand);
            ui->actionNand->setChecked(true);
            ui->Map->select(Nand);
        });

        ui->toolBarComponent->addAction(ui->actionNor);
        connect(ui->actionNor, &QAction::triggered, [=](){
            emit select(Nor);
            ui->actionNor->setChecked(true);
            ui->Map->select(Nor);
        });

        ui->toolBarComponent->addAction(ui->actionAndOrNot);
        connect(ui->actionAndOrNot, &QAction::triggered, [=](){
            emit select(AndOrNot);
            ui->actionAndOrNot->setChecked(true);
            ui->Map->select(AndOrNot);
        });

        ui->toolBarComponent->addAction(ui->actionXor);
        connect(ui->actionXor, &QAction::triggered, [=](){
            emit select(Xor);
            ui->actionXor->setChecked(true);
            ui->Map->select(Xor);
        });

        ui->toolBarComponent->addAction(ui->actionXnor);
        connect(ui->actionXnor, &QAction::triggered, [=](){
            emit select(Xnor);
            ui->actionXnor->setChecked(true);
            ui->Map->select(Xnor);
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
