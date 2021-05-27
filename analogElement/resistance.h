#ifndef RESISTANCE_H
#define RESISTANCE_H
#include<QGraphicsItem>
#include"baseelement.h"

class resistance:public baseElement
{
public:
    resistance(int inrv=0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    //获得值
    int getR_Value();
    //设置电阻值
    void setR_Value(int newR_Value);

protected:
    //填充边缘坐标信息
    void fillPosition();
    int r_value;

private:
    QPoint position;
};

#endif // RESISTANCE_H
