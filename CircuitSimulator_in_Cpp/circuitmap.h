#ifndef CIRCUITMAP_H
#define CIRCUITMAP_H

#include <QWidget>
#include <QPixmap>

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
    ~CircuitMap();

protected:
    QPixmap draw_Dots_Map();

private:
    Ui::CircuitMap *ui;
    int zoom;
    QPixmap map;
};

#endif // CIRCUITMAP_H
