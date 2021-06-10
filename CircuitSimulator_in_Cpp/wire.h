#ifndef WIRE_H
#define WIRE_H

#include <QGraphicsLineItem>
#include <QPainter>
#include "pin-to-node/G_Wire.h"

class Wire : public QGraphicsLineItem
{
private:
    const QColor GRAY = QColor(100, 100, 100);
    const QColor GREEN = QColor(0, 200, 0);
    QPen * penGray;
    QPen * penGreen;
    bool value;
    int width, height;
    int cache_x_1, cache_y_1, cache_x_2, cache_y_2;

public:
    Wire(QGraphicsItem *parent = nullptr);
    int getValue();
    void setValue(bool statue);
    void setIntP1(QPointF p);
    void setIntP2(QPointF p);
    int type() const override;
    G_Wire* g_w;
    void reflash_G_Wire();
    ~Wire();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void calculateSize();

};

#endif // WIRE_H
