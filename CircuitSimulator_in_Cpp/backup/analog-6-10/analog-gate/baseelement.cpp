#include "baseelement.h"

baseElement::baseElement(int inv)
{
    value = inv;
}

int baseElement::getValue()
{
    return value;
}

void baseElement::setValue(int newValue)
{
    this->value = newValue;
}

QVector< QPair<int, int> > baseElement::getInputPin()
{
    return inputPinPosition;
}

QVector< QPair<int, int> > baseElement::getOutputPin()
{
    return outputPinPosition;
}
