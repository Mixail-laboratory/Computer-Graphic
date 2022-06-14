/********************************************************************************
** Form generated from reading UI file 'earthwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EARTHWIDGET_H
#define UI_EARTHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EarthWidget
{
public:

    void setupUi(QWidget *EarthWidget)
    {
        if (EarthWidget->objectName().isEmpty())
            EarthWidget->setObjectName(QString::fromUtf8("EarthWidget"));
        EarthWidget->resize(800, 600);

        retranslateUi(EarthWidget);

        QMetaObject::connectSlotsByName(EarthWidget);
    } // setupUi

    void retranslateUi(QWidget *EarthWidget)
    {
        EarthWidget->setWindowTitle(QApplication::translate("EarthWidget", "EarthWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EarthWidget: public Ui_EarthWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EARTHWIDGET_H
