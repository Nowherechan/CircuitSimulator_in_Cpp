#ifndef BASELOGICGATE_H
#define BASELOGICGATE_H
#include <QPainter>
#include <QGraphicsItem>

class baselogicgate:public QGraphicsItem,public QPainter
{
public:
    baselogicgate(int iniN = 2);

    //获得引脚数
    int getN();
    //设置引脚数 —— 由子类重载
    void setN(int newN);
    //获得引脚坐标
    QVector< QPair<int, int> > getInputPin();
    QVector< QPair<int, int> > getOutputPin();
    //进行运算，更新状态并返回输出 —— 由子类重载
    volatile QVector<bool> flash(QVector<bool> input);
    void setIntPos(QPointF p);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    int type() const override;
    int getKind();

protected:
    const int lineWidth = 15;
    const int width = 70;
    const int height = 100;
    int n;                                                          //引脚数
    int kind;
    QVector< QPair<int, int> > inputPinPosition, outputPinPosition; //引脚坐标数组
    QVector<bool> nowInput, lastInput, nowOutput, lastOutput;       //输入输出状态
    const QColor BLACK = QColor(0, 0, 0);
    const QColor GRAY = QColor(100, 100, 100);
    const QColor GREEN = QColor(0, 200, 0);
    void fillPosition();                                            //填充引脚坐标信息

};

/**
  * kind分配
  * base        0x000
  * highlevel   0x001
  * and         0x010
  * or          0x020
  * non         0x030
  * nand        0x040
  * nor         0x050
  * xor         0x060
  * xnor        0x070
  * andornot    0x080
  */

#endif // BASELOGICGATE_H
