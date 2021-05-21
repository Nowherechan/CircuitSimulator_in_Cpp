/********************************************************************************
** Form generated from reading UI file 'qgraphicsview_map.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGRAPHICSVIEW_MAP_H
#define UI_QGRAPHICSVIEW_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_QGraphicsView_Map
{
public:

    void setupUi(QFrame *QGraphicsView_Map)
    {
        if (QGraphicsView_Map->objectName().isEmpty())
            QGraphicsView_Map->setObjectName(QString::fromUtf8("QGraphicsView_Map"));
        QGraphicsView_Map->resize(400, 300);

        retranslateUi(QGraphicsView_Map);

        QMetaObject::connectSlotsByName(QGraphicsView_Map);
    } // setupUi

    void retranslateUi(QFrame *QGraphicsView_Map)
    {
        QGraphicsView_Map->setWindowTitle(QCoreApplication::translate("QGraphicsView_Map", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QGraphicsView_Map: public Ui_QGraphicsView_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGRAPHICSVIEW_MAP_H
