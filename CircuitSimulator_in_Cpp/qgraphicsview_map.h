#ifndef QGRAPHICSVIEW_MAP_H
#define QGRAPHICSVIEW_MAP_H

#include <QGraphicsView>

namespace Ui {
class QGraphicsView_Map;
}

class QGraphicsView_Map : public QGraphicsView
{
    Q_OBJECT

public:
    explicit QGraphicsView_Map(QWidget *parent = nullptr);
    void setMap(QPixmap newMap);
    ~QGraphicsView_Map();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    Ui::QGraphicsView_Map *ui;
    QPixmap map;
};

#endif // QGRAPHICSVIEW_MAP_H
