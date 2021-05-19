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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CircuitMap
{
public:

    void setupUi(QWidget *CircuitMap)
    {
        if (CircuitMap->objectName().isEmpty())
            CircuitMap->setObjectName(QString::fromUtf8("CircuitMap"));
        CircuitMap->resize(400, 300);

        retranslateUi(CircuitMap);

        QMetaObject::connectSlotsByName(CircuitMap);
    } // setupUi

    void retranslateUi(QWidget *CircuitMap)
    {
        CircuitMap->setWindowTitle(QCoreApplication::translate("CircuitMap", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircuitMap: public Ui_CircuitMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITMAP_H
