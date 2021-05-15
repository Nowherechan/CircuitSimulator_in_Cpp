/**
  * main.cpp
  * author@刘睿尧
  * tester@刘睿尧
  * function:
  *     the main program of the project
  * bug:
  *     null
  * TODO:
  *     null
  */
#include "startwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    return a.exec();
}
