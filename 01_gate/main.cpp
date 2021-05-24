#include "widget.h"
#include"baselogicgate.h"
#include"andlogicgate.h"
#include"orlogicgate.h"
#include"nonlogicgate.h"

#include <QApplication>

/////////////////////////////
//baselogicgate *andlog = new andLogicGate;
//baselogicgate *orlog = new orLogicGate;
//baselogicgate *nonlog = new nonLogicGate;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
