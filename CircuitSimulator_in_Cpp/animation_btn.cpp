#include "animation_btn.h"
#include <QDebug>
#include <QPropertyAnimation>

Animation_Btn::Animation_Btn(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImgPath);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    //去除边框
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

Animation_Btn::Animation_Btn(QWidget* parent) : QPushButton(parent)
{
    this->normalImgPath = ":/src/default_png.png";
    this->pressImgPath = "";

    QPixmap pix;
    bool ret = pix.load(normalImgPath);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    //去除边框
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void Animation_Btn::changeNormalImg(QString newNormalImg)
{
    normalImgPath = newNormalImg;
}

void Animation_Btn::changePressImg(QString newPressImg)
{
    pressImgPath = newPressImg;
}

void Animation_Btn::zoom1()
{
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void Animation_Btn::zoom2()
{
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void Animation_Btn::mousePressEvent(QMouseEvent *e)
{
    if(pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(pressImgPath);
        if(!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }

        this->setFixedSize(pix.width(), pix.height());
        //去除边框
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    return QPushButton::mousePressEvent(e);
}

void Animation_Btn::mouseReleaseEvent(QMouseEvent *e)
{
    if(pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(normalImgPath);
        if(!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }

        this->setFixedSize(pix.width(), pix.height());
        //去除边框
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    return QPushButton::mouseReleaseEvent(e);
}
