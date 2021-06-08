#include "wire.h"
#include "circuitmap.h"
#include "pin-to-node/G_Wire.h"
#include <QDebug>

/*QPoint modify(QPoint point_1)
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
}*/

Wire::Wire()
{
    penGray = new QPen(GRAY);
    penGray->setWidth(2);
    setPen(*penGray);
    penGreen = new QPen(GREEN);
    penGreen->setWidth(2);

    g_w = new G_Wire(1, 1, 1, 1);

    //置于整点
    /*point_1 = modify(point_1);
    point_2 = modify(point_2);

    QLineF l;
    QPoint p1, p2, p_min;
    p_min = QPoint(std::min(point_1.x(), point_2.x()), std::min(point_1.y(), point_2.y()));
    p1 = QPoint(point_1.x() - p_min.x(), point_1.y() - p_min.y());
    p2 = QPoint(point_2.x() - p_min.x(), point_2.y() - p_min.y());

    l.setP1(p1);
    l.setP2(p2);
    setLine(l);
    setPos(p_min);*/
    //connectedA = false;
    //connectedB = false;
    value = false;
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    calculateSize();
}

int Wire::type() const
{
    return UserType + 2;
}

void Wire::calculateSize()
{
    QLineF l = this->line();
    width = std::abs(l.p1().x() - l.p2().x());
    height = std::abs(l.p1().y() - l.p2().y());
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

void Wire::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsLineItem::mouseMoveEvent(event);

    //元件防止移出界面
    QLineF l = this->line(), nextL;
    int x = std::min(l.p1().x(), l.p2().x());
    int y = std::min(l.p1().y(), l.p2().y());
    bool x_P1LessThanP2 = l.p1().x() < l.p2().x();
    bool y_P1LessThanP2 = l.p1().y() < l.p2().y();
    int p1_x, p1_y, p2_x, p2_y;
    if(x < 10)
        x = 10;
    if(x > CircuitMap::MAP_WIDTH - width - 10)
        x = CircuitMap::MAP_WIDTH - width - 10;
    if(y < 10)
        y = 10;
    if(y > CircuitMap::MAP_HEIGHT - height - 10)
        y = CircuitMap::MAP_HEIGHT - height - 10;
    if(x_P1LessThanP2)
    {
        p1_x = x;
        p2_x = x + width;
    }
    else
    {
        p2_x = x;
        p1_x = x + width;
    }
    if(y_P1LessThanP2)
    {
        p1_y = y;
        p2_y = y + height;
    }
    else
    {
        p2_y = y;
        p1_y = y + height;
    }
    nextL.setP1(QPoint(p1_x, p1_y));
    nextL.setP2(QPoint(p2_x, p2_y));
    setLine(nextL);
    qDebug() << nextL;
}

void Wire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsLineItem::mouseReleaseEvent(event);

    //元件置于整点
    int nowX, nowY;
    nowX = x();
    nowY = y();
    //qDebug() << nowX << nowY << " before change";
    int beforeX, afterX, beforeY, afterY, dx, dy;
    beforeX = nowX / 10 * 10;
    afterX = beforeX + 10;
    beforeY = nowY / 10 * 10;
    afterY = beforeY + 10;
    dx = nowX - beforeX;
    dy = nowY - beforeY;
    dx <= 5 ? setPos(beforeX, y()) : setPos(afterX, y());
    dy <= 5 ? setPos(x(), beforeY) : setPos(x(), afterY);
    //qDebug() << x() << y() << " after change";
    //g_w同步坐标
    delete g_w;
    QLineF l = line();
    QPointF p1 = l.p1();
    p1 += mapToParent(pos());
    QPointF p2 = l.p2();
    p2 += mapToParent(pos());
    g_w = new G_Wire((int)p1.x()/10, (int)p1.y()/10, (int)p2.x()/10, (int)p2.y()/10);
    //qDebug() << (int)p1.x()/10 << (int)p1.y()/10 << (int)p2.x()/10 << (int)p2.y()/10;
}

