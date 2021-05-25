#ifndef XNORLOGICGATE_H
#define XNORLOGICGATE_H
#include"baselogicgate.h"
#include <QGraphicsItem>

class xnorLogicGate:public baselogicgate
{
public:
    xnorLogicGate();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
     QPoint position;
};

#endif // XNORLOGICGATE_H
