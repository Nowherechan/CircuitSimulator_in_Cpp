/**
  * baselogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an abstract logic gate
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "baselogicgate.h"
#include "circuitmap.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

baselogicgate::baselogicgate(int iniN)
{
    n = iniN;
    kind = 0x000;
}

int baselogicgate::type() const
{
    return baselogicgate::UserType + 1;
}

int baselogicgate::getKind()
{
    return kind;
}

int baselogicgate::getN()
{
    return n;
}

void baselogicgate::setN(int newN)
{
    this->n = newN;
}

QVector< QPair<int, int> > baselogicgate::getInputPin()
{
    return inputPinPosition;
}

QVector< QPair<int, int> > baselogicgate::getOutputPin()
{
    return outputPinPosition;
}

void baselogicgate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);

    //元件防止移出界面
    if(x() < 10)
        setPos(10, y());
    if(x() > CircuitMap::MAP_WIDTH - width - lineWidth*2 - 10)
        setPos(CircuitMap::MAP_WIDTH - width - lineWidth*2 - 10, y());
    if(y() < 10)
        setPos(x(), 10);
    if(y() > CircuitMap::MAP_HEIGHT - height - 10)
        setPos(x(), CircuitMap::MAP_HEIGHT - height - 10);
}

void baselogicgate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);

    //元件置于整点
    int nowX, nowY;
    nowX = x();
    nowY = y();
    int beforeX, afterX, beforeY, afterY, dx, dy;
    beforeX = nowX / 10 * 10;
    afterX = beforeX + 10;
    beforeY = nowY / 10 * 10;
    afterY = beforeY + 10;
    dx = nowX - beforeX;
    dy = nowY - beforeY;
    dx <= 5 ? setPos(beforeX, y()) : setPos(afterX, y());
    dy <= 5 ? setPos(x(), beforeY) : setPos(x(), afterY);
}

void baselogicgate::setIntPos(QPointF p)
{
    qreal nowX = p.x();
    qreal nowY = p.y();
    //防出界
    if(nowX < 10)
        nowX = 10;
    if(nowX > CircuitMap::MAP_WIDTH - width - lineWidth*2 - 10)
        nowX = CircuitMap::MAP_WIDTH - width - lineWidth*2 - 10;
    if(nowY < 10)
        nowY = 10;
    if(nowY > CircuitMap::MAP_HEIGHT - height - 10)
        nowY = CircuitMap::MAP_HEIGHT - height - 10;
    //设整点
    int beforeX, afterX, beforeY, afterY, dx, dy;
    beforeX = (int)nowX / 10 * 10;
    afterX = beforeX + 10;
    beforeY = (int)nowY / 10 * 10;
    afterY = beforeY + 10;
    //qDebug() << beforeX << " " << afterX << " " << beforeY << " " << afterY;
    dx = nowX - beforeX;
    dy = nowY - beforeY;
    if(dx <= 5)
        nowX = beforeX;
    else
        nowX = afterX;
    if(dy <= 5)
        nowY = beforeY;
    else
        nowY = afterY;
    //qDebug() << nowX << "" << nowY;
    QPointF p2 = QPointF(nowX, nowY);
    setPos(p2);
}
