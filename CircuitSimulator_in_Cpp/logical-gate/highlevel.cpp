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
#include "baselogicgate.h"

highLevel::highLevel()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
    nowInput.clear();
    nowOutput.clear();
    nowOutput.push_back(true);
    setN(0);

    kind = 0x001;
}

QVector<bool> highLevel::flash(QVector<bool>)
{
    return nowOutput;
}

void highLevel::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    temp = {baseX + 100, baseY + 30};
    outputPinPosition.push_back(temp);
}

QRectF highLevel::boundingRect() const
{
    return QRectF(0,0,100,60);
}

void highLevel::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    int baseX = position.x();
    int baseY = position.y();

    QPen penGreenPin = QPen(baselogicgate::GREEN);
        penGreenPin.setWidth(2);
        painter->setPen(penGreenPin);

    //画主体
    painter->drawText(baseX + 10,
                      baseY + 30,
                      "1");
    painter->drawLine(baseX+30,
                      baseY+30,
                      baseX+94.5,
                      baseY+30);
    //画圈
    painter->drawEllipse(baseX+95,baseY+27.5,5,5);
}
