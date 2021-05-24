#ifndef ORLOGICGATE_H
#define ORLOGICGATE_H

#include"baselogicgate.h"

#include <QGraphicsItem>

class orLogicGate:public baselogicgate
{
public:
    orLogicGate();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    int n;
    int getN(int n);

private:
    QPoint position;
};

#endif // ANDLOGICGATE_H
