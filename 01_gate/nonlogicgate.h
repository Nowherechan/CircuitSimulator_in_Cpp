#ifndef NONLOGICGATE_H
#define NONLOGICGATE_H
#include"baselogicgate.h"
#include <QGraphicsItem>

class nonLogicGate:public baselogicgate
{
public:
    nonLogicGate();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    //进行运算，更新状态并返回输出
    QVector<bool> flash(QVector<bool> input);

protected:
    //填充引脚坐标信息
    void fillPosition();

private:
    QPoint position;

};
#endif // NONLOGICGATE_H
