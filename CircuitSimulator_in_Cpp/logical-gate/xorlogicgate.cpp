/**
  * xorlogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an and-or-not logic gate
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "xorlogicgate.h"

//填充引脚坐标信息
void xorLogicGate::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    //输入引脚
    temp = {baseX, baseY + 20};
    inputPinPosition.push_back(temp);
    temp = {baseX, baseY + 70};
    inputPinPosition.push_back(temp);
    //输出引脚
    temp = {baseX + lineWidth*2 + width, baseY + height/2};
    outputPinPosition.push_back(temp);
}

xorLogicGate::xorLogicGate()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
    nowInput.clear();
    nowOutput.clear();
    for(int i = 0; i < 2; i++)
    {
        nowInput.push_back(false);
    }
    nowOutput.push_back(false);

    kind = 0x060;
}

QRectF xorLogicGate::boundingRect() const
{
    return QRectF(0,0,100,100);
}

QVector<bool> xorLogicGate::flash(QVector<bool> input)
{
    //维护旧输入输出
    lastInput = nowInput;
    lastOutput = nowOutput;
    //处理新输入输出
    nowInput = input;
    bool temp1 = nowInput[0];
    bool temp2 = nowInput[1];
    bool temp;
    temp = (temp1&&(!temp2))||((!temp1)&&temp2);
    nowOutput.clear();
    nowOutput.push_back(temp);
    return nowOutput;
}

void xorLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    int baseX = position.x();
    int baseY = position.y();

    //主体绘制设置
    QPen penEdge = QPen(baselogicgate::BLACK);
    penEdge.setWidth(2);
    painter->setPen(penEdge);

    //画主体
    painter->drawRect(QRect(baseX + lineWidth,
                            baseY,
                            width,
                            height));
    painter->drawText(baseX + 40,
                      baseY + 40,
                      "=1");

    //引脚绘制设置
    QPen penGrayPin = QPen(baselogicgate::GRAY);
    penGrayPin.setWidth(2);
    QPen penGreenPin = QPen(baselogicgate::GREEN);
    penGreenPin.setWidth(2);
    painter->setPen(penGrayPin);

    //画输入引脚
    for(int i = 0; i < inputPinPosition.size(); i++)
    {
        nowInput[i] ? painter->setPen(penGreenPin) : painter->setPen(penGrayPin);
        painter->drawLine(inputPinPosition[i].first,
                          inputPinPosition[i].second,
                          inputPinPosition[i].first + lineWidth,
                          inputPinPosition[i].second);
    }
    //画输出引脚
    for(int i = 0; i < outputPinPosition.size(); i++)
    {
        nowOutput[i] ? painter->setPen(penGreenPin) : painter->setPen(penGrayPin);
        painter->drawLine(outputPinPosition[i].first,
                          outputPinPosition[i].second,
                          outputPinPosition[i].first - lineWidth,
                          outputPinPosition[i].second);
    }
}
