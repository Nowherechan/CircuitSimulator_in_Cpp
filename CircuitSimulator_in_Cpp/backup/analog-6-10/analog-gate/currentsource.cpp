#include "currentsource.h"

//void currentSource::setValue(int newValue)
//{
//    value = newValue;
//}

void currentSource::setA_Value(int newR_Value)
{
    this->a_value = newR_Value;
}

int currentSource::getA_Value()
{
    return a_value;
}

void currentSource::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    temp = {baseX+50, baseY};
    inputPinPosition.push_back(temp);
    temp = {baseX+50, baseY + 100};
    inputPinPosition.push_back(temp);
}

currentSource::currentSource(int inav)
{
    a_value = inav;
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
}

QRectF currentSource::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void currentSource::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int baseX = position.x();
    int baseY = position.y();
    //画主体
    painter->drawEllipse(baseX+20,baseY+20,60,60);
    painter->drawLine(baseX+20,
                      baseY+50,
                      baseX+80,
                      baseY+50);
    painter->drawLine(baseX+50,
                      baseY,
                      baseX+50,
                      baseY+20);
    painter->drawLine(baseX+50,
                      baseY+80,
                      baseX+50,
                      baseY+100);
    painter->drawText(baseX+35,
                      baseY+15,
                      "+"
                      );
    painter->drawText(baseX+35,
                      baseY+95,
                      "-"
                      );
}