void Wire::setIntP1(QPointF p)
{
    qreal nowX = p.x();
    qreal nowY = p.y();
    //防出界
    if(nowX < 10)
        nowX = 10;
    if(nowX > CircuitMap::MAP_WIDTH - 10)
        nowX = CircuitMap::MAP_WIDTH - 10;
    if(nowY < 10)
        nowY = 10;
    if(nowY > CircuitMap::MAP_HEIGHT - 10)
        nowY = CircuitMap::MAP_HEIGHT - 10;
    //设整点
    int beforeX, afterX, beforeY, afterY, dx, dy;
    beforeX = (int)nowX / 10 * 10;
    afterX = beforeX + 10;
    beforeY = (int)nowY / 10 * 10;
    afterY = beforeY + 10;
    //qDebug() << beforeX << " " << afterX << " " << beforeY << " " << afterY;
    dx = nowX - beforeX;
    dy = nowY - beforeY;
    if(dx <= 5)
        nowX = beforeX;
    else
        nowX = afterX;
    if(dy <= 5)
        nowY = beforeY;
    else
        nowY = afterY;
    //g_w同步坐标
    Pin pin2 = g_w->get_pin2();
    delete g_w;
    g_w = new G_Wire((int)nowX/10, (int)nowY/10, pin2.x, pin2.y);
    QPointF p2 = QPointF(nowX, nowY);
    QLineF l = line();
    l.setP1(p2);
    setLine(l);
    calculateSize();
}

void Wire::setIntP2(QPointF p)
{
    qreal nowX = p.x();
    qreal nowY = p.y();
    //防出界
    if(nowX < 10)
        nowX = 10;
    if(nowX > CircuitMap::MAP_WIDTH - 10)
        nowX = CircuitMap::MAP_WIDTH - 10;
    if(nowY < 10)
        nowY = 10;
    if(nowY > CircuitMap::MAP_HEIGHT - 10)
        nowY = CircuitMap::MAP_HEIGHT - 10;
    //设整点
    int beforeX, afterX, beforeY, afterY, dx, dy;
    beforeX = (int)nowX / 10 * 10;
    afterX = beforeX + 10;
    beforeY = (int)nowY / 10 * 10;
    afterY = beforeY + 10;
    //qDebug() << beforeX << " " << afterX << " " << beforeY << " " << afterY;
    dx = nowX - beforeX;
    dy = nowY - beforeY;
    if(dx <= 5)
        nowX = beforeX;
    else
        nowX = afterX;
    if(dy <= 5)
        nowY = beforeY;
    else
        nowY = afterY;
    //g_w同步坐标
    Pin pin1 = g_w->get_pin1();
    delete g_w;
    g_w = new G_Wire(pin1.x, pin1.y, (int)nowX/10, (int)nowY/10);
    QPointF p2 = QPointF(nowX, nowY);
    QLineF l = line();
    l.setP2(p2);
    setLine(l);
    calculateSize();
}

Wire::~Wire()
{
    delete g_w;
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

//void Wire::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    QGraphicsLineItem::mouseMoveEvent(event);

//    QLineF thisLine = line();
//    int width = std::abs(thisLine.x1() - thisLine.x2());
//    int height = std::abs(thisLine.y1() - thisLine.y2());

//    if(x() < 10)
//        setPos(10, y());
//    if(x() > CircuitMap::MAP_WIDTH - width - 10)
//        setPos(CircuitMap::MAP_WIDTH - width - 10, y());
//    if(y() < 10)
//        setPos(x(), 10);
//    if(y() > CircuitMap::MAP_HEIGHT - height - 10)
//        setPos(x(), CircuitMap::MAP_HEIGHT - height - 10);
//}

//void Wire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    QGraphicsLineItem::mouseReleaseEvent(event);

//    //元件置于整点
//    int nowX, nowY;
//    nowX = x();
//    nowY = y();
//    int beforeX, afterX, beforeY, afterY, dx, dy;
//    beforeX = nowX / 10 * 10;
//    afterX = beforeX + 10;
//    beforeY = nowY / 10 * 10;
//    afterY = beforeY + 10;
//    dx = nowX - beforeX;
//    dy = nowY - beforeY;
//    dx <= 5 ? setPos(beforeX, y()) : setPos(afterX, y());
//    dy <= 5 ? setPos(x(), beforeY) : setPos(x(), afterY);
//}
