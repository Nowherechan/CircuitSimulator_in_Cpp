#include "circuitmap.h"
#include "ui_circuitmap.h"
#include <QPainter>
#include <QDebug>

CircuitMap::CircuitMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CircuitMap)
{
    ui->setupUi(this);
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
