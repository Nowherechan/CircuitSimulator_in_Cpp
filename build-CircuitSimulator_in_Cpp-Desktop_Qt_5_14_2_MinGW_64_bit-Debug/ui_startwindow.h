/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "animation_btn.h"

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *title_Pic;
    QSpacerItem *verticalSpacer;
    QWidget *widget_Down;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    Animation_Btn *btn_Digital;
    QLabel *label_Digital;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QMenu *menu_Start;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(800, 600);
        StartWindow->setMinimumSize(QSize(800, 600));
        actionExit = new QAction(StartWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        title_Pic = new QLabel(centralwidget);
        title_Pic->setObjectName(QString::fromUtf8("title_Pic"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title_Pic->sizePolicy().hasHeightForWidth());
        title_Pic->setSizePolicy(sizePolicy);
        title_Pic->setPixmap(QPixmap(QString::fromUtf8(":/src/default_png.png")));
        title_Pic->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title_Pic);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget_Down = new QWidget(centralwidget);
        widget_Down->setObjectName(QString::fromUtf8("widget_Down"));
        horizontalLayout = new QHBoxLayout(widget_Down);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Digital = new Animation_Btn(widget_Down);
        btn_Digital->setObjectName(QString::fromUtf8("btn_Digital"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_Digital->sizePolicy().hasHeightForWidth());
        btn_Digital->setSizePolicy(sizePolicy1);
        btn_Digital->setMinimumSize(QSize(200, 200));
        btn_Digital->setMaximumSize(QSize(200, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(24);
        btn_Digital->setFont(font);

        horizontalLayout->addWidget(btn_Digital);

        label_Digital = new QLabel(widget_Down);
        label_Digital->setObjectName(QString::fromUtf8("label_Digital"));

        horizontalLayout->addWidget(label_Digital);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_Down);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu_Start = new QMenu(menubar);
        menu_Start->setObjectName(QString::fromUtf8("menu_Start"));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartWindow->setStatusBar(statusbar);

        menubar->addAction(menu_Start->menuAction());
        menu_Start->addAction(actionExit);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("StartWindow", "\351\200\200\345\207\272", nullptr));
        title_Pic->setText(QString());
        btn_Digital->setText(QString());
        label_Digital->setText(QCoreApplication::translate("StartWindow", "TextLabel", nullptr));
        menu_Start->setTitle(QCoreApplication::translate("StartWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
