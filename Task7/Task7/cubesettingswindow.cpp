#include "cubesettingswindow.h"
#include "ui_cubesettingswindow.h"

#include <QColorDialog>
#include <QVector3D>
#include <iostream>
#include <fstream>

CubeSettingsWindow::CubeSettingsWindow(Params& p, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CubeSettingsWindow),
    p(p)
{
    ui->setupUi(this);
    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, "white");

    p.ambient_col = {0, 0, 0};
    ui->ambient_color_label->setAutoFillBackground(true);
    ui->ambient_color_label->setPalette(sample_palette);

    p.point_light_col = {0, 0, 0};
    ui->point_color_label->setAutoFillBackground(true);
    ui->point_color_label->setPalette(sample_palette);

    p.dir_light_col = {0, 0, 0};
    ui->dir_color_label->setAutoFillBackground(true);
    ui->dir_color_label->setPalette(sample_palette);

    p.projector_col = {0, 0, 0};
    ui->projector_color_label->setAutoFillBackground(true);
    ui->projector_color_label->setPalette(sample_palette);
}

CubeSettingsWindow::~CubeSettingsWindow()
{
    delete ui;
}


void CubeSettingsWindow::on_camera_x_valueChanged(double arg1)
{
    p.camera_pos.setX(arg1);
}

void CubeSettingsWindow::on_camera_y_valueChanged(double arg1)
{
    p.camera_pos.setY(arg1);
}

void CubeSettingsWindow::on_camera_z_valueChanged(double arg1)
{
    p.camera_pos.setZ(arg1);
}


void CubeSettingsWindow::on_enable_ambient_stateChanged(int arg1)
{
    static QColor color = ui->ambient_color_label->palette().color(QPalette::Window);
    if (arg1){
        p.ambient_col = QVector3D{color.redF(), color.greenF(), color.blueF()};
    }
    else{
        p.ambient_col = QVector3D(0, 0, 0);
    }
}

void CubeSettingsWindow::on_ambient_color_button_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    p.ambient_col = QVector3D{color.redF(), color.greenF(), color.blueF()};

    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, color);
    ui->ambient_color_label->setAutoFillBackground(true);
    ui->ambient_color_label->setPalette(sample_palette);
}


void CubeSettingsWindow::on_enable_point_stateChanged(int arg1)
{
    static QColor color = ui->point_color_label->palette().color(QPalette::Window);
    if (arg1){
        p.point_light_col = QVector3D{static_cast<float>(color.redF()), static_cast<float>(color.greenF()), color.blueF()};
    }
    else{
        p.point_light_col = QVector3D(0, 0, 0);
    }
}

void CubeSettingsWindow::on_point_color_button_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    p.point_light_col = QVector3D{static_cast<float>(color.redF()), color.greenF(), color.blueF()};

    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, color);
    ui->point_color_label->setAutoFillBackground(true);
    ui->point_color_label->setPalette(sample_palette);
}

void CubeSettingsWindow::on_point_light_x_valueChanged(double arg1)
{
    p.point_light_pos.setX(arg1);
}

void CubeSettingsWindow::on_point_light_y_valueChanged(double arg1)
{
    p.point_light_pos.setY(arg1);
}

void CubeSettingsWindow::on_point_light_z_valueChanged(double arg1)
{
    p.point_light_pos.setZ(arg1);
}


void CubeSettingsWindow::on_enable_directed_stateChanged(int arg1)
{
    static QColor color = ui->dir_color_label->palette().color(QPalette::Window);
    if (arg1){
        p.dir_light_col = QVector3D{color.redF(), color.greenF(), color.blueF()};
    }
    else{
        p.dir_light_col = QVector3D(0, 0, 0);
    }
}

void CubeSettingsWindow::on_dir_color_button_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    p.dir_light_col = QVector3D{color.redF(), color.greenF(), color.blueF()};

    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, color);
    ui->dir_color_label->setAutoFillBackground(true);
    ui->dir_color_label->setPalette(sample_palette);
}

void CubeSettingsWindow::on_dir_light_x_valueChanged(double arg1)
{
    p.dir_light_dir.setX(arg1);
}

void CubeSettingsWindow::on_dir_light_y_valueChanged(double arg1)
{
    p.dir_light_dir.setY(arg1);
}

void CubeSettingsWindow::on_dir_light_z_valueChanged(double arg1)
{
    p.dir_light_dir.setZ(arg1);
}


void CubeSettingsWindow::on_enable_projector_stateChanged(int arg1)
{
    static QColor color = ui->projector_color_label->palette().color(QPalette::Window);
    if (arg1){
        p.projector_col = QVector3D{color.redF(), color.greenF(), color.blueF()};
    }
    else{
        p.projector_col = QVector3D(0, 0, 0);
    }
}
void CubeSettingsWindow::on_projector_color_button_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    p.projector_col = QVector3D{color.redF(), color.greenF(), color.blueF()};

    QPalette sample_palette;
    sample_palette.setColor(QPalette::Window, color);
    ui->projector_color_label->setAutoFillBackground(true);
    ui->projector_color_label->setPalette(sample_palette);
}
void CubeSettingsWindow::on_projector_pos_x_valueChanged(double arg1)
{
    p.projector_pos.setX(arg1);
}
void CubeSettingsWindow::on_projector_pos_y_valueChanged(double arg1)
{
    p.projector_pos.setY(arg1);
}
void CubeSettingsWindow::on_projector_pos_z_valueChanged(double arg1)
{
    p.projector_pos.setZ(arg1);
}
void CubeSettingsWindow::on_projector_dir_x_valueChanged(double arg1)
{
    p.projector_dir.setX(arg1);
}
void CubeSettingsWindow::on_projector_dir_y_valueChanged(double arg1)
{
    p.projector_dir.setY(arg1);
}
void CubeSettingsWindow::on_projector_dir_z_valueChanged(double arg1)
{
    p.projector_dir.setZ(arg1);
}
void CubeSettingsWindow::on_spin_inner_angle_valueChanged(double arg1)
{
    p.inner_angle = arg1;
    ui->spin_outer_angle->setMinimum(arg1);
}

void CubeSettingsWindow::on_spin_outer_angle_valueChanged(double arg1)
{
    p.outer_angle = arg1;
}

void CubeSettingsWindow::on_comboBox_currentIndexChanged(int index)
{
    std::vector<std::string> files{"C:\\Qt\\Examples\\Qt-6.2.3\\opengl\\MeshObjects\\Materials\\MeshSphere.obj",
                                  "C:\\Qt\\Examples\\Qt-6.2.3\\opengl\\MeshObjects\\Materials\\MeshCube.obj",
                                  "C:\\Qt\\Examples\\Qt-6.2.3\\opengl\\MeshObjects\\Materials\\MeshHouse.obj"};
    std::fstream fs;
    fs.open(files[index]);
    auto v = Parser().parse(fs);
    fs.close();
    p.v = v;
}

