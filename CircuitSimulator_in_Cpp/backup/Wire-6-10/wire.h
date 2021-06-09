#ifndef WIRE_H
#define WIRE_H

#include <QGraphicsLineItem>
#include <QPainter>
#include "pin-to-node/G_Wire.h"

class Wire : public QGraphicsLineItem
{
    Q_OBJECT

public:
    Wire(QGraphicsItem *parent = nullptr);
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
    void reflash_G_Wire(int x1, int y1, int x2, int y2);
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
    void resetG_Wire(int p1_x, int p1_y, int p2_x, int p2_y);

};

#endif // WIRE_H
