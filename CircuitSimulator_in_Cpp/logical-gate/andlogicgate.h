#ifndef ANDLOGICGATE_H
#define ANDLOGICGATE_H
#include"baselogicgate.h"

#include <QGraphicsItem>

class andLogicGate:public baselogicgate
{
public:
    andLogicGate();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QPoint position;
};

#endif // ANDLOGICGATE_H
