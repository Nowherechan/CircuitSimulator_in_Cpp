#ifndef HIGHLEVEL_H
#define HIGHLEVEL_H
#include "baselogicgate.h"
#include <QGraphicsItem>

class highLevel:public baselogicgate
{
public:
    highLevel();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QVector<bool> flash(QVector<bool> input);

protected:
    void fillPosition();

private:
    QPoint position;
};

#endif // HIGHLEVEL_H
