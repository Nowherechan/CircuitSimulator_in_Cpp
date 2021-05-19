/**
  * circuitmap.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     a map of circuit.
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     1.Finish the show-all button.
  *     2.Complete the actions of components, like put-on , delete and move.
  *     3.Matrix of the can-put points.
  */
#include "circuitmap.h"
#include "ui_circuitmap.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsView>
#include <QSlider>

//画可放元件的点阵
void CircuitMap::drawDots_Map()
{
    QPainter painter(this);
    QPen pen(QColor(200, 200, 200));
    pen.setWidth(2);
    painter.setPen(pen);
}

CircuitMap::CircuitMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CircuitMap)
{
    ui->setupUi(this);

    //设置滑动条与数值框
    ui->slider_Zoom->setRange(10, 100);
    ui->slider_Zoom->setSingleStep(10);
    ui->slider_Zoom->setTickInterval(30);
    ui->slider_Zoom->setTickPosition(QSlider::TicksAbove);
    ui->slider_Zoom->setValue(50);
    ui->spinBox_Zoom->setRange(10, 100);
    ui->spinBox_Zoom->setSingleStep(10);
    ui->spinBox_Zoom->setValue(50);
    connect(ui->slider_Zoom, &QSlider::valueChanged, ui->spinBox_Zoom, [=](){
        int v = ui->slider_Zoom->value();
        v = (v + 5) / 10 * 10;
        ui->spinBox_Zoom->setValue(v);
        ui->slider_Zoom->setValue(v);
        zoom = v;
    });
    connect(ui->spinBox_Zoom, &QSpinBox::textChanged, ui->slider_Zoom, [=](){
        int v = ui->spinBox_Zoom->value();
        ui->slider_Zoom->setValue(v);
        zoom = v;
    });
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
