#include "widget.h"
#include "ui_widget.h"
#include<QPoint>
#include"andlogicgate.h"
#include<QGraphicsItem>
#include<baselogicgate.h>
#include<QGraphicsScene>
#include"orlogicgate.h"
#include"nonlogicgate.h"
#include "nandlogicgate.h"
#include "norlogicgate.h"
#include "xorlogicgate.h"
#include "xnorlogicgate.h"
#include"andornotlogicgate.h"
#include"highlevel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    highLevel *item=new highLevel;
    //orLogicGate * item2 = new orLogicGate;
    // xorLogicGate * item3 = new xorLogicGate;
    scene->addItem(item);
    //scene->addItem(item2);
    // scene->addItem(item3);

}

Widget::~Widget()
{
    delete ui;
}

