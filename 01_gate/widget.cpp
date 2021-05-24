#include "widget.h"
#include "ui_widget.h"
#include<QPoint>
#include"andlogicgate.h"
#include<QGraphicsItem>
#include<baselogicgate.h>
#include<QGraphicsScene>
#include"orlogicgate.h"
#include"nonlogicgate.h"
#include"nandlogicgate.h"
#include "norlogicgate.h"
#include "xorlogicgate.h"
#include "xnorlogicgate.h"
#include"andornotlogicgate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);

   andOrNotLogicGate *item=new andOrNotLogicGate;
    scene->addItem(item);
}

Widget::~Widget()
{
    delete ui;
}

