#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "circuitwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~StartWindow();

private:
    Ui::StartWindow *ui;
    CircuitWindow * circuit_Window = NULL;
};
#endif // STARTWINDOW_H
