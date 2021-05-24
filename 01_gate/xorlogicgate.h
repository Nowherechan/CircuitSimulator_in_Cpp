#ifndef XORLOGICGATE_H
#define XORLOGICGATE_H
#include"baselogicgate.h"
#include <QGraphicsItem>

class XorLogicGate:public baselogicgate
{
public:
    XorLogicGate();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
     QPoint position;
};

#endif // ANDLOGICGATE_H
