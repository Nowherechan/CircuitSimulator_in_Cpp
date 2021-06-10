#ifndef CURRENTSOURCE_H
#define CURRENTSOURCE_H
#include<QGraphicsItem>
#include"baseelement.h"

class currentSource:public baseElement
{
public:
    currentSource(int inav=0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    //获得值
    int getA_Value();
    //设置电流
    void setA_Value(int newA_Value);
protected:
    //填充边缘坐标信息
    void fillPosition();
    int a_value;

private:
    QPoint position;
};

#endif // CURRENTSOURCE_H
