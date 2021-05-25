/**
  * orlogicgate.cpp
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

int orLogicGate::getN(int n){
    return n;
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
    switch(n)
    {
    case 2:
        painter->drawLine(baseX,
                          baseY + 20,
                          baseX + lineWidth,
                          baseY + 20);
        painter->drawLine(baseX,
                          baseY + 80,
                          baseX + lineWidth,
                          baseY + 80);
        break;
    case 3:
        painter->drawLine(baseX,
                          baseY + height/4,
                          baseX + lineWidth,
                          baseY + height/4);
        painter->drawLine(baseX,
                          baseY + height/2,
                          baseX + lineWidth,
                          baseY + height/2);
        painter->drawLine(baseX,
                          baseY + height*3/4,
                          baseX + lineWidth,
                          baseY + height*3/4);
        break;
    case 4:
        painter->drawLine(baseX,
                          baseY + height/5,
                          baseX + lineWidth,
                          baseY + height/5);
        painter->drawLine(baseX,
                          baseY + height*2/5,
                          baseX + lineWidth,
                          baseY + height*2/5);
        painter->drawLine(baseX,
                          baseY + height*3/5,
                          baseX + lineWidth,
                          baseY + height*3/5);
        painter->drawLine(baseX,
                          baseY + height*4/5,
                          baseX + lineWidth,
                          baseY + height*4/5);
        break;
    case 5:
        painter->drawLine(baseX,
                          baseY + (height-4)/6,
                          baseX + lineWidth,
                          baseY + (height-4)/6);
        painter->drawLine(baseX,
                          baseY + (height-4)/3,
                          baseX + lineWidth,
                          baseY + (height-4)/3);
        painter->drawLine(baseX,
                          baseY + (height-4)/2,
                          baseX + lineWidth,
                          baseY + (height-4)/2);
        painter->drawLine(baseX,
                          baseY + (height-4)*2/3,
                          baseX + lineWidth,
                          baseY + (height-4)*2/3);
        painter->drawLine(baseX,
                          baseY + (height-4)*5/6,
                          baseX + lineWidth,
                          baseY + (height-4)*5/6);
        break;
    case 6:
        painter->drawLine(baseX,
                          baseY + (height-2)/7,
                          baseX + lineWidth,
                          baseY + (height-2)/7);
        painter->drawLine(baseX,
                          baseY + (height-2)*2/7,
                          baseX + lineWidth,
                          baseY + (height-2)*2/7);
        painter->drawLine(baseX,
                          baseY + (height-2)*3/7,
                          baseX + lineWidth,
                          baseY + (height-2)*3/7);
        painter->drawLine(baseX,
                          baseY + (height-2)*4/7,
                          baseX + lineWidth,
                          baseY + (height-2)*4/7);
        painter->drawLine(baseX,
                          baseY + (height-2)*5/7,
                          baseX + lineWidth,
                          baseY + (height-2)*5/7);
        painter->drawLine(baseX,
                          baseY + (height-2)*6/7,
                          baseX + lineWidth,
                          baseY + (height-2)*6/7);
        break;
    case 7:
        painter->drawLine(baseX,
                          baseY + height/8,
                          baseX + lineWidth,
                          baseY + height/8);
        painter->drawLine(baseX,
                          baseY + height/4,
                          baseX + lineWidth,
                          baseY + height/4);
        painter->drawLine(baseX,
                          baseY + height*3/8,
                          baseX + lineWidth,
                          baseY + height*3/8);
        painter->drawLine(baseX,
                          baseY +  height/2,
                          baseX + lineWidth,
                          baseY +  height/2);
        painter->drawLine(baseX,
                          baseY +  height*5/8,
                          baseX + lineWidth,
                          baseY +  height*5/8);
        painter->drawLine(baseX,
                          baseY +  height*6/8,
                          baseX + lineWidth,
                          baseY +  height*6/8);
        painter->drawLine(baseX,
                          baseY +  height*7/8,
                          baseX + lineWidth,
                          baseY +  height*7/8);
        break;
    case 8:
        painter->drawLine(baseX,
                          baseY +  (height-1)/9,
                          baseX + lineWidth,
                          baseY +  (height-1)/9);
        painter->drawLine(baseX,
                          baseY +  (height-1)*2/9,
                          baseX + lineWidth,
                          baseY +  (height-1)*2/9);
        painter->drawLine(baseX,
                          baseY +  (height-1)*3/9,
                          baseX + lineWidth,
                          baseY +  (height-1)*3/9);
        painter->drawLine(baseX,
                          baseY +  (height-1)*4/9,
                          baseX + lineWidth,
                          baseY +  (height-1)*4/9);
        painter->drawLine(baseX,
                          baseY +  (height-1)*5/9,
                          baseX + lineWidth,
                          baseY +  (height-1)*5/9);
        painter->drawLine(baseX,
                          baseY +  (height-1)*6/9,
                          baseX + lineWidth,
                          baseY +  (height-1)*6/9);
        painter->drawLine(baseX,
                          baseY +  (height-1)*7/9,
                          baseX + lineWidth,
                          baseY +  (height-1)*7/9);
        painter->drawLine(baseX,
                          baseY +  (height-1)*8/9,
                          baseX + lineWidth,
                          baseY +  (height-1)*8/9);
        break;
    default:
        break;
    }

    //画输出引脚
    painter->drawLine(baseX + lineWidth + width,
                      baseY + height/2,
                      baseX + lineWidth + width + lineWidth,
                      baseY + height/2);
}
