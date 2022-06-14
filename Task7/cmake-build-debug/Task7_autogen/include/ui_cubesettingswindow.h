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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CubeSettingsWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ambient_color_button;
    QLabel *ambient_color_label;
    QLabel *point_color_label;
    QPushButton *point_color_button;
    QLabel *label_3;
    QDoubleSpinBox *point_light_x;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *point_light_y;
    QDoubleSpinBox *point_light_z;
    QDoubleSpinBox *dir_light_z;
    QLabel *label_7;
    QLabel *dir_color_label;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *dir_light_y;
    QPushButton *dir_color_button;
    QLabel *label_10;
    QDoubleSpinBox *dir_light_x;
    QCheckBox *enable_ambient;
    QCheckBox *enable_point;
    QCheckBox *enable_directed;
    QLabel *label_11;
    QDoubleSpinBox *camera_x;
    QDoubleSpinBox *camera_z;
    QLabel *label_12;
    QLabel *label_13;
    QDoubleSpinBox *camera_y;
    QLabel *label_14;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *projector_color_label;
    QDoubleSpinBox *projector_pos_z;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QDoubleSpinBox *projector_pos_y;
    QCheckBox *enable_projector;
    QDoubleSpinBox *projector_pos_x;
    QFrame *line_5;
    QPushButton *projector_color_button;
    QDoubleSpinBox *projector_dir_x;
    QDoubleSpinBox *projector_dir_z;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *projector_dir_y;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QDoubleSpinBox *spin_inner_angle;
    QDoubleSpinBox *spin_outer_angle;
    QComboBox *comboBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CubeSettingsWindow)
    {
        if (CubeSettingsWindow->objectName().isEmpty())
            CubeSettingsWindow->setObjectName(QString::fromUtf8("CubeSettingsWindow"));
        CubeSettingsWindow->resize(706, 608);
        centralwidget = new QWidget(CubeSettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ambient_color_button = new QPushButton(centralwidget);
        ambient_color_button->setObjectName(QString::fromUtf8("ambient_color_button"));
        ambient_color_button->setGeometry(QRect(370, 40, 181, 31));
        QFont font;
        font.setPointSize(9);
        ambient_color_button->setFont(font);
        ambient_color_label = new QLabel(centralwidget);
        ambient_color_label->setObjectName(QString::fromUtf8("ambient_color_label"));
        ambient_color_label->setGeometry(QRect(590, 40, 91, 31));
        ambient_color_label->setFont(font);
        point_color_label = new QLabel(centralwidget);
        point_color_label->setObjectName(QString::fromUtf8("point_color_label"));
        point_color_label->setGeometry(QRect(590, 120, 91, 31));
        point_color_label->setFont(font);
        point_color_button = new QPushButton(centralwidget);
        point_color_button->setObjectName(QString::fromUtf8("point_color_button"));
        point_color_button->setGeometry(QRect(370, 120, 181, 29));
        point_color_button->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 150, 181, 21));
        label_3->setFont(font);
        point_light_x = new QDoubleSpinBox(centralwidget);
        point_light_x->setObjectName(QString::fromUtf8("point_light_x"));
        point_light_x->setGeometry(QRect(390, 170, 67, 31));
        point_light_x->setFont(font);
        point_light_x->setMinimum(-100.000000000000000);
        point_light_x->setMaximum(100.000000000000000);
        point_light_x->setSingleStep(0.500000000000000);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(370, 170, 21, 31));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 170, 21, 31));
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(570, 170, 21, 31));
        label_6->setFont(font);
        point_light_y = new QDoubleSpinBox(centralwidget);
        point_light_y->setObjectName(QString::fromUtf8("point_light_y"));
        point_light_y->setGeometry(QRect(490, 170, 67, 31));
        point_light_y->setFont(font);
        point_light_y->setMinimum(-100.000000000000000);
        point_light_y->setMaximum(100.000000000000000);
        point_light_y->setSingleStep(0.500000000000000);
        point_light_z = new QDoubleSpinBox(centralwidget);
        point_light_z->setObjectName(QString::fromUtf8("point_light_z"));
        point_light_z->setGeometry(QRect(590, 170, 67, 31));
        point_light_z->setFont(font);
        point_light_z->setMinimum(-100.000000000000000);
        point_light_z->setMaximum(100.000000000000000);
        point_light_z->setSingleStep(0.500000000000000);
        dir_light_z = new QDoubleSpinBox(centralwidget);
        dir_light_z->setObjectName(QString::fromUtf8("dir_light_z"));
        dir_light_z->setGeometry(QRect(590, 300, 67, 31));
        dir_light_z->setFont(font);
        dir_light_z->setMinimum(-10.000000000000000);
        dir_light_z->setMaximum(10.000000000000000);
        dir_light_z->setSingleStep(0.500000000000000);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 300, 21, 31));
        label_7->setFont(font);
        dir_color_label = new QLabel(centralwidget);
        dir_color_label->setObjectName(QString::fromUtf8("dir_color_label"));
        dir_color_label->setGeometry(QRect(590, 250, 91, 31));
        dir_color_label->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(370, 280, 181, 20));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(370, 300, 21, 31));
        label_9->setFont(font);
        dir_light_y = new QDoubleSpinBox(centralwidget);
        dir_light_y->setObjectName(QString::fromUtf8("dir_light_y"));
        dir_light_y->setGeometry(QRect(490, 300, 67, 31));
        dir_light_y->setFont(font);
        dir_light_y->setMinimum(-10.000000000000000);
        dir_light_y->setMaximum(10.000000000000000);
        dir_light_y->setSingleStep(0.500000000000000);
        dir_color_button = new QPushButton(centralwidget);
        dir_color_button->setObjectName(QString::fromUtf8("dir_color_button"));
        dir_color_button->setGeometry(QRect(370, 250, 181, 29));
        dir_color_button->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(570, 300, 21, 31));
        label_10->setFont(font);
        dir_light_x = new QDoubleSpinBox(centralwidget);
        dir_light_x->setObjectName(QString::fromUtf8("dir_light_x"));
        dir_light_x->setGeometry(QRect(390, 300, 67, 31));
        dir_light_x->setFont(font);
        dir_light_x->setMinimum(-10.000000000000000);
        dir_light_x->setMaximum(10.000000000000000);
        dir_light_x->setSingleStep(0.500000000000000);
        enable_ambient = new QCheckBox(centralwidget);
        enable_ambient->setObjectName(QString::fromUtf8("enable_ambient"));
        enable_ambient->setGeometry(QRect(370, 10, 151, 26));
        enable_ambient->setFont(font);
        enable_point = new QCheckBox(centralwidget);
        enable_point->setObjectName(QString::fromUtf8("enable_point"));
        enable_point->setGeometry(QRect(370, 90, 151, 26));
        enable_point->setFont(font);
        enable_directed = new QCheckBox(centralwidget);
        enable_directed->setObjectName(QString::fromUtf8("enable_directed"));
        enable_directed->setGeometry(QRect(370, 220, 151, 26));
        enable_directed->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 210, 151, 20));
        label_11->setFont(font);
        camera_x = new QDoubleSpinBox(centralwidget);
        camera_x->setObjectName(QString::fromUtf8("camera_x"));
        camera_x->setGeometry(QRect(40, 230, 67, 31));
        camera_x->setFont(font);
        camera_x->setMinimum(-100.000000000000000);
        camera_x->setMaximum(100.000000000000000);
        camera_x->setSingleStep(0.500000000000000);
        camera_z = new QDoubleSpinBox(centralwidget);
        camera_z->setObjectName(QString::fromUtf8("camera_z"));
        camera_z->setGeometry(QRect(240, 230, 67, 31));
        camera_z->setFont(font);
        camera_z->setMinimum(-100.000000000000000);
        camera_z->setMaximum(100.000000000000000);
        camera_z->setSingleStep(0.500000000000000);
        camera_z->setValue(3.000000000000000);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(220, 230, 21, 31));
        label_12->setFont(font);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(120, 230, 21, 31));
        label_13->setFont(font);
        camera_y = new QDoubleSpinBox(centralwidget);
        camera_y->setObjectName(QString::fromUtf8("camera_y"));
        camera_y->setGeometry(QRect(140, 230, 67, 31));
        camera_y->setFont(font);
        camera_y->setMinimum(-100.000000000000000);
        camera_y->setMaximum(100.000000000000000);
        camera_y->setSingleStep(0.500000000000000);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 230, 21, 31));
        label_14->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 190, 351, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 260, 351, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(350, 70, 351, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(350, 200, 351, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        projector_color_label = new QLabel(centralwidget);
        projector_color_label->setObjectName(QString::fromUtf8("projector_color_label"));
        projector_color_label->setGeometry(QRect(590, 380, 91, 31));
        projector_color_label->setFont(font);
        projector_pos_z = new QDoubleSpinBox(centralwidget);
        projector_pos_z->setObjectName(QString::fromUtf8("projector_pos_z"));
        projector_pos_z->setGeometry(QRect(590, 430, 67, 31));
        projector_pos_z->setFont(font);
        projector_pos_z->setMinimum(-100.000000000000000);
        projector_pos_z->setMaximum(100.000000000000000);
        projector_pos_z->setSingleStep(0.500000000000000);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(570, 430, 21, 31));
        label_15->setFont(font);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(370, 430, 21, 31));
        label_16->setFont(font);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(370, 410, 181, 21));
        label_17->setFont(font);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(470, 430, 21, 31));
        label_18->setFont(font);
        projector_pos_y = new QDoubleSpinBox(centralwidget);
        projector_pos_y->setObjectName(QString::fromUtf8("projector_pos_y"));
        projector_pos_y->setGeometry(QRect(490, 430, 67, 31));
        projector_pos_y->setFont(font);
        projector_pos_y->setMinimum(-100.000000000000000);
        projector_pos_y->setMaximum(100.000000000000000);
        projector_pos_y->setSingleStep(0.500000000000000);
        enable_projector = new QCheckBox(centralwidget);
        enable_projector->setObjectName(QString::fromUtf8("enable_projector"));
        enable_projector->setGeometry(QRect(370, 350, 151, 26));
        enable_projector->setFont(font);
        projector_pos_x = new QDoubleSpinBox(centralwidget);
        projector_pos_x->setObjectName(QString::fromUtf8("projector_pos_x"));
        projector_pos_x->setGeometry(QRect(390, 430, 67, 31));
        projector_pos_x->setFont(font);
        projector_pos_x->setMinimum(-100.000000000000000);
        projector_pos_x->setMaximum(100.000000000000000);
        projector_pos_x->setSingleStep(0.500000000000000);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(350, 330, 351, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        projector_color_button = new QPushButton(centralwidget);
        projector_color_button->setObjectName(QString::fromUtf8("projector_color_button"));
        projector_color_button->setGeometry(QRect(370, 380, 181, 29));
        projector_color_button->setFont(font);
        projector_dir_x = new QDoubleSpinBox(centralwidget);
        projector_dir_x->setObjectName(QString::fromUtf8("projector_dir_x"));
        projector_dir_x->setGeometry(QRect(390, 480, 67, 31));
        projector_dir_x->setFont(font);
        projector_dir_x->setMinimum(-10.000000000000000);
        projector_dir_x->setMaximum(10.000000000000000);
        projector_dir_x->setSingleStep(0.500000000000000);
        projector_dir_z = new QDoubleSpinBox(centralwidget);
        projector_dir_z->setObjectName(QString::fromUtf8("projector_dir_z"));
        projector_dir_z->setGeometry(QRect(590, 480, 67, 31));
        projector_dir_z->setFont(font);
        projector_dir_z->setMinimum(-10.000000000000000);
        projector_dir_z->setMaximum(10.000000000000000);
        projector_dir_z->setSingleStep(0.500000000000000);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(370, 460, 181, 20));
        label_19->setFont(font);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(570, 480, 21, 31));
        label_20->setFont(font);
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(470, 480, 21, 31));
        label_21->setFont(font);
        projector_dir_y = new QDoubleSpinBox(centralwidget);
        projector_dir_y->setObjectName(QString::fromUtf8("projector_dir_y"));
        projector_dir_y->setGeometry(QRect(490, 480, 67, 31));
        projector_dir_y->setFont(font);
        projector_dir_y->setMinimum(-10.000000000000000);
        projector_dir_y->setMaximum(10.000000000000000);
        projector_dir_y->setSingleStep(0.500000000000000);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(370, 480, 21, 31));
        label_22->setFont(font);
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(370, 520, 91, 21));
        label_23->setFont(font);
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(370, 550, 91, 21));
        label_24->setFont(font);
        spin_inner_angle = new QDoubleSpinBox(centralwidget);
        spin_inner_angle->setObjectName(QString::fromUtf8("spin_inner_angle"));
        spin_inner_angle->setGeometry(QRect(470, 520, 67, 29));
        spin_inner_angle->setMaximum(90.000000000000000);
        spin_outer_angle = new QDoubleSpinBox(centralwidget);
        spin_outer_angle->setObjectName(QString::fromUtf8("spin_outer_angle"));
        spin_outer_angle->setGeometry(QRect(470, 550, 67, 29));
        spin_outer_angle->setMaximum(90.000000000000000);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(90, 330, 241, 28));
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
        ambient_color_button->setText(QApplication::translate("CubeSettingsWindow", "Set Ambient Color", nullptr));
        ambient_color_label->setText(QString());
        point_color_label->setText(QString());
        point_color_button->setText(QApplication::translate("CubeSettingsWindow", "Set Point Light Color", nullptr));
        label_3->setText(QApplication::translate("CubeSettingsWindow", "Point Light Coordinates", nullptr));
        label_4->setText(QApplication::translate("CubeSettingsWindow", "X:", nullptr));
        label_5->setText(QApplication::translate("CubeSettingsWindow", "Y:", nullptr));
        label_6->setText(QApplication::translate("CubeSettingsWindow", "Z:", nullptr));
        label_7->setText(QApplication::translate("CubeSettingsWindow", "Y:", nullptr));
        dir_color_label->setText(QString());
        label_8->setText(QApplication::translate("CubeSettingsWindow", "Point Light Direction", nullptr));
        label_9->setText(QApplication::translate("CubeSettingsWindow", "X:", nullptr));
        dir_color_button->setText(QApplication::translate("CubeSettingsWindow", "Set Directed Light Color", nullptr));
        label_10->setText(QApplication::translate("CubeSettingsWindow", "Z:", nullptr));
        enable_ambient->setText(QApplication::translate("CubeSettingsWindow", "Enable Ambient", nullptr));
        enable_point->setText(QApplication::translate("CubeSettingsWindow", "Enable Point", nullptr));
        enable_directed->setText(QApplication::translate("CubeSettingsWindow", "Enable Directed", nullptr));
        label_11->setText(QApplication::translate("CubeSettingsWindow", "Camera position", nullptr));
        label_12->setText(QApplication::translate("CubeSettingsWindow", "Z:", nullptr));
        label_13->setText(QApplication::translate("CubeSettingsWindow", "Y:", nullptr));
        label_14->setText(QApplication::translate("CubeSettingsWindow", "X:", nullptr));
        projector_color_label->setText(QString());
        label_15->setText(QApplication::translate("CubeSettingsWindow", "Z:", nullptr));
        label_16->setText(QApplication::translate("CubeSettingsWindow", "X:", nullptr));
        label_17->setText(QApplication::translate("CubeSettingsWindow", "Projector Coordinates", nullptr));
        label_18->setText(QApplication::translate("CubeSettingsWindow", "Y:", nullptr));
        enable_projector->setText(QApplication::translate("CubeSettingsWindow", "Enable Projector", nullptr));
        projector_color_button->setText(QApplication::translate("CubeSettingsWindow", "Set Projector Color", nullptr));
        label_19->setText(QApplication::translate("CubeSettingsWindow", "Point Light Direction", nullptr));
        label_20->setText(QApplication::translate("CubeSettingsWindow", "Z:", nullptr));
        label_21->setText(QApplication::translate("CubeSettingsWindow", "Y:", nullptr));
        label_22->setText(QApplication::translate("CubeSettingsWindow", "X:", nullptr));
        label_23->setText(QApplication::translate("CubeSettingsWindow", "Inner angle", nullptr));
        label_24->setText(QApplication::translate("CubeSettingsWindow", "Outer angle", nullptr));
        comboBox->setItemText(0, QApplication::translate("CubeSettingsWindow", "Sphere", nullptr));
        comboBox->setItemText(1, QApplication::translate("CubeSettingsWindow", "Cube", nullptr));
        comboBox->setItemText(2, QApplication::translate("CubeSettingsWindow", "House", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CubeSettingsWindow: public Ui_CubeSettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBESETTINGSWINDOW_H
