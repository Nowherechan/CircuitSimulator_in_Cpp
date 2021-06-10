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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "circuitmap.h"

QT_BEGIN_NAMESPACE

class Ui_CircuitWindow
{
public:
    QAction *actionReturn;
    QAction *actionExit;
    QAction *actionAnd;
    QAction *actionOr;
    QAction *actionNon;
    QAction *actionSelect;
    QAction *actionNand;
    QAction *actionNor;
    QAction *actionAndOrNot;
    QAction *actionXor;
    QAction *actionXnor;
    QAction *actionWire;
    QAction *actionHighLevel;
    QAction *actionRun;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    CircuitMap *Map;
    QMenuBar *menubar;
    QMenu *menu;
    QToolBar *toolBarComponent;

    void setupUi(QMainWindow *CircuitWindow)
    {
        if (CircuitWindow->objectName().isEmpty())
            CircuitWindow->setObjectName(QString::fromUtf8("CircuitWindow"));
        CircuitWindow->resize(1000, 600);
        actionReturn = new QAction(CircuitWindow);
        actionReturn->setObjectName(QString::fromUtf8("actionReturn"));
        actionExit = new QAction(CircuitWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAnd = new QAction(CircuitWindow);
        actionAnd->setObjectName(QString::fromUtf8("actionAnd"));
        actionAnd->setCheckable(true);
        actionAnd->setChecked(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/src/logical-gate/component_and.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnd->setIcon(icon);
        actionOr = new QAction(CircuitWindow);
        actionOr->setObjectName(QString::fromUtf8("actionOr"));
        actionOr->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/src/logical-gate/component_or.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOr->setIcon(icon1);
        actionNon = new QAction(CircuitWindow);
        actionNon->setObjectName(QString::fromUtf8("actionNon"));
        actionNon->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/src/logical-gate/component_non.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNon->setIcon(icon2);
        actionSelect = new QAction(CircuitWindow);
        actionSelect->setObjectName(QString::fromUtf8("actionSelect"));
        actionSelect->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/src/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect->setIcon(icon3);
        actionNand = new QAction(CircuitWindow);
        actionNand->setObjectName(QString::fromUtf8("actionNand"));
        actionNand->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/src/logical-gate/component_nand.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNand->setIcon(icon4);
        actionNor = new QAction(CircuitWindow);
        actionNor->setObjectName(QString::fromUtf8("actionNor"));
        actionNor->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/src/logical-gate/component_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNor->setIcon(icon5);
        actionAndOrNot = new QAction(CircuitWindow);
        actionAndOrNot->setObjectName(QString::fromUtf8("actionAndOrNot"));
        actionAndOrNot->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/src/logical-gate/component_andornot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAndOrNot->setIcon(icon6);
        actionXor = new QAction(CircuitWindow);
        actionXor->setObjectName(QString::fromUtf8("actionXor"));
        actionXor->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/src/logical-gate/component_xor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionXor->setIcon(icon7);
        actionXnor = new QAction(CircuitWindow);
        actionXnor->setObjectName(QString::fromUtf8("actionXnor"));
        actionXnor->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/src/logical-gate/component_xnor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionXnor->setIcon(icon8);
        actionWire = new QAction(CircuitWindow);
        actionWire->setObjectName(QString::fromUtf8("actionWire"));
        actionWire->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/src/wire.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWire->setIcon(icon9);
        actionHighLevel = new QAction(CircuitWindow);
        actionHighLevel->setObjectName(QString::fromUtf8("actionHighLevel"));
        actionHighLevel->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/src/logical-gate/component_hightlevel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHighLevel->setIcon(icon10);
        actionRun = new QAction(CircuitWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionRun->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/src/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon11);
        centralwidget = new QWidget(CircuitWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Map = new CircuitMap(centralwidget);
        Map->setObjectName(QString::fromUtf8("Map"));

        horizontalLayout->addWidget(Map);

        CircuitWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CircuitWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CircuitWindow->setMenuBar(menubar);
        toolBarComponent = new QToolBar(CircuitWindow);
        toolBarComponent->setObjectName(QString::fromUtf8("toolBarComponent"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBarComponent->sizePolicy().hasHeightForWidth());
        toolBarComponent->setSizePolicy(sizePolicy);
        toolBarComponent->setMovable(false);
        toolBarComponent->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea|Qt::TopToolBarArea);
        toolBarComponent->setFloatable(false);
        CircuitWindow->addToolBar(Qt::RightToolBarArea, toolBarComponent);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionReturn);
        menu->addAction(actionExit);
        toolBarComponent->addAction(actionSelect);
        toolBarComponent->addAction(actionRun);
        toolBarComponent->addAction(actionWire);
        toolBarComponent->addSeparator();

        retranslateUi(CircuitWindow);

        QMetaObject::connectSlotsByName(CircuitWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CircuitWindow)
    {
        CircuitWindow->setWindowTitle(QCoreApplication::translate("CircuitWindow", "MainWindow", nullptr));
        actionReturn->setText(QCoreApplication::translate("CircuitWindow", "\350\277\224\345\233\236", nullptr));
        actionExit->setText(QCoreApplication::translate("CircuitWindow", "\351\200\200\345\207\272", nullptr));
        actionAnd->setText(QCoreApplication::translate("CircuitWindow", "\344\270\216\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionAnd->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\344\270\216\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAnd->setShortcut(QCoreApplication::translate("CircuitWindow", "A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOr->setText(QCoreApplication::translate("CircuitWindow", "\346\210\226\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionOr->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\346\210\226\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOr->setShortcut(QCoreApplication::translate("CircuitWindow", "O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNon->setText(QCoreApplication::translate("CircuitWindow", "\351\235\236\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionNon->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\351\235\236\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNon->setShortcut(QCoreApplication::translate("CircuitWindow", "N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect->setText(QCoreApplication::translate("CircuitWindow", "\351\200\211\346\213\251", nullptr));
#if QT_CONFIG(tooltip)
        actionSelect->setToolTip(QCoreApplication::translate("CircuitWindow", "\351\200\211\346\213\251\345\205\203\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSelect->setShortcut(QCoreApplication::translate("CircuitWindow", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNand->setText(QCoreApplication::translate("CircuitWindow", "\344\270\216\351\235\236\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionNand->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\344\270\216\351\235\236\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNand->setShortcut(QCoreApplication::translate("CircuitWindow", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNor->setText(QCoreApplication::translate("CircuitWindow", "\346\210\226\351\235\236\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionNor->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\346\210\226\351\235\236\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNor->setShortcut(QCoreApplication::translate("CircuitWindow", "Alt+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAndOrNot->setText(QCoreApplication::translate("CircuitWindow", "\344\270\216\346\210\226\351\235\236\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionAndOrNot->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\344\270\216\346\210\226\351\235\236\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAndOrNot->setShortcut(QCoreApplication::translate("CircuitWindow", "Alt+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionXor->setText(QCoreApplication::translate("CircuitWindow", "\345\274\202\346\210\226\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionXor->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\345\274\202\346\210\226\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionXor->setShortcut(QCoreApplication::translate("CircuitWindow", "Shift+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionXnor->setText(QCoreApplication::translate("CircuitWindow", "\345\220\214\346\210\226\351\227\250", nullptr));
#if QT_CONFIG(tooltip)
        actionXnor->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\345\220\214\346\210\226\351\227\250", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionXnor->setShortcut(QCoreApplication::translate("CircuitWindow", "Shift+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWire->setText(QCoreApplication::translate("CircuitWindow", "\345\257\274\347\272\277", nullptr));
#if QT_CONFIG(tooltip)
        actionWire->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\345\257\274\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionWire->setShortcut(QCoreApplication::translate("CircuitWindow", "W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHighLevel->setText(QCoreApplication::translate("CircuitWindow", "\351\253\230\347\224\265\345\271\263", nullptr));
#if QT_CONFIG(tooltip)
        actionHighLevel->setToolTip(QCoreApplication::translate("CircuitWindow", "\346\267\273\345\212\240\351\253\230\347\224\265\345\271\263\350\276\223\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionHighLevel->setShortcut(QCoreApplication::translate("CircuitWindow", "H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRun->setText(QCoreApplication::translate("CircuitWindow", "\350\277\220\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        actionRun->setToolTip(QCoreApplication::translate("CircuitWindow", "\350\277\220\350\241\214\344\273\277\347\234\237", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRun->setShortcut(QCoreApplication::translate("CircuitWindow", "R", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("CircuitWindow", "\345\274\200\345\247\213", nullptr));
        toolBarComponent->setWindowTitle(QCoreApplication::translate("CircuitWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircuitWindow: public Ui_CircuitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITWINDOW_H
