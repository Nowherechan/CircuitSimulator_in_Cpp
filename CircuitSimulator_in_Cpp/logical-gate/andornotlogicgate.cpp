/**
  * andornotlogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an and-or-not logic gate
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "andornotlogicgate.h"

andOrNotLogicGate::andOrNotLogicGate()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
}

 QRectF andOrNotLogicGate::boundingRect() const
 {
     return QRectF(0,0,100,100);
 }

 void andOrNotLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     int baseX = position.x();
     int baseY = position.y();

      int getN(int n);

     //画主体
     painter->drawRect(QRect(baseX + lineWidth,
                            baseY,
                            width,
                            height));
     painter->drawLine(baseX+lineWidth,
                      baseY + height/2,
                      baseX + lineWidth+width/2,
                      baseY + height/2);
     painter->drawLine(baseX+lineWidth+width/2,
                      baseY ,
                      baseX + lineWidth+width/2,
                      baseY + height);
     painter->drawText(baseX + 25,
                      baseY + 25,
                      "&");
     painter->drawText(baseX + 51,
                      baseY + 25,
                      "≥1");
     painter->setPen(QPen(QColor(0,0,0)));

     //画输入引脚
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
     //画输出引脚
     painter->drawLine(baseX + lineWidth + width+5,
                      baseY + height/2,
                      baseX + lineWidth + width + lineWidth,
                      baseY + height/2);
     //画圈
     painter->drawEllipse(baseX+lineWidth+width,baseY+height/2-2.5,5,5);
 }
