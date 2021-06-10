#ifndef SWITCHCLOSE_H
#define SWITCHCLOSE_H
#include<QGraphicsItem>
#include"baseelement.h"

class switchClose:public baseElement
{
public:
    switchClose();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    //填充边缘坐标信息
    void fillPosition();

private:
    QPoint position;
};

#endif // SWITCHCLOSE_H
