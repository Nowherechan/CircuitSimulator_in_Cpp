/**
  * baselogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an or logic gate
  * bug:(when one bug was fixed, marked it with '~')
  * ~   1. Function boundingRect() return wrong QRectF(0,0,50,50)
  *         Fix: Turn it into QRectF(0,0,100,100).
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "orlogicgate.h"

orLogicGate::orLogicGate()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
}

QRectF orLogicGate::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void orLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int baseX = position.x();
    int baseY = position.y();

    //画主体
    painter->drawRect(QRect(baseX + lineWidth,
                            baseY,
                            width,
                            height));
    painter->drawText(baseX + 40,
                      baseY + 40,
                      "≥1");
    painter->setPen(QPen(QColor(0,0,0)));

    //画输入引脚
    painter->drawLine(baseX,
                      baseY + 20,
                      baseX + lineWidth,
                      baseY + 20);
    painter->drawLine(baseX,
                      baseY + 80,
                      baseX + lineWidth,
                      baseY + 80);
    //画输出引脚
    painter->drawLine(baseX + lineWidth + width,
                      baseY + height/2,
                      baseX + lineWidth + width + lineWidth,
                      baseY + height/2);
}
