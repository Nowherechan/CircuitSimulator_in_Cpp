#ifndef ANDORNOTLOGICGATE_H
#define ANDORNOTLOGICGATE_H
#include"baselogicgate.h"
#include <QGraphicsItem>


class andOrNotLogicGate:public baselogicgate
{
public:
    andOrNotLogicGate();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
     QPoint position;
};

#endif // ANDORNOTLOGICGATE_H

