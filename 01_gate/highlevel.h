#ifndef HIGHLEVEL_H
#define HIGHLEVEL_H
#include <QPainter>
#include<QGraphicsItem>

class highLevel:public QGraphicsItem,public QPainter
{
public:
    highLevel();
    //获得边缘点坐标
    QVector< QPair<int, int> > getInputPin();
    QVector< QPair<int, int> > getOutputPin();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

protected:
    QVector< QPair<int, int> > inputPinPosition, outputPinPosition;
    //填充边缘点坐标信息
    void fillPosition();
private:
    QPoint position;
};

#endif // HIGHLEVEL_H
