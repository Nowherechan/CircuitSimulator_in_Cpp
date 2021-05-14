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
    QAction *actionexit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *title_Pic;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    Animation_Btn *btn_Digital;
    QSpacerItem *horizontalSpacer_2;
    Animation_Btn *btn_Analog;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(837, 649);
        StartWindow->setMinimumSize(QSize(800, 600));
        actionexit = new QAction(StartWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        title_Pic = new QLabel(centralwidget);
        title_Pic->setObjectName(QString::fromUtf8("title_Pic"));
        title_Pic->setPixmap(QPixmap(QString::fromUtf8(":/src/default_png.png")));
        title_Pic->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title_Pic);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Digital = new Animation_Btn(widget);
        btn_Digital->setObjectName(QString::fromUtf8("btn_Digital"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_Digital->sizePolicy().hasHeightForWidth());
        btn_Digital->setSizePolicy(sizePolicy);
        btn_Digital->setMinimumSize(QSize(200, 200));
        btn_Digital->setMaximumSize(QSize(200, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(24);
        btn_Digital->setFont(font);

        horizontalLayout->addWidget(btn_Digital);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_Analog = new Animation_Btn(widget);
        btn_Analog->setObjectName(QString::fromUtf8("btn_Analog"));
        sizePolicy.setHeightForWidth(btn_Analog->sizePolicy().hasHeightForWidth());
        btn_Analog->setSizePolicy(sizePolicy);
        btn_Analog->setMinimumSize(QSize(200, 200));
        btn_Analog->setMaximumSize(QSize(200, 200));
        btn_Analog->setFont(font);

        horizontalLayout->addWidget(btn_Analog);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 837, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StartWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionexit);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        actionexit->setText(QCoreApplication::translate("StartWindow", "\351\200\200\345\207\272", nullptr));
        title_Pic->setText(QString());
        btn_Digital->setText(QString());
        btn_Analog->setText(QString());
        menu->setTitle(QCoreApplication::translate("StartWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
