/**
  * highlevel.cpp
  * author@王梦泽
  * function:
  *     highlevel
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "highlevel.h"

QVector< QPair<int, int> > highLevel::getInputPin()
{
    return inputPinPosition;
}

QVector< QPair<int, int> > highLevel::getOutputPin()
{
    return outputPinPosition;
}

highLevel::highLevel()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
}

void highLevel::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    temp = {baseX+100, baseY + 30};
    inputPinPosition.push_back(temp);
    }

QRectF highLevel::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void highLevel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int baseX = position.x();
    int baseY = position.y();

    //画主体
    painter->drawText(baseX + 10,
                      baseY + 30,
                      "1");
    painter->drawLine(baseX+30,
                      baseY+30,
                      baseX+94.5,
                      baseY+30);
    //画圈
    painter->drawEllipse(baseX+95,baseY+30,5,5);
}
