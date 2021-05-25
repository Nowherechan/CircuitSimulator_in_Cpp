/**
  * xorlogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an and-or-not logic gate
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "xorlogicgate.h"

XorLogicGate::XorLogicGate()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
}

QRectF XorLogicGate::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void XorLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int baseX = position.x();
    int baseY = position.y();

    int getN(int n);

    //画主体
    painter->drawRect(QRect(baseX + lineWidth,
                            baseY,
                            width,
                            height));
    painter->drawText(baseX + 40,
                      baseY + 40,
                      "=1");
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
