/********************************************************************************
** Form generated from reading UI file 'circuitwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCUITWINDOW_H
#define UI_CIRCUITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "circuitmap.h"

QT_BEGIN_NAMESPACE

class Ui_CircuitWindow
{
public:
    QAction *actionReturn;
    QAction *actionExit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    CircuitMap *widget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CircuitWindow)
    {
        if (CircuitWindow->objectName().isEmpty())
            CircuitWindow->setObjectName(QString::fromUtf8("CircuitWindow"));
        CircuitWindow->resize(1000, 600);
        actionReturn = new QAction(CircuitWindow);
        actionReturn->setObjectName(QString::fromUtf8("actionReturn"));
        actionExit = new QAction(CircuitWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(CircuitWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new CircuitMap(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        CircuitWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CircuitWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CircuitWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CircuitWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CircuitWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(CircuitWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        CircuitWindow->addToolBar(Qt::RightToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionReturn);
        menu->addAction(actionExit);

        retranslateUi(CircuitWindow);

        QMetaObject::connectSlotsByName(CircuitWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CircuitWindow)
    {
        CircuitWindow->setWindowTitle(QCoreApplication::translate("CircuitWindow", "MainWindow", nullptr));
        actionReturn->setText(QCoreApplication::translate("CircuitWindow", "\350\277\224\345\233\236", nullptr));
        actionExit->setText(QCoreApplication::translate("CircuitWindow", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QCoreApplication::translate("CircuitWindow", "\345\274\200\345\247\213", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("CircuitWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircuitWindow: public Ui_CircuitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITWINDOW_H
