#include "voltagesource.h"

void voltageSource::setU_Value(int newR_Value)
{
    this->u_value = newR_Value;
}

int voltageSource::getU_Value()
{
    return u_value;
}

void voltageSource::fillPosition()
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

voltageSource::voltageSource(int inuv)
{
    u_value = inuv;
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
}

QRectF voltageSource::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void voltageSource::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int baseX = position.x();
    int baseY = position.y();
    //画主体
    painter->drawEllipse(baseX+20,baseY+20,60,60);
    painter->drawLine(baseX+50,
                      baseY+20,
                      baseX+50,
                      baseY+80);
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
