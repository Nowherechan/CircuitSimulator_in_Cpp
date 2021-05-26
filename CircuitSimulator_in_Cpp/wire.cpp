#include "wire.h"

Wire::Wire(QPoint point_1, QPoint point_2)
{
    QPen pen(GRAY);
    pen.setWidth(2);
    setPen(pen);
    QLineF l;
    l.setP1(point_1);
    l.setP2(point_2);
    setLine(l);
    connectedA = false;
    connectedB = false;
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
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
}

void Wire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsLineItem::mouseReleaseEvent(event);
}
