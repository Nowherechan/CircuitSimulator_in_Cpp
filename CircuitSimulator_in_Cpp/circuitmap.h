#ifndef CIRCUITMAP_H
#define CIRCUITMAP_H

#include "circuitwindow.h"
#include "wire.h"
#include "logical-gate/highlevel.h"
#include "logical-gate/andlogicgate.h"
#include "logical-gate/orlogicgate.h"
#include "logical-gate/nonlogicgate.h"
#include "logical-gate/nandlogicgate.h"
#include "logical-gate/norlogicgate.h"
#include "logical-gate/andornotlogicgate.h"
#include "logical-gate/xorlogicgate.h"
#include "logical-gate/xnorlogicgate.h"
#include <QWidget>
#include <QPixmap>
#include <QGraphicsScene>

namespace Ui {
class CircuitMap;
}

class CircuitMap : public QWidget
{
    Q_OBJECT

public:
    //电路背景图参数
    static const int MAP_WIDTH = 1600;
    static const int MAP_HEIGHT = 900;
    const QColor DOTS_COLOR = QColor("#B0B0B0");
    const QString BG_COLOR_STRING = "#A0A0A0";
    const QString BTN_COLOR_STRING = "#80C0E0";
    const QColor MAP_COLOR = QColor("#FFFFFF");
    const QColor LINE_COLOR = QColor("#101010");
    static const int INITIAL_ZOOM = 50;

    explicit CircuitMap(QWidget *parent = nullptr);
    void zoomCircuit(int value);
    void paintEvent(QPaintEvent *) override;
    void select(CircuitWindow::component_Selected c);
    ~CircuitMap();

protected:
    QPixmap draw_Dots_Map();
    Wire* addWire(QPointF A, QPointF B);
    highLevel* addHighLevel(QPointF p);
    andLogicGate* addGateAnd(QPointF p);
    orLogicGate* addGateOr(QPointF p);
    nonLogicGate* addGateNon(QPointF p);
    nandLogicGate* addGateNand(QPointF p);
    norLogicGate* addGateNor(QPointF p);
    andOrNotLogicGate* addGateAndOrNor(QPointF p);
    xorLogicGate* addGateXor(QPointF p);
    xnorLogicGate* addGateXnor(QPointF p);
    void dealPress(QPointF p);
    void dealMove(QPointF p);
    void dealRelease(QPointF p);
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    CircuitWindow::component_Selected mod;
    Ui::CircuitMap *ui;
    int zoom;
    QPixmap map;
    QGraphicsScene * scene;
    QGraphicsItem * w;
};

#endif // CIRCUITMAP_H
