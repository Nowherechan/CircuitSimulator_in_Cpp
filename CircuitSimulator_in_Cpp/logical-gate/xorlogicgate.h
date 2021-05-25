#ifndef XORLOGICGATE_H
#define XORLOGICGATE_H
#include"baselogicgate.h"
#include <QGraphicsItem>

class xorLogicGate:public baselogicgate
{
public:
    xorLogicGate();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
     QPoint position;
};

#endif // XORLOGICGATE_H
