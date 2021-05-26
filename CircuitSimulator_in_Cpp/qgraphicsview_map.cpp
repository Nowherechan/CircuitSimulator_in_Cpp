/**
  * qgraphicsview_map.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     a graphic's view with functions extended.
  * bug:(when one bug was fixed, marked it with '~')
  *     1. After zooming the dots become a mess.
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "qgraphicsview_map.h"
#include "ui_qgraphicsview_map.h"
#include "circuitmap.h"
#include <QDebug>
#include <QMouseEvent>

QGraphicsView_Map::QGraphicsView_Map(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::QGraphicsView_Map)
{
    ui->setupUi(this);

    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);   //解决拖影
}

void QGraphicsView_Map::setMap(QPixmap newMap)
{
    map = newMap;
}

void QGraphicsView_Map::drawBackground(QPainter *painter, const QRectF &)
{
    painter->drawPixmap(int(sceneRect().left() + sceneRect().width()/10),
                        int(sceneRect().top() + sceneRect().height()/10), map);
}

void QGraphicsView_Map::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);

    QPoint posChild(event->x(), event->y());
    emit mousePressed(posChild);
}

void QGraphicsView_Map::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

    QPoint posChild(event->x(), event->y());
    emit mouseMoved(posChild);
}

void QGraphicsView_Map::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);

    //mouseMoved(QPoint())->disconnect();
}

QGraphicsView_Map::~QGraphicsView_Map()
{
    delete ui;
}
