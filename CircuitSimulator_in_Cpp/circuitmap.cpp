/**
  * circuitmap.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     a map of circuit.
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  * ~   1.Finish the show-all and clear-all button.
  *     2.Complete the actions of components, like put-on , delete and move.
  *     3.Matrix of the can-put points.
  *     4.Function select().
  */
#include "circuitmap.h"
#include "ui_circuitmap.h"
#include "wire.h"
#include "logical-gate/andlogicgate.h"
#include "logical-gate/orlogicgate.h"
#include "logical-gate/nonlogicgate.h"
#include "logical-gate/nandlogicgate.h"
#include "logical-gate/norlogicgate.h"
#include "logical-gate/andornotlogicgate.h"
#include "logical-gate/xorlogicgate.h"
#include "logical-gate/xnorlogicgate.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsView>
#include <QSlider>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QPushButton>
#include <cmath>

//画可放元件的点阵图
QPixmap CircuitMap::draw_Dots_Map()
{
    //创建背景图
    QPixmap pix(MAP_WIDTH, MAP_HEIGHT);
    pix.fill(MAP_COLOR);

    //QPainter设置
    QPainter painter(&pix);
    QPen pen(DOTS_COLOR);
    pen.setWidth(1);
    painter.setPen(pen);
    QPen pen_bigger(DOTS_COLOR);
    pen_bigger.setWidth(3);

    //绘制点阵
    for(int i = 0; i <= MAP_WIDTH; i += 10)
    {
        for(int j = 0; j <= MAP_HEIGHT; j += 10)
        {
            if(i%100 == 0 && j%100 == 0)
                painter.setPen(pen_bigger);
            painter.drawPoint(QPoint(i, j));
            if(i%100 == 0 && j%100 == 0)
                painter.setPen(pen);
        }
    }

    //绘制map边缘
    pen.setColor(LINE_COLOR);
    painter.setPen(pen);
    painter.drawLine(0, 0, 0, MAP_HEIGHT-1);
    painter.drawLine(0, 0, MAP_WIDTH-1, 0);
    painter.drawLine(0, MAP_HEIGHT-1, MAP_WIDTH-1, MAP_HEIGHT-1);
    painter.drawLine(MAP_WIDTH-1, 0, MAP_WIDTH-1, MAP_HEIGHT-1);

    //pix.save("C:\\Users\\13445\\Desktop\\pix.png");

    return pix;
}

//放缩函数
void CircuitMap::zoomCircuit(int value)
{
    double s;
    s = pow(1.02, value - zoom);
    ui->map_Circuit->scale(s, s);
    //ui->map_Circuit->updateSceneRect(ui->map_Circuit->sceneRect());
    zoom = value;
}

