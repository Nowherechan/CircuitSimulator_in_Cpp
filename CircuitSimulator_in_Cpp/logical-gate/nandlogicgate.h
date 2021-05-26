#ifndef NANDLOGICGATE_H
#define NANDLOGICGATE_H
#include"baselogicgate.h"

#include <QGraphicsItem>

class nandLogicGate:public baselogicgate
{
public:
    nandLogicGate(int iniN = 2);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void setN(int newN);
    //进行运算，更新状态并返回输出
    QVector<bool> flash(QVector<bool> input);

protected:
    //填充引脚坐标信息
    void fillPosition();

private:
    QPoint position;

};

#endif // ANDLOGICGATE_H
