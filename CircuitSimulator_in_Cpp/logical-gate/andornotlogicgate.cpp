/**
  * andornotlogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an and-or-not logic gate
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "andornotlogicgate.h"

//填充引脚坐标信息
void andOrNotLogicGate::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    //输入引脚
    temp = {baseX, baseY + 20};
    inputPinPosition.push_back(temp);
    temp = {baseX, baseY + 40};
    inputPinPosition.push_back(temp);
    temp = {baseX, baseY + 60};
    inputPinPosition.push_back(temp);
    temp = {baseX, baseY + 80};
    inputPinPosition.push_back(temp);

    //输出引脚
    temp = {baseX + lineWidth*2 + width, baseY + height/2};
    outputPinPosition.push_back(temp);
}

andOrNotLogicGate::andOrNotLogicGate()
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    fillPosition();
    nowInput.clear();
    nowOutput.clear();
    for(int i = 0; i < 4; i++)
    {
        nowInput.push_back(false);
    }
    nowOutput.push_back(true);
    setN(4);

    kind = 0x080;
}

QRectF andOrNotLogicGate::boundingRect() const
{
    return QRectF(0,0,100,100);
}

QVector<bool> andOrNotLogicGate::flash(QVector<bool> input)
{
    //维护旧输入输出
    lastInput = nowInput;
    lastOutput = nowOutput;
    //处理新输入输出
    nowInput = input;
    bool temp1 = nowInput[0];
    bool temp2 = nowInput[1];
    bool temp3 = nowInput[2];
    bool temp4 = nowInput[3];
    bool temp;
    temp=!((temp1&&temp2)||(temp3&&temp4));
    nowOutput.clear();
    nowOutput.push_back(temp);
    return nowOutput;
}

void andOrNotLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
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
    painter->drawLine(baseX+lineWidth,
                      baseY + height/2,
                      baseX + lineWidth+width/2,
                      baseY + height/2);
    painter->drawLine(baseX+lineWidth+width/2,
                      baseY ,
                      baseX + lineWidth+width/2,
                      baseY + height);
    painter->drawEllipse(baseX+lineWidth+width,
                         baseY+height/2-2.5,
                         5,
                         5);
    painter->drawText(baseX + 20,
                      baseY + 20,
                      "&");
    painter->drawText(baseX + 50,
                      baseY + 20,
                      "≥1");

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
                          outputPinPosition[i].first - lineWidth + 5,
                          outputPinPosition[i].second);
    }
}