CircuitMap::CircuitMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CircuitMap)
{
    ui->setupUi(this);

    //设置滑动条与数值框
    zoom = INITIAL_ZOOM;
    ui->slider_Zoom->setRange(10, 100);
    ui->slider_Zoom->setSingleStep(10);
    ui->slider_Zoom->setTickInterval(30);
    ui->slider_Zoom->setTickPosition(QSlider::TicksAbove);
    ui->slider_Zoom->setValue(INITIAL_ZOOM);
    ui->spinBox_Zoom->setRange(10, 100);
    ui->spinBox_Zoom->setSingleStep(10);
    ui->spinBox_Zoom->setValue(INITIAL_ZOOM);
    connect(ui->slider_Zoom, &QSlider::valueChanged, ui->spinBox_Zoom, [=](){
        int v = ui->slider_Zoom->value();
        v = (v + 5) / 10 * 10;
        ui->spinBox_Zoom->setValue(v);
        ui->slider_Zoom->setValue(v);
        zoomCircuit(v);
    });
    connect(ui->spinBox_Zoom, &QSpinBox::textChanged, ui->slider_Zoom, [=](){
        int v = ui->spinBox_Zoom->value();
        ui->slider_Zoom->setValue(v);
        zoomCircuit(v);
    });

    //创建画图区域
    ui->map_Circuit->setStyleSheet("padding:0px;border:0px;background:" + BG_COLOR_STRING); //去除边缘并设置底色
    QPixmap pix_Map = draw_Dots_Map();
    ui->map_Circuit->setMap(pix_Map);
    scene = new QGraphicsScene(ui->map_Circuit);
    scene->setSceneRect(-MAP_WIDTH/8, -MAP_HEIGHT/8, MAP_WIDTH*5/4, MAP_HEIGHT*5/4);
    ui->map_Circuit->setScene(scene);
    //ui->map_Circuit->setCacheMode(QGraphicsView::CacheBackground);                        //缓存背景加速渲染，但导致边缘有重影
    //ui->map_Circuit->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);            //改变渲染方式

    //显示全部按钮
    ui->btn_All->setStyleSheet("padding:10px;border:2px;background:" + BTN_COLOR_STRING);
    connect(ui->btn_All, &QPushButton::clicked, [=](){
        ui->spinBox_Zoom->setValue(10);
    });

    //清除元件按钮
    ui->btn_Clear->setStyleSheet("padding:10px;border:2px;background:" + BTN_COLOR_STRING);
    connect(ui->btn_Clear, &QPushButton::clicked, [=](){
        QList<QGraphicsItem *> itemList = scene->items();
        for(auto i = 0; i < itemList.size(); i++) {
            scene->removeItem(itemList[i]);
            delete itemList[i];
        }
    });
}

//添加元件图片方法

Wire* CircuitMap::addWire(QPoint A, QPoint B)
{
    Wire *w = new Wire(A, B);
    scene->addItem(w);
    return w;
}

andLogicGate* CircuitMap::addGateAnd()
{
    andLogicGate *g = new andLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

orLogicGate* CircuitMap::addGateOr()
{
    orLogicGate *g = new orLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

nonLogicGate* CircuitMap::addGateNon()
{
    nonLogicGate *g = new nonLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

nandLogicGate* CircuitMap::addGateNand()
{
    nandLogicGate *g = new nandLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

norLogicGate* CircuitMap::addGateNor()
{
    norLogicGate *g = new norLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

andOrNotLogicGate* CircuitMap::addGateAndOrNor()
{
    andOrNotLogicGate *g = new andOrNotLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

xorLogicGate* CircuitMap::addGateXor()
{
    xorLogicGate *g = new xorLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

xnorLogicGate* CircuitMap::addGateXnor()
{
    xnorLogicGate *g = new xnorLogicGate();
    scene->addItem(g);
    /*connect(g, &baselogicgate::deleteIt, this, [=](){
        scene->removeItem(g);
        delete g;
    });*/
    return g;
}

//当前选项
void CircuitMap::select(CircuitWindow::component_Selected c)
{
    //功能待填充
    switch (c) {
    case CircuitWindow::Select:
        //待填充
        break;

    case CircuitWindow::Wire:
        //
        addWire(QPoint(100, 100), QPoint(200, 200));
        break;

    case CircuitWindow::And :
        //待填充
        addGateAnd();
        break;

    case CircuitWindow::Or :
        //待填充
        addGateOr();
        break;

    case CircuitWindow::Non :
        //待填充
        addGateNon();
        break;

    case CircuitWindow::Nand :
        //待填充
        addGateNand();
        break;

    case CircuitWindow::Nor :
        //待填充
        addGateNor();
        break;

    case CircuitWindow::AndOrNot :
        //待填充
        addGateAndOrNor();
        break;

    case CircuitWindow::Xor :
        //待填充
        addGateXor();
        break;

    case CircuitWindow::Xnor :
        //待填充
        addGateXnor();
        break;

    default :
        break;
    }
}

CircuitMap::~CircuitMap()
{
    delete ui;
}

//绘制背景图片
void CircuitMap::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QString pix_Background = ":/src/bg_circuit.png";   //背景图片路径
    QPixmap pixmap_Background;
    bool ret = pixmap_Background.load(pix_Background);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }
    painter.drawPixmap(0, 0, this->width(), this->height(), pix_Background);
}
