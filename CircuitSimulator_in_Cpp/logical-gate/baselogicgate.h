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
////////////////////////////////得到图像
   // void getPaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ////////得到用户选择的元件的编号
    //int getPaintNum(int paintNum){return paintNum;}
protected:
    const int lineWidth = 15;
    const int width = 70;
    const int height = 100;
    ////////用户点击工具栏中的门元件，返回一个数值，再通过getPaint函数中的switch来决定打印哪一个图像
    //int paintNum;
};

#endif // BASELOGICGATE_H
