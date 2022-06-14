/********************************************************************************
** Form generated from reading UI file 'morphwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORPHWIDGET_H
#define UI_MORPHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MorphWidget
{
public:
    GLWidget *cubeWidget;
    QPushButton *lightColor;
    QSlider *ambientIntensity;
    QPushButton *backColor;
    QComboBox *RockComboBox;
    QComboBox *CracksComboBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *RoadComboBox;
    QComboBox *modeSelector;
    QSlider *speedSlider;
    QDoubleSpinBox *roadAnisotroic;
    QLabel *label_4;
    QDoubleSpinBox *rockAnisotropic;
    QDoubleSpinBox *cracksAnisotropic;
    QDoubleSpinBox *roadActivation;
    QDoubleSpinBox *rockActivation;
    QDoubleSpinBox *cracksActivation;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *MorphWidget)
    {
        if (MorphWidget->objectName().isEmpty())
            MorphWidget->setObjectName(QString::fromUtf8("MorphWidget"));
        MorphWidget->resize(572, 639);
        cubeWidget = new GLWidget(MorphWidget);
        cubeWidget->setObjectName(QString::fromUtf8("cubeWidget"));
        cubeWidget->setGeometry(QRect(30, 10, 471, 391));
        lightColor = new QPushButton(MorphWidget);
        lightColor->setObjectName(QString::fromUtf8("lightColor"));
        lightColor->setGeometry(QRect(200, 590, 141, 29));
        ambientIntensity = new QSlider(MorphWidget);
        ambientIntensity->setObjectName(QString::fromUtf8("ambientIntensity"));
        ambientIntensity->setGeometry(QRect(530, 100, 18, 160));
        ambientIntensity->setOrientation(Qt::Vertical);
        backColor = new QPushButton(MorphWidget);
        backColor->setObjectName(QString::fromUtf8("backColor"));
        backColor->setGeometry(QRect(20, 590, 141, 29));
        RockComboBox = new QComboBox(MorphWidget);
        RockComboBox->addItem(QString());
        RockComboBox->addItem(QString());
        RockComboBox->addItem(QString());
        RockComboBox->setObjectName(QString::fromUtf8("RockComboBox"));
        RockComboBox->setGeometry(QRect(150, 410, 82, 28));
        CracksComboBox = new QComboBox(MorphWidget);
        CracksComboBox->addItem(QString());
        CracksComboBox->addItem(QString());
        CracksComboBox->addItem(QString());
        CracksComboBox->setObjectName(QString::fromUtf8("CracksComboBox"));
        CracksComboBox->setGeometry(QRect(250, 410, 82, 28));
        label = new QLabel(MorphWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 530, 63, 20));
        label_2 = new QLabel(MorphWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 530, 63, 20));
        label_3 = new QLabel(MorphWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 530, 63, 20));
        RoadComboBox = new QComboBox(MorphWidget);
        RoadComboBox->addItem(QString());
        RoadComboBox->addItem(QString());
        RoadComboBox->addItem(QString());
        RoadComboBox->setObjectName(QString::fromUtf8("RoadComboBox"));
        RoadComboBox->setGeometry(QRect(30, 410, 82, 28));
        modeSelector = new QComboBox(MorphWidget);
        modeSelector->addItem(QString());
        modeSelector->addItem(QString());
        modeSelector->setObjectName(QString::fromUtf8("modeSelector"));
        modeSelector->setGeometry(QRect(350, 410, 82, 28));
        speedSlider = new QSlider(MorphWidget);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setGeometry(QRect(380, 600, 160, 18));
        speedSlider->setValue(99);
        speedSlider->setOrientation(Qt::Horizontal);
        roadAnisotroic = new QDoubleSpinBox(MorphWidget);
        roadAnisotroic->setObjectName(QString::fromUtf8("roadAnisotroic"));
        roadAnisotroic->setGeometry(QRect(30, 490, 67, 29));
        roadAnisotroic->setSingleStep(1.000000000000000);
        label_4 = new QLabel(MorphWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 490, 121, 20));
        rockAnisotropic = new QDoubleSpinBox(MorphWidget);
        rockAnisotropic->setObjectName(QString::fromUtf8("rockAnisotropic"));
        rockAnisotropic->setGeometry(QRect(150, 490, 67, 29));
        rockAnisotropic->setSingleStep(1.000000000000000);
        cracksAnisotropic = new QDoubleSpinBox(MorphWidget);
        cracksAnisotropic->setObjectName(QString::fromUtf8("cracksAnisotropic"));
        cracksAnisotropic->setGeometry(QRect(250, 490, 67, 29));
        cracksAnisotropic->setSingleStep(1.000000000000000);
        roadActivation = new QDoubleSpinBox(MorphWidget);
        roadActivation->setObjectName(QString::fromUtf8("roadActivation"));
        roadActivation->setGeometry(QRect(30, 450, 67, 29));
        roadActivation->setMaximum(1.000000000000000);
        roadActivation->setSingleStep(0.100000000000000);
        rockActivation = new QDoubleSpinBox(MorphWidget);
        rockActivation->setObjectName(QString::fromUtf8("rockActivation"));
        rockActivation->setGeometry(QRect(150, 450, 67, 29));
        rockActivation->setMaximum(1.000000000000000);
        rockActivation->setSingleStep(0.100000000000000);
        cracksActivation = new QDoubleSpinBox(MorphWidget);
        cracksActivation->setObjectName(QString::fromUtf8("cracksActivation"));
        cracksActivation->setGeometry(QRect(250, 450, 67, 29));
        cracksActivation->setMaximum(1.000000000000000);
        cracksActivation->setSingleStep(0.100000000000000);
        label_5 = new QLabel(MorphWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(320, 450, 91, 20));
        label_6 = new QLabel(MorphWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(420, 580, 63, 20));

        retranslateUi(MorphWidget);

        QMetaObject::connectSlotsByName(MorphWidget);
    } // setupUi

    void retranslateUi(QWidget *MorphWidget)
    {
        MorphWidget->setWindowTitle(QApplication::translate("MorphWidget", "Form", nullptr));
        lightColor->setText(QApplication::translate("MorphWidget", "change light color", nullptr));
        backColor->setText(QApplication::translate("MorphWidget", "changeBackColor", nullptr));
        RockComboBox->setItemText(0, QApplication::translate("MorphWidget", "Nearest", nullptr));
        RockComboBox->setItemText(1, QApplication::translate("MorphWidget", "Linear", nullptr));
        RockComboBox->setItemText(2, QApplication::translate("MorphWidget", "LinearMipMapLinear", nullptr));

        CracksComboBox->setItemText(0, QApplication::translate("MorphWidget", "Nearest", nullptr));
        CracksComboBox->setItemText(1, QApplication::translate("MorphWidget", "Linear", nullptr));
        CracksComboBox->setItemText(2, QApplication::translate("MorphWidget", "LinearMipMapLinear", nullptr));

        label->setText(QApplication::translate("MorphWidget", "Road", nullptr));
        label_2->setText(QApplication::translate("MorphWidget", "Rock", nullptr));
        label_3->setText(QApplication::translate("MorphWidget", "Cracks", nullptr));
        RoadComboBox->setItemText(0, QApplication::translate("MorphWidget", "Nearest", nullptr));
        RoadComboBox->setItemText(1, QApplication::translate("MorphWidget", "Linear", nullptr));
        RoadComboBox->setItemText(2, QApplication::translate("MorphWidget", "LinearMipMapLinear", nullptr));

        modeSelector->setItemText(0, QApplication::translate("MorphWidget", "mode 1", nullptr));
        modeSelector->setItemText(1, QApplication::translate("MorphWidget", "mode 2", nullptr));

        label_4->setText(QApplication::translate("MorphWidget", "Anisotropic Level", nullptr));
        label_5->setText(QApplication::translate("MorphWidget", "Transparency", nullptr));
        label_6->setText(QApplication::translate("MorphWidget", "speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MorphWidget: public Ui_MorphWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORPHWIDGET_H
