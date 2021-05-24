#include "nonlogicgate.h"

nonLogicGate::nonLogicGate()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
}

 QRectF nonLogicGate::boundingRect() const
 {
     return QRectF(0,0,100,100);
 }

void nonLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
                     "1");
    painter->setPen(QPen(QColor(0,0,0)));

    //画输入引脚
    painter->drawLine(baseX,
                      baseY + height/2,
                      baseX + lineWidth,
                      baseY + height/2);
    //画输出引脚
    painter->drawLine(baseX + lineWidth + width+5,
                     baseY + height/2,
                     baseX + lineWidth + width + lineWidth,
                     baseY + height/2);
    //画圈
    painter->drawEllipse(baseX+lineWidth+width,baseY+height/2-2.5,5,5);
}
