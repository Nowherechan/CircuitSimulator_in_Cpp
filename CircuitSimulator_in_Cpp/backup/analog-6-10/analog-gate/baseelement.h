#ifndef BASEELEMENT_H
#define BASEELEMENT_H
#include <QPainter>
#include<QGraphicsItem>

class baseElement:public QGraphicsItem
{
public:
    baseElement(int inv=0);
    //获得值
    int getValue();
    //设置值
    void setValue(int newValue);
    //获得引脚坐标
    QVector< QPair<int, int> > getInputPin();
    QVector< QPair<int, int> > getOutputPin();
protected:
    QVector< QPair<int, int> > inputPinPosition, outputPinPosition;
    int value;
    void fillPosition();
};

#endif // BASEELEMENT_H
