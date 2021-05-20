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
    void paintEvent(QPaintEvent *);
    ~CircuitMap();

protected:
    void drawDots_Map();

private:
    Ui::CircuitMap *ui;
    int zoom;
    QPixmap map;
};

#endif // CIRCUITMAP_H
