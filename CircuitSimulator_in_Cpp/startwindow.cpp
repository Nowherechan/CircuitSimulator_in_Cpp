#include "startwindow.h"
#include "ui_startwindow.h"
#include <QDebug>
#include <QString>

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    QString pix_Digital, pix_Analog, pix_Title;
    pix_Digital = ":/src/default_png.png";
    pix_Analog = ":/src/default_png.png";
    pix_Title = ":/src/default_png.png";

    QPixmap pixmap_Title;
    bool ret = pixmap_Title.load(pix_Title);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }

    ui->btn_Digital->changeNormalImg(pix_Digital);
    ui->btn_Analog->changePressImg(pix_Analog);
    ui->title_Pic->setPixmap(pixmap_Title);
}

StartWindow::~StartWindow()
{
    delete ui;
}
