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

QGraphicsView_Map::QGraphicsView_Map(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::QGraphicsView_Map)
{
    ui->setupUi(this);
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

QGraphicsView_Map::~QGraphicsView_Map()
{
    delete ui;
}
