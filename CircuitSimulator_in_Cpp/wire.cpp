#include "wire.h"
#include "circuitmap.h"
#include "pin-to-node/G_Wire.h"
#include <QDebug>

Wire::Wire(QGraphicsItem *parent) : QGraphicsLineItem(parent)
{
    penGray = new QPen(GRAY);
    penGray->setWidth(2);
    setPen(*penGray);
    penGreen = new QPen(GREEN);
    penGreen->setWidth(2);

    g_w = new G_Wire(1, 1, 1, 1);

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
    //qDebug() << nextL << pos();
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
    QLineF l = line();
    QPointF p1 = l.p1();
    //qDebug() << p1;
    p1 = mapToParent(p1);
    QPointF p2 = l.p2();
    //qDebug() << p2;
    p2 = mapToParent(p2);
    //qDebug() << pos() << p1 << p2;
    cache_x_1 = (int)p1.x()/10;
    cache_y_1 = (int)p1.y()/10;
    cache_x_2 = (int)p2.x()/10;
    cache_y_2 = (int)p2.y()/10;
    //qDebug() << (int)p1.x()/10 << (int)p1.y()/10 << (int)p2.x()/10 << (int)p2.y()/10;
}

void Wire::setIntP1(QPointF p)
{
    //qDebug() << p << "setIntP1";
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
    cache_x_1 = (int)nowX/10;
    cache_y_1 = (int)nowY/10;
    QPointF p2 = QPointF(nowX, nowY);
    //qDebug() << p2 << "setIntP1" << cache_x_1 << cache_y_1;
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
    cache_x_2 = (int)nowX/10;
    cache_y_2 = (int)nowY/10;
    //qDebug() << "setp2" << nowX << nowY << pin1.x << pin1.y;
    QPointF p2 = QPointF(nowX, nowY);
    QLineF l = line();
    l.setP2(p2);
    setLine(l);
    calculateSize();
}

void Wire::reflash_G_Wire()
{
    delete g_w;
    //qDebug() << "reflash" << cache_x_1 << cache_y_1;
    g_w = new G_Wire(cache_x_1, cache_y_1, cache_x_2, cache_y_2);
}

Wire::~Wire()
{
    delete g_w;
}
