#ifndef BASELOGICGATE_H
#define BASELOGICGATE_H
#include <QPainter>
#include<QGraphicsItem>

class baselogicgate:public QGraphicsItem,public QPainter
{
public:
    baselogicgate();
    //输入函数
    int input();
    //输出函数
    int output();
protected:
    const int lineWidth = 15;
    const int width = 70;
    const int height = 100;
};

#endif // BASELOGICGATE_H
