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
  * ~   4.Function select().
  */
#include "circuitmap.h"
#include "ui_circuitmap.h"
#include "wire.h"
#include "logical-gate/highlevel.h"
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
#include <QMouseEvent>

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

    //鼠标按下
    connect(ui->map_Circuit, &QGraphicsView_Map::mousePressed, [=](QMouseEvent event){
        select(mod);                                    //阻止新生成的元件移动
        int mouseX = event.x();
        int mouseY = event.y();
        QPoint mouse(mouseX, mouseY);
        QPointF p = ui->map_Circuit->mapToScene(mouse);
        dealPress(p);
    });

    //鼠标移动
    connect(ui->map_Circuit, &QGraphicsView_Map::mouseMoved, [=](QMouseEvent event){
        int mouseX = event.x();
        int mouseY = event.y();
        QPoint mouse(mouseX, mouseY);
        QPointF p = ui->map_Circuit->mapToScene(mouse);
        dealMove(p);
    });

    //鼠标松开
    connect(ui->map_Circuit, &QGraphicsView_Map::mouseReleased, [=](QMouseEvent event){
        w = nullptr;                                    //安全性
        int mouseX = event.x();
        int mouseY = event.y();
        QPoint mouse(mouseX, mouseY);
        QPointF p = ui->map_Circuit->mapToScene(mouse);
        dealRelease(p);
    });
}

void CircuitMap::dealPress(QPointF p)
{
    switch (mod) {
    case CircuitWindow::Select :
        break;

    case CircuitWindow::Wire :
        w = addWire(p, p);
        break;

    case CircuitWindow::HighLevel :
        w = addHighLevel(p);
        break;

    case CircuitWindow::And :
        w = addGateAnd(p);
        break;

    case CircuitWindow::Or :
        w = addGateOr(p);
        break;

    case CircuitWindow::Non :
        w = addGateNon(p);
        break;

    case CircuitWindow::Nand :
        w = addGateNand(p);
        break;

    case CircuitWindow::Nor :
        w = addGateNor(p);
        break;

    case CircuitWindow::AndOrNot :
        w = addGateAndOrNor(p);
        break;

    case CircuitWindow::Xor :
        w = addGateXor(p);
        break;

    case CircuitWindow::Xnor :
        w = addGateXnor(p);
        break;

    default :
        break;
    }
}

//inline QLineF setWire(Wire* w, QPointF p)
//{
//    w->setIntP2(p);
//    l.setP2(p);
//    return l;
//}

void CircuitMap::dealMove(QPointF p)
{
    switch (mod) {
    case CircuitWindow::Select :
        break;

    case CircuitWindow::Wire :
        ((Wire*)w)->setIntP2(p);
        break;

    case CircuitWindow::HighLevel :
        ((highLevel*)w)->setIntPos(p);
        break;

    case CircuitWindow::And :
        ((andLogicGate*)w)->setIntPos(p);
        break;

    case CircuitWindow::Or :
        ((orLogicGate*)w)->setIntPos(p);
        break;

    case CircuitWindow::Non :
        ((nonLogicGate*)w)->setIntPos(p);
        break;

    case CircuitWindow::Nand :
        ((nandLogicGate*)w)->setIntPos(p);
        break;

    case CircuitWindow::Nor :
        ((norLogicGate*)w)->setIntPos(p);
        break;

    case CircuitWindow::AndOrNot :
        ((andOrNotLogicGate*)w)->setIntPos(p);
        break;

    case CircuitWindow::Xor :
        ((xorLogicGate*)w)->setIntPos(p);
        break;

    case CircuitWindow::Xnor :
        ((xnorLogicGate*)w)->setIntPos(p);
        break;

    default :
        break;
    }
}

void CircuitMap::dealRelease(QPointF )
{
//    switch (mod) {
//    case CircuitWindow::Select :
//        break;

//    case CircuitWindow::Wire :
//        //addWire(QPoint(100, 100), QPoint(200, 200));
//        break;

//    case CircuitWindow::HighLevel :
//        //addHighLevel();
//        break;

//    case CircuitWindow::And :
//        //addGateAnd();
//        break;

//    case CircuitWindow::Or :
//        //addGateOr();
//        break;

//    case CircuitWindow::Non :
//        //addGateNon();
//        break;

//    case CircuitWindow::Nand :
//        //addGateNand();
//        break;

//    case CircuitWindow::Nor :
//        //addGateNor();
//        break;

//    case CircuitWindow::AndOrNot :
//        //addGateAndOrNor();
//        break;

//    case CircuitWindow::Xor :
//        //addGateXor();
//        break;

//    case CircuitWindow::Xnor :
//        //addGateXnor();
//        break;

//    default :
//        break;
//    }
}

