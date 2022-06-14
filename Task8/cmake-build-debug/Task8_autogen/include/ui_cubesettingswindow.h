/********************************************************************************
** Form generated from reading UI file 'cubesettingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBESETTINGSWINDOW_H
#define UI_CUBESETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CubeSettingsWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QSpinBox *spin_div_n;
    QDoubleSpinBox *dir_light_z;
    QLabel *label_7;
    QLabel *dir_color_label;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *dir_light_y;
    QPushButton *dir_color_button;
    QLabel *label_10;
    QDoubleSpinBox *dir_light_x;
    QCheckBox *enable_directed;
    QLabel *label_11;
    QDoubleSpinBox *camera_x;
    QDoubleSpinBox *camera_z;
    QLabel *label_12;
    QLabel *label_13;
    QDoubleSpinBox *camera_y;
    QLabel *label_14;
    QFrame *line;
    QSpinBox *spin_div_m;
    QLabel *label_2;
    QFrame *line_2;
    QComboBox *comboBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CubeSettingsWindow)
    {
        if (CubeSettingsWindow->objectName().isEmpty())
            CubeSettingsWindow->setObjectName(QString::fromUtf8("CubeSettingsWindow"));
        CubeSettingsWindow->resize(361, 608);
        centralwidget = new QWidget(CubeSettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 231, 21));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        spin_div_n = new QSpinBox(centralwidget);
        spin_div_n->setObjectName(QString::fromUtf8("spin_div_n"));
        spin_div_n->setGeometry(QRect(250, 18, 81, 31));
        spin_div_n->setFont(font);
        spin_div_n->setMinimum(30);
        spin_div_n->setMaximum(200);
        spin_div_n->setSingleStep(10);
        spin_div_n->setValue(100);
        dir_light_z = new QDoubleSpinBox(centralwidget);
        dir_light_z->setObjectName(QString::fromUtf8("dir_light_z"));
        dir_light_z->setGeometry(QRect(230, 280, 67, 31));
        dir_light_z->setFont(font);
        dir_light_z->setMinimum(-10.000000000000000);
        dir_light_z->setMaximum(10.000000000000000);
        dir_light_z->setSingleStep(0.500000000000000);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 280, 21, 31));
        label_7->setFont(font);
        dir_color_label = new QLabel(centralwidget);
        dir_color_label->setObjectName(QString::fromUtf8("dir_color_label"));
        dir_color_label->setGeometry(QRect(230, 230, 91, 31));
        dir_color_label->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 260, 181, 20));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 280, 21, 31));
        label_9->setFont(font);
        dir_light_y = new QDoubleSpinBox(centralwidget);
        dir_light_y->setObjectName(QString::fromUtf8("dir_light_y"));
        dir_light_y->setGeometry(QRect(130, 280, 67, 31));
        dir_light_y->setFont(font);
        dir_light_y->setMinimum(-10.000000000000000);
        dir_light_y->setMaximum(10.000000000000000);
        dir_light_y->setSingleStep(0.500000000000000);
        dir_light_y->setValue(-0.500000000000000);
        dir_color_button = new QPushButton(centralwidget);
        dir_color_button->setObjectName(QString::fromUtf8("dir_color_button"));
        dir_color_button->setGeometry(QRect(10, 230, 181, 29));
        dir_color_button->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 280, 21, 31));
        label_10->setFont(font);
        dir_light_x = new QDoubleSpinBox(centralwidget);
        dir_light_x->setObjectName(QString::fromUtf8("dir_light_x"));
        dir_light_x->setGeometry(QRect(30, 280, 67, 31));
        dir_light_x->setFont(font);
        dir_light_x->setMinimum(-10.000000000000000);
        dir_light_x->setMaximum(10.000000000000000);
        dir_light_x->setSingleStep(0.500000000000000);
        enable_directed = new QCheckBox(centralwidget);
        enable_directed->setObjectName(QString::fromUtf8("enable_directed"));
        enable_directed->setGeometry(QRect(10, 200, 151, 26));
        enable_directed->setFont(font);
        enable_directed->setChecked(true);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 110, 151, 20));
        label_11->setFont(font);
        camera_x = new QDoubleSpinBox(centralwidget);
        camera_x->setObjectName(QString::fromUtf8("camera_x"));
        camera_x->setGeometry(QRect(30, 130, 67, 31));
        camera_x->setFont(font);
        camera_x->setMinimum(-100.000000000000000);
        camera_x->setMaximum(100.000000000000000);
        camera_x->setSingleStep(0.500000000000000);
        camera_x->setValue(0.500000000000000);
        camera_z = new QDoubleSpinBox(centralwidget);
        camera_z->setObjectName(QString::fromUtf8("camera_z"));
        camera_z->setGeometry(QRect(230, 130, 67, 31));
        camera_z->setFont(font);
        camera_z->setMinimum(-100.000000000000000);
        camera_z->setMaximum(100.000000000000000);
        camera_z->setSingleStep(0.100000000000000);
        camera_z->setValue(-1.000000000000000);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(210, 130, 21, 31));
        label_12->setFont(font);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(110, 130, 21, 31));
        label_13->setFont(font);
        camera_y = new QDoubleSpinBox(centralwidget);
        camera_y->setObjectName(QString::fromUtf8("camera_y"));
        camera_y->setGeometry(QRect(130, 130, 67, 31));
        camera_y->setFont(font);
        camera_y->setMinimum(-100.000000000000000);
        camera_y->setMaximum(100.000000000000000);
        camera_y->setSingleStep(0.500000000000000);
        camera_y->setValue(0.500000000000000);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 130, 21, 31));
        label_14->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 90, 351, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        spin_div_m = new QSpinBox(centralwidget);
        spin_div_m->setObjectName(QString::fromUtf8("spin_div_m"));
        spin_div_m->setGeometry(QRect(250, 50, 81, 31));
        spin_div_m->setFont(font);
        spin_div_m->setMinimum(30);
        spin_div_m->setMaximum(200);
        spin_div_m->setSingleStep(10);
        spin_div_m->setValue(100);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 231, 21));
        label_2->setFont(font);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 170, 351, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(141, 330, 151, 28));
        CubeSettingsWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CubeSettingsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CubeSettingsWindow->setStatusBar(statusbar);

        retranslateUi(CubeSettingsWindow);

        QMetaObject::connectSlotsByName(CubeSettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CubeSettingsWindow)
    {
        CubeSettingsWindow->setWindowTitle(QApplication::translate("CubeSettingsWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("CubeSettingsWindow", "Set latitude bins", nullptr));
        label_7->setText(QApplication::translate("CubeSettingsWindow", "Y:", nullptr));
        dir_color_label->setText(QString());
        label_8->setText(QApplication::translate("CubeSettingsWindow", "Point Light Direction", nullptr));
        label_9->setText(QApplication::translate("CubeSettingsWindow", "X:", nullptr));
        dir_color_button->setText(QApplication::translate("CubeSettingsWindow", "Set Directed Light Color", nullptr));
        label_10->setText(QApplication::translate("CubeSettingsWindow", "Z:", nullptr));
        enable_directed->setText(QApplication::translate("CubeSettingsWindow", "Enable Directed", nullptr));
        label_11->setText(QApplication::translate("CubeSettingsWindow", "Camera position", nullptr));
        label_12->setText(QApplication::translate("CubeSettingsWindow", "Z:", nullptr));
        label_13->setText(QApplication::translate("CubeSettingsWindow", "Y:", nullptr));
        label_14->setText(QApplication::translate("CubeSettingsWindow", "X:", nullptr));
        label_2->setText(QApplication::translate("CubeSettingsWindow", "Set longitude bins", nullptr));
        comboBox->setItemText(0, QApplication::translate("CubeSettingsWindow", "Nearest", nullptr));
        comboBox->setItemText(1, QApplication::translate("CubeSettingsWindow", "Linear", nullptr));
        comboBox->setItemText(2, QApplication::translate("CubeSettingsWindow", "Linear MIP map", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CubeSettingsWindow: public Ui_CubeSettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBESETTINGSWINDOW_H
