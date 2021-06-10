/********************************************************************************
** Form generated from reading UI file 'circuitmap.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCUITMAP_H
#define UI_CIRCUITMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgraphicsview_map.h"

QT_BEGIN_NAMESPACE

class Ui_CircuitMap
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView_Map *map_Circuit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Clear;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Zoom;
    QSpinBox *spinBox_Zoom;
    QSlider *slider_Zoom;
    QPushButton *btn_All;

    void setupUi(QWidget *CircuitMap)
    {
        if (CircuitMap->objectName().isEmpty())
            CircuitMap->setObjectName(QString::fromUtf8("CircuitMap"));
        CircuitMap->resize(800, 600);
        CircuitMap->setMinimumSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(CircuitMap);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        map_Circuit = new QGraphicsView_Map(CircuitMap);
        map_Circuit->setObjectName(QString::fromUtf8("map_Circuit"));
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        map_Circuit->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        map_Circuit->setForegroundBrush(brush1);

        verticalLayout->addWidget(map_Circuit);

        widget = new QWidget(CircuitMap);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_Clear = new QPushButton(widget);
        btn_Clear->setObjectName(QString::fromUtf8("btn_Clear"));

        horizontalLayout->addWidget(btn_Clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_Zoom = new QLabel(widget);
        label_Zoom->setObjectName(QString::fromUtf8("label_Zoom"));

        horizontalLayout->addWidget(label_Zoom);

        spinBox_Zoom = new QSpinBox(widget);
        spinBox_Zoom->setObjectName(QString::fromUtf8("spinBox_Zoom"));

        horizontalLayout->addWidget(spinBox_Zoom);

        slider_Zoom = new QSlider(widget);
        slider_Zoom->setObjectName(QString::fromUtf8("slider_Zoom"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(slider_Zoom->sizePolicy().hasHeightForWidth());
        slider_Zoom->setSizePolicy(sizePolicy);
        slider_Zoom->setMinimumSize(QSize(160, 0));
        slider_Zoom->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider_Zoom);

        btn_All = new QPushButton(widget);
        btn_All->setObjectName(QString::fromUtf8("btn_All"));

        horizontalLayout->addWidget(btn_All);


        verticalLayout->addWidget(widget);


        retranslateUi(CircuitMap);

        QMetaObject::connectSlotsByName(CircuitMap);
    } // setupUi

    void retranslateUi(QWidget *CircuitMap)
    {
        CircuitMap->setWindowTitle(QCoreApplication::translate("CircuitMap", "Form", nullptr));
        btn_Clear->setText(QCoreApplication::translate("CircuitMap", "\346\270\205\351\231\244\345\205\203\344\273\266", nullptr));
        label_Zoom->setText(QCoreApplication::translate("CircuitMap", "\346\224\276\347\274\251", nullptr));
        btn_All->setText(QCoreApplication::translate("CircuitMap", "\346\230\276\347\244\272\345\205\250\351\203\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircuitMap: public Ui_CircuitMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITMAP_H
