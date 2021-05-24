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

    //引脚数
    int n = 3;
    int getN(int n);

private:
    QPoint position;
};

#endif // ANDLOGICGATE_H
