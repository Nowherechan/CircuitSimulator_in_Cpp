/**
  * startwindows.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     the start widget of the program
  * bug:(when one bug was fixed, marked it with '~')
  * ~   1.text can't move when only change y of the window.
  *         one solution: put the label into button.
  *         final solution: setParent() change to btn.
  * ~   2.segmentation-faults happen when use this->show() after delete the subscene.
  *         final solution: close() instead of delete.
  * TODO:(when one was completed, marked it with '~')
  * ~   1.Complete four pictures(200x200) and fill them into paths.
  * ~   2.Complete the show and hide function.
  */
#include "startwindow.h"
#include "ui_startwindow.h"
#include "circuitwindow.h"
#include <QDebug>
#include <QString>
#include <QSound>
#include <QPainter>
#include <QTimer>

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    //图片路径
    QString pix_Digital, /*pix_Analog,*/ pix_Title;
    pix_Digital = ":/src/btn_basic.png";      //数电模式图标路径
    /*
    pix_Analog = ":/src/btn_basic.png";       //模电模式图片路径
    */
    pix_Title = ":/src/title.png";        //开始界面标题图片路径

    //加载标题图片
    QPixmap pixmap_Title;
    bool ret = pixmap_Title.load(pix_Title);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }
    ui->title_Pic->setPixmap(pixmap_Title);

    //音效与字体设置
    QSound * clickSound = new QSound(":/src/click.wav");
    QFont font;
    font.setPointSize(28);
    font.setBold(true);
    font.setFamily("黑体");

    //退出按钮
    connect(ui->actionExit, &QAction::triggered, [=](){
        this->close();
    });

    //数电按钮设置
    ui->btn_Digital->changeNormalImg(pix_Digital);
    ui->label_Digital->setParent(ui->btn_Digital);
    ui->label_Digital->setFixedSize(ui->btn_Digital->size());
    ui->label_Digital->setText("<font color=#2265A9>数字<br>电路</font>");
    ui->label_Digital->setFont(font);
    ui->label_Digital->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);   //水平以及垂直居中
    ui->label_Digital->setAttribute(Qt::WA_TransparentForMouseEvents);      //鼠标穿透
//    connect(ui->btn_Digital, &Animation_Btn::moved, ui->label_Digital, [=](){
//        QPoint * p = new QPoint(ui->btn_Digital->x()
//                                + ui->widget_Down->x(),
//                                ui->btn_Digital->y()
//                                + ui->widget_Down->y()
//                                + ui->menubar->geometry().height());
//        ui->label_Digital->move(*p);
//    });
    connect(ui->btn_Digital, &Animation_Btn::clicked, [=](){
        ui->btn_Digital->zoom1();
        ui->btn_Digital->zoom2();
        clickSound->play();
        ui->btn_Digital->setDisabled(true);
        //ui->btn_Analog->setDisabled(true);
        //界面切换
        QTimer::singleShot(200, this, [=](){
            this->hide();
            ui->btn_Digital->setDisabled(false);
            //ui->btn_Analog->setDisabled(false);
            circuit_Window = new CircuitWindow(nullptr, CircuitWindow::Digital);
            circuit_Window->show();
            connect(circuit_Window, &CircuitWindow::turn_Back, [=](){
                circuit_Window->close();
//                delete circuit_Window;
                circuit_Window = NULL;
                this->show();
            });
        });
    });

    /*
    //模电按钮设置
    ui->btn_Analog->changeNormalImg(pix_Analog);
    ui->label_Analog->setParent(ui->btn_Analog);
    ui->label_Analog->setFixedSize(ui->btn_Analog->size());
    ui->label_Analog->setText("<font color=#2265A9>模拟<br>电路</font>");
    ui->label_Analog->setFont(font);
    ui->label_Analog->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);   //水平以及垂直居中
    ui->label_Analog->setAttribute(Qt::WA_TransparentForMouseEvents);      //鼠标穿透
//    connect(ui->btn_Analog, &Animation_Btn::moved, ui->label_Analog, [=](){
//        QPoint * p = new QPoint(ui->btn_Analog->x()
//                                + ui->widget_Down->x(),
//                                ui->btn_Analog->y()
//                                + ui->widget_Down->y()
//                                + ui->menubar->geometry().height());
//        ui->label_Analog->move(*p);
//    });
    connect(ui->btn_Analog, &Animation_Btn::clicked, [=](){
        ui->btn_Analog->zoom1();
        ui->btn_Analog->zoom2();
        clickSound->play();
        ui->btn_Digital->setDisabled(true);
        ui->btn_Analog->setDisabled(true);
        //界面切换
        QTimer::singleShot(200, this, [=](){
            this->hide();
            ui->btn_Digital->setDisabled(false);
            ui->btn_Analog->setDisabled(false);
            circuit_Window = new CircuitWindow(nullptr, CircuitWindow::Analog);
            circuit_Window->show();
            connect(circuit_Window, &CircuitWindow::turn_Back, [&](){
                circuit_Window->close();
//                delete circuit_Window;
                circuit_Window = NULL;
                this->show();
            });
        });
    });
    */
}

//绘制背景图片
void StartWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QString pix_Background = ":/src/bg_basic.png";   //背景图片路径
    QPixmap pixmap_Background;
    bool ret = pixmap_Background.load(pix_Background);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }
    painter.drawPixmap(0, 0, this->width(), this->height(), pix_Background);
}

StartWindow::~StartWindow()
{
    delete ui;
    delete circuit_Window;
}
