#ifndef CIRCUITWINDOW_H
#define CIRCUITWINDOW_H

#include <QMainWindow>

namespace Ui {
class CircuitWindow;
}

class CircuitWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum circuit_Mod{Digital, Analog};
    enum component_Selected{Select, Wire, HighLevel, And, Or, Non, Nand, Nor, AndOrNot, Xor, Xnor};  //Add more when add components.
    explicit CircuitWindow(QWidget *parent = nullptr, circuit_Mod mod = Digital);
    void paintEvent(QPaintEvent *);
    ~CircuitWindow();

private:
    Ui::CircuitWindow *ui;
    circuit_Mod current_Mod;

signals:
    void turn_Back();
    void select(component_Selected c);
};

#endif // CIRCUITWINDOW_H
