/**
  * norlogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an and-or-not logic gate
  * bug:(when one bug was fixed, marked it with '~')
  * ~   1.flash push wrong bool.
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "norlogicgate.h"

//设置引脚数 —— 注意安全性
void norLogicGate::setN(int newN)
{
    if(newN < 2)
        n = 2;
    else if(newN > 5)
        n = 5;
    else
        n = newN;
    fillPosition();
}

//填充引脚坐标信息
void norLogicGate::fillPosition()
{
    int baseX = position.x();
    int baseY = position.y();
    inputPinPosition.clear();
    outputPinPosition.clear();
    QPair<int, int> temp;
    //输入引脚
    switch(n)
    {
    case 2:
        temp = {baseX, baseY + 30};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 70};
        inputPinPosition.push_back(temp);
        break;
    case 3:
        temp = {baseX, baseY + 20};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 50};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 80};
        inputPinPosition.push_back(temp);
        break;
    case 4:
        temp = {baseX, baseY + 20};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 40};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 60};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 80};
        inputPinPosition.push_back(temp);
        break;
    case 5:
        temp = {baseX, baseY + 10};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 30};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 50};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 70};
        inputPinPosition.push_back(temp);
        temp = {baseX, baseY + 90};
        inputPinPosition.push_back(temp);
        break;
    default:
        break;
    }
    //输出引脚
    temp = {baseX + lineWidth*2 + width, baseY + height/2};
    outputPinPosition.push_back(temp);
}

norLogicGate::norLogicGate(int iniN)
{
    position.setX(0);
    position.setY(0);
    setFocus();
    setFlags(QGraphicsItem::ItemIsFocusable|QGraphicsItem::ItemIsMovable);
    setN(iniN);
    nowInput.clear();
    nowOutput.clear();
    for(int i = 0; i < n; i++)
    {
        nowInput.push_back(false);
    }
    nowOutput.push_back(true);

    kind = 0x050;
}

QRectF norLogicGate::boundingRect() const
{
    return QRectF(0,0,100,100);
}

QVector<bool> norLogicGate::flash(QVector<bool> input)
{
    //维护旧输入输出
    lastInput = nowInput;
    lastOutput = nowOutput;
    //处理新输入输出
    nowInput = input;
    bool temp = nowInput[0];
    bool temp1;
    for(int i = 1; i < nowInput.size(); i++)
    {
        temp =temp || nowInput[i];
    }
    temp1 = !temp;
    nowOutput.clear();
    nowOutput.push_back(temp1);
    return nowOutput;
}

void norLogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
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
                      "≥1");
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
