#include "wire.h"
#include "circuitmap.h"
#include <QDebug>

QPoint modify(QPoint point_1)
{
    int nowX, nowY;
    nowX = point_1.x();
    nowY = point_1.y();
    int beforeX, afterX, beforeY, afterY, dx, dy;
    beforeX = nowX / 10 * 10;
    afterX = beforeX + 10;
    beforeY = nowY / 10 * 10;
    afterY = beforeY + 10;
    dx = nowX - beforeX;
    dy = nowY - beforeY;
    dx <= 5 ? point_1.setX(beforeX) : point_1.setY(afterX);
    dy <= 5 ? point_1.setY(beforeY) : point_1.setY(afterY);
    return point_1;
}

void Wire::setP1(QPoint point_1)
{
    point_1 = modify(point_1);
    QLineF l = line();
    l.setP1(point_1);
    setLine(l);
}

void Wire::setP2(QPoint point_2)
{
    point_2 = modify(point_2);
    QLineF l = line();
    l.setP2(point_2);
    setLine(l);
}

Wire::Wire(QPoint point_1, QPoint point_2)
{
    penGray = new QPen(GRAY);
    penGray->setWidth(2);
    setPen(*penGray);
    penGreen = new QPen(GREEN);
    penGreen->setWidth(2);

    //置于整点
    point_1 = modify(point_1);
    point_2 = modify(point_2);

    QLineF l;
    QPoint p1, p2, p_min;
    p_min = QPoint(std::min(point_1.x(), point_2.x()), std::min(point_1.y(), point_2.y()));
    p1 = QPoint(point_1.x() - p_min.x(), point_1.y() - p_min.y());
    p2 = QPoint(point_2.x() - p_min.x(), point_2.y() - p_min.y());

    l.setP1(p1);
    l.setP2(p2);
    setLine(l);
    setPos(p_min);
    //connectedA = false;
    //connectedB = false;
    value = false;
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
}

int Wire::getValue()
{
    return value;
}
void Wire::setValue(bool statue)
{
    value = statue;
    if(value)
        setPen(*penGreen);
    else
        setPen(*penGray);
}

//QRectF Wire::boundingRect() const
//{
//    int AX = pointA.x();
//    int AY = pointA.y();
//    int BX = pointB.x();
//    int BY = pointB.y();
//    if(AX > BX)
//        std::swap(AX, BX);
//    if(AY > BY)
//        std::swap(AY, BY);
//    return QRectF(AX, AY, BX, BY);
//}

//void Wire::setPointA(QPoint p)
//{
//    pointA = p;
//}

//void Wire::setPointB(QPoint p)
//{
//    pointB = p;
//}

//QPoint Wire::getPointA()
//{
//    return pointA;
//}

//QPoint Wire::getPointB()
//{
//    return pointB;
//}

//void Wire::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
//{
//    int XA = pointA.x();
//    int YA = pointA.y();
//    int XB = pointB.x();
//    int YB = pointB.y();

//    //导线绘制设置
//    QPen penWireGray = QPen(GRAY);
//    penWireGray.setWidth(2);
//    QPen penWireGreen = QPen(GREEN);
//    penWireGreen.setWidth(2);
//    painter->setPen(penWireGray);

//    painter->drawLine(XA, YA, XB, YB);
//}

void Wire::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsLineItem::mouseMoveEvent(event);

    QLineF thisLine = line();
    int width = std::abs(thisLine.x1() - thisLine.x2());
    int height = std::abs(thisLine.y1() - thisLine.y2());

    if(x() < 10)
        setPos(10, y());
    if(x() > CircuitMap::MAP_WIDTH - width - 10)
        setPos(CircuitMap::MAP_WIDTH - width - 10, y());
    if(y() < 10)
        setPos(x(), 10);
    if(y() > CircuitMap::MAP_HEIGHT - height - 10)
        setPos(x(), CircuitMap::MAP_HEIGHT - height - 10);
}

void Wire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsLineItem::mouseReleaseEvent(event);

    //元件置于整点
    int nowX, nowY;
    nowX = x();
    nowY = y();
    int beforeX, afterX, beforeY, afterY, dx, dy;
    beforeX = nowX / 10 * 10;
    afterX = beforeX + 10;
    beforeY = nowY / 10 * 10;
    afterY = beforeY + 10;
    dx = nowX - beforeX;
    dy = nowY - beforeY;
    dx <= 5 ? setPos(beforeX, y()) : setPos(afterX, y());
    dy <= 5 ? setPos(x(), beforeY) : setPos(x(), afterY);
}
