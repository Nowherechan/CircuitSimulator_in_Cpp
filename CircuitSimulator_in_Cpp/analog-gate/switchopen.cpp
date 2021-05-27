#include "switchopen.h"

void switchOpen::fillPosition()
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

switchOpen::switchOpen()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
}

QRectF switchOpen::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void switchOpen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int baseX = position.x();
    int baseY = position.y();

    //画主体
    //画圆
    painter->drawEllipse(baseX+30,
                         baseY+45,
                         10,
                         10);
    //斜线
    painter->drawLine(baseX+35,
                      baseY+45,
                      baseX+70,
                      baseY+30
                      );
    //水平线
    painter->drawLine(baseX,
                      baseY+50,
                      baseX+30,
                      baseY+50
                      );
    painter->drawLine(baseX+70,
                      baseY+50,
                      baseX+100,
                      baseY+50
                      );

}
