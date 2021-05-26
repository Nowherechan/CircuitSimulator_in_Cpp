#ifndef SWITCHOPEN_H
#define SWITCHOPEN_H
#include<QGraphicsItem>
#include"baseelement.h"

class switchOpen:public baseElement
{
public:
    switchOpen();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    //填充边缘坐标信息
    void fillPosition();

private:
    QPoint position;
};

#endif // SWITCHOPEN_H
