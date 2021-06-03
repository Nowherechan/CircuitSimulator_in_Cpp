/**
  * qgraphicsview_map.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     a graphic's view with functions extended.
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "qgraphicsview_map.h"
#include "ui_qgraphicsview_map.h"
#include "circuitmap.h"
#include "logical-gate/andlogicgate.h"
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
//    qDebug() << event->x() << " " << event->y();
//    QPoint p = event->pos();
//    qDebug() << p;
//    QPointF p2 = this->mapToScene(p);
//    qDebug() << p2;
    QGraphicsView::mousePressEvent(event);
    emit mousePressed(*event);
}

void QGraphicsView_Map::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    emit mouseMoved(*event);
}

void QGraphicsView_Map::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    emit mouseReleased(*event);
}

QGraphicsView_Map::~QGraphicsView_Map()
{
    delete ui;
}
