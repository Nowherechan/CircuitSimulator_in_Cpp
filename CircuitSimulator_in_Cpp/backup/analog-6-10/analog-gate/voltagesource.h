#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H
#include<QGraphicsItem>
#include"baseelement.h"

class voltageSource:public baseElement
{
public:
    voltageSource(int inuv=0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    //获得值
    int getU_Value();
    //设置电压
    void setU_Value(int newU_Value);

protected:
    //填充边缘坐标信息
    void fillPosition();
    int u_value;

private:
    QPoint position;
};

#endif // VOLTAGESOURCE_H
