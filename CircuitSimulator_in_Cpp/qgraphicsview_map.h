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
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::QGraphicsView_Map *ui;
    QPixmap map;

signals:
    void mousePressed(QPoint p);
    void mouseMoved(QPoint p);
};

#endif // QGRAPHICSVIEW_MAP_H
