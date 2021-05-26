#ifndef NORLOGICGATE_H
#define NORLOGICGATE_H
#include"baselogicgate.h"
#include <QGraphicsItem>

class norLogicGate:public baselogicgate
{
public:
    norLogicGate();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    //引脚数
    int n = 2;
    int getN(int n);
private:
     QPoint position;
};

#endif // NORLOGICGATE_H

