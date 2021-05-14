#ifndef ANIMATION_BTN_H
#define ANIMATION_BTN_H

#include <QPushButton>

class Animation_Btn : public QPushButton
{
    Q_OBJECT
public:
    Animation_Btn(QWidget* parent);
    Animation_Btn(QString normalImg = ":/src/default_png.png", QString pressImg = "");

    void changeNormalImg(QString newNormalImg);
    void changePressImg(QString newPressImg);

    void zoom1();
    void zoom2();

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QString normalImgPath;
    QString pressImgPath;

signals:

};

#endif // MYPUSHBUTTON_H