//画可放元件的点阵图
QPixmap CircuitMap::draw_Dots_Map()
{
    //创建背景图
    QPixmap pix(MAP_WIDTH, MAP_HEIGHT);
    pix.fill(MAP_COLOR);

    //QPainter设置
    QPainter painter(&pix);
    QPen pen(DOTS_COLOR);
    pen.setWidth(2);
    painter.setPen(pen);
    QPen pen_bigger(DOTS_COLOR);
    pen_bigger.setWidth(4);
    //painter.setRenderHint(QPainter::HighQualityAntialiasing);//抗锯齿能力

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

//添加元件图片方法
Wire* CircuitMap::addWire(QPointF A, QPointF B)
{
    Wire *w = new Wire();
    w->setIntP1(A);
    w->setIntP2(B);
    scene->addItem(w);
    w->setFocus();
    return w;
}

highLevel* CircuitMap::addHighLevel(QPointF p)
{
    highLevel *h = new highLevel();
    h->setIntPos(p);
    scene->addItem(h);
    h->setFocus();
    return h;
}

andLogicGate* CircuitMap::addGateAnd(QPointF p)
{
    andLogicGate *g = new andLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

orLogicGate* CircuitMap::addGateOr(QPointF p)
{
    orLogicGate *g = new orLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

nonLogicGate* CircuitMap::addGateNon(QPointF p)
{
    nonLogicGate *g = new nonLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

nandLogicGate* CircuitMap::addGateNand(QPointF p)
{
    nandLogicGate *g = new nandLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

norLogicGate* CircuitMap::addGateNor(QPointF p)
{
    norLogicGate *g = new norLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

andOrNotLogicGate* CircuitMap::addGateAndOrNor(QPointF p)
{
    andOrNotLogicGate *g = new andOrNotLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

xorLogicGate* CircuitMap::addGateXor(QPointF p)
{
    xorLogicGate *g = new xorLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

xnorLogicGate* CircuitMap::addGateXnor(QPointF p)
{
    xnorLogicGate *g = new xnorLogicGate();
    g->setIntPos(p);
    scene->addItem(g);
    g->setFocus();
    return g;
}

//当前选项
void CircuitMap::select(CircuitWindow::component_Selected c)
{
//    //测试函数
//    switch (c) {
//    case CircuitWindow::Select :
//        //
//        break;

//    case CircuitWindow::Wire :
//        //addWire(QPoint(100, 100), QPoint(200, 200));
//        break;

//    case CircuitWindow::HighLevel :
//        //addHighLevel();
//        break;

//    case CircuitWindow::And :
//        //addGateAnd();
//        break;

//    case CircuitWindow::Or :
//        //addGateOr();
//        break;

//    case CircuitWindow::Non :
//        //addGateNon();
//        break;

//    case CircuitWindow::Nand :
//        //addGateNand();
//        break;

//    case CircuitWindow::Nor :
//        //addGateNor();
//        break;

//    case CircuitWindow::AndOrNot :
//        //addGateAndOrNor();
//        break;

//    case CircuitWindow::Xor :
//        //addGateXor();
//        break;

//    case CircuitWindow::Xnor :
//        //addGateXnor();
//        break;

//    default :
//        break;
//    }

    mod = c;
    if(mod == CircuitWindow::Select)
    {
        QList<QGraphicsItem *> itemList = scene->items();
        for(auto i = 0; i < itemList.size(); i++) {
            itemList[i]->setFlag(QGraphicsItem::ItemIsMovable);
        }
    }
    else
    {
        QList<QGraphicsItem *> itemList = scene->items();
        for(auto i = 0; i < itemList.size(); i++) {
            itemList[i]->setFlag(QGraphicsItem::ItemIsMovable, false);
        }
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

//void CircuitMap::mousePressEvent(QMouseEvent *event)
//{
//    QWidget::mousePressEvent(event);

//    if(mod == CircuitWindow::Wire)
//    {
//        connect(ui->map_Circuit, &QGraphicsView_Map::mousePressed, [=](QPoint p1){
//            w = addWire(p1, p1);
//            w->setFlag(QGraphicsItem::ItemIsMovable, false);
//        });
//        connect(ui->map_Circuit, &QGraphicsView_Map::mouseMoved, [=](QPoint p2){
//            if(nullptr != w)
//            {
//                QLineF l = ((Wire*)w)->line();
//                l.setP2(p2);
//                ((Wire *)w)->setLine(l);
//            }
//        });
//    }
//}

//void CircuitMap::mouseMoveEvent(QMouseEvent *event)
//{
//    QWidget::mouseMoveEvent(event);
//}

//void CircuitMap::mouseReleaseEvent(QMouseEvent *event)
//{
//    QWidget::mouseReleaseEvent(event);
//    ui->map_Circuit->disconnect();
//    w = nullptr;

//    if(mod != CircuitWindow::Wire && mod != CircuitWindow::Select)
//    {

//    }
//}
