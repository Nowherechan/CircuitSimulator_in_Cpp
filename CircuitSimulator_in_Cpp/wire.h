#ifndef WIRE_H
#define WIRE_H

#include <QGraphicsLineItem>
#include <QPainter>
#include "pin-to-node/G_Wire.h"

class Wire : public QGraphicsLineItem
{
public:
    Wire();
    int getValue();
    void setValue(bool statue);
    void setIntP1(QPointF p);
    void setIntP2(QPointF p);
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    //void setPointA(QPoint p);
    //void setPointB(QPoint p);
    //QPoint getPointA();
    //QPoint getPointB();
    int type() const override;
    G_Wire* g_w;
    ~Wire();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void calculateSize();

private:
    //QPoint pointA, pointB;
    //bool connectedA, connectedB;
    //const QColor BLACK = QColor(0, 0, 0);
    const QColor GRAY = QColor(100, 100, 100);
    const QColor GREEN = QColor(0, 200, 0);
    //const QColor RED = QColor(200, 0, 0);
    QPen * penGray;
    QPen * penGreen;
    bool value;
    int width, height;

signals:
    void remove();

};

#endif // WIRE_H
