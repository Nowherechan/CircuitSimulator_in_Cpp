#ifndef CIRCUITMAP_H
#define CIRCUITMAP_H

#include <QWidget>

namespace Ui {
class CircuitMap;
}

class CircuitMap : public QWidget
{
    Q_OBJECT

public:
    explicit CircuitMap(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~CircuitMap();

private:
    Ui::CircuitMap *ui;
};

#endif // CIRCUITMAP_H
