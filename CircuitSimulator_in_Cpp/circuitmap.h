#ifndef CIRCUITMAP_H
#define CIRCUITMAP_H

#include "circuitwindow.h"
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
    explicit CircuitMap(QWidget *parent = nullptr);
    void zoomCircuit(int value);
    void paintEvent(QPaintEvent *);
    void select(CircuitWindow::component_Selected c);
    ~CircuitMap();

protected:
    QPixmap draw_Dots_Map();
    andLogicGate* addGateAnd();
    orLogicGate* addGateOr();
    nonLogicGate* addGateNon();
    nandLogicGate* addGateNand();
    norLogicGate* addGateNor();
    andOrNotLogicGate* addGateAndOrNor();
    xorLogicGate* addGateXor();
    xnorLogicGate* addGateXnor();

private:
    Ui::CircuitMap *ui;
    int zoom;
    QPixmap map;
    QGraphicsScene * scene;
};

#endif // CIRCUITMAP_H
