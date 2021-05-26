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

baselogicgate::baselogicgate(int iniN)
{
    n = iniN;
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
