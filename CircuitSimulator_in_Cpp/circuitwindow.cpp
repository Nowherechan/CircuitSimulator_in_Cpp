/**
  * circuitwindow.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     a window contains map of circuit.
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "circuitwindow.h"
#include "ui_circuitwindow.h"

CircuitWindow::CircuitWindow(QWidget *parent, circuit_Mod mod) :
    QMainWindow(parent),
    ui(new Ui::CircuitWindow)
{
    ui->setupUi(this);
    current_Mod = mod;

    //退出按钮
    connect(ui->actionExit, &QAction::triggered, [=](){
        this->close();
    });

    //返回按钮
    connect(ui->actionReturn, &QAction::triggered, [=](){
        emit turn_Back();
    });
}

CircuitWindow::~CircuitWindow()
{
    delete ui;
}
