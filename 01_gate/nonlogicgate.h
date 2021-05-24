#ifndef NONLOGICGATE_H
#define NONLOGICGATE_H
#include"baselogicgate.h"
#include <QGraphicsItem>

class nonLogicGate:public baselogicgate
{
public:
    nonLogicGate();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
     QPoint position;
};

#endif // NONLOGICGATE_H
