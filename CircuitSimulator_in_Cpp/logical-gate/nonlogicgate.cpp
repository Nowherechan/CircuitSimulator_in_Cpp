/**
  * nonlogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     a not logic gate
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "nonlogicgate.h"

//填充引脚坐标信息
void nonLogicGate::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    //输入引脚
    temp = {baseX,baseY+height/2};
    inputPinPosition.push_back(temp);
    //输出引脚
    temp = {baseX + lineWidth*2 + width, baseY + height/2};
    outputPinPosition.push_back(temp);
}

nonLogicGate::nonLogicGate()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
    nowInput.clear();
    nowOutput.clear();
    nowInput.push_back(false);
    nowOutput.push_back(true);
    setN(1);

    kind = 0x030;
}

QRectF nonLogicGate::boundingRect() const
{
    return QRectF(0,0,100,100);
}

QVector<bool> nonLogicGate::flash(QVector<bool> input)
{
    //维护旧输入输出
    lastInput = nowInput;
    lastOutput = nowOutput;
    //处理新输入输出
    nowInput = input;
    bool temp = nowInput[0];
    temp = !nowInput[0];
    nowOutput.clear();
    nowOutput.push_back(temp);
    return nowOutput;
}

void nonLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
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
                      "1");
    painter->drawEllipse(baseX+lineWidth+width,
                         baseY+height/2-2.5,
                         5,
                         5);

    //引脚绘制设置
    QPen penGrayPin = QPen(baselogicgate::GRAY);
    penGrayPin.setWidth(2);
    QPen penGreenPin = QPen(baselogicgate::GREEN);
    penGreenPin.setWidth(2);
    painter->setPen(penGrayPin);

    //画输入引脚
    nowInput[0] ? painter->setPen(penGreenPin) : painter->setPen(penGrayPin);
    painter->drawLine(inputPinPosition[0].first,
            inputPinPosition[0].second,
            inputPinPosition[0].first + lineWidth,
            inputPinPosition[0].second);

    //画输出引脚
    nowOutput[0] ? painter->setPen(penGreenPin) : painter->setPen(penGrayPin);
    painter->drawLine(outputPinPosition[0].first,
            outputPinPosition[0].second,
            outputPinPosition[0].first - lineWidth + 5,
            outputPinPosition[0].second);

}

