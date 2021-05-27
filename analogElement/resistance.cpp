#include "resistance.h"

void resistance::setR_Value(int newR_Value)
{
    this->r_value = newR_Value;
}

int resistance::getR_Value()
{
    return r_value;
}

void resistance::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    temp = {baseX, baseY+50};
    inputPinPosition.push_back(temp);
    temp = {baseX+100, baseY + 50};
    inputPinPosition.push_back(temp);
}

resistance::resistance(int inrv)
{
    r_value = inrv;
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
}

QRectF resistance::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void resistance::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int baseX = position.x();
    int baseY = position.y();

    //画主体
    painter->drawRect(QRect(baseX+30,
                            baseY+40,
                            40,
                            20));
    //画输入导线
    painter->drawLine(baseX,
                      baseY+50,
                      baseX+30,
                      baseY+50
                      );
    //画输出导线
    painter->drawLine(baseX+70,
                      baseY+50,
                      baseX+100,
                      baseY+50
                      );
}
