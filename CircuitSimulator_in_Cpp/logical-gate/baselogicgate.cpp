/**
  * baselogicgate.cpp
  * author@王梦泽&尤曼绮
  * tester@刘睿尧
  * function:
  *     an abstract logic gate
  * bug:(when one bug was fixed, marked it with '~')
  *     null
  * TODO:(when one was completed, marked it with '~')
  *     null
  */
#include "baselogicgate.h"
#include "andlogicgate.h"
#include "orlogicgate.h"
#include "nonlogicgate.h"
#include <QPainter>

baselogicgate::baselogicgate(int iniN)
{
    n = iniN;
}

int baselogicgate::getN()
{
    return n;
}

void baselogicgate::setN(int newN)
{
    this->n = newN;
}

QVector< QPair<int, int> > baselogicgate::getInputPin()
{
    return inputPinPosition;
}

QVector< QPair<int, int> > baselogicgate::getOutputPin()
{
    return outputPinPosition;
}
