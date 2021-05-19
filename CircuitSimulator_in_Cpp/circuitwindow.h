#ifndef CIRCUITWINDOW_H
#define CIRCUITWINDOW_H

#include <QMainWindow>

enum circuit_Mod{Digital, Analog};

namespace Ui {
class CircuitWindow;
}

class CircuitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CircuitWindow(QWidget *parent = nullptr, circuit_Mod mod = Digital);
    void paintEvent(QPaintEvent *);
    ~CircuitWindow();

private:
    Ui::CircuitWindow *ui;
    circuit_Mod current_Mod;

signals:
    void turn_Back();
};

#endif // CIRCUITWINDOW_H
