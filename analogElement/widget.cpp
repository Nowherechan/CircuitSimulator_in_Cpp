#include "widget.h"
#include "ui_widget.h"
#include"resistance.h"
#include"currentsource.h"
#include"voltagesource.h"
#include"switchopen.h"
#include"switchclose.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    resistance *item = new resistance;
    scene->addItem(item);


    voltageSource*item1 = new  voltageSource;
    scene->addItem(item1);

    switchClose*item2 = new  switchClose;
    scene->addItem(item2);

    switchOpen*item3 = new  switchOpen;
    scene->addItem(item3);

    currentSource*item4 = new  currentSource;
    scene->addItem(item4);

}

Widget::~Widget()
{
    delete ui;

}

