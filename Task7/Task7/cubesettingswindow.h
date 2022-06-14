#ifndef CUBESETTINGSWINDOW_H
#define CUBESETTINGSWINDOW_H

#include <QMainWindow>
#include "Params.h"

namespace Ui {
class CubeSettingsWindow;
}

class CubeSettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CubeSettingsWindow(Params& p, QWidget *parent = nullptr);
    ~CubeSettingsWindow();

private slots:
    void on_camera_x_valueChanged(double arg1);
    void on_camera_y_valueChanged(double arg1);
    void on_camera_z_valueChanged(double arg1);

    void on_enable_ambient_stateChanged(int arg1);
    void on_ambient_color_button_clicked();

    void on_enable_point_stateChanged(int arg1);
    void on_point_color_button_clicked();
    void on_point_light_x_valueChanged(double arg1);
    void on_point_light_y_valueChanged(double arg1);
    void on_point_light_z_valueChanged(double arg1);

    void on_enable_directed_stateChanged(int arg1);
    void on_dir_color_button_clicked();
    void on_dir_light_x_valueChanged(double arg1);
    void on_dir_light_y_valueChanged(double arg1);
    void on_dir_light_z_valueChanged(double arg1);

    void on_enable_projector_stateChanged(int arg1);
    void on_projector_color_button_clicked();
    void on_projector_pos_x_valueChanged(double arg1);
    void on_projector_pos_y_valueChanged(double arg1);
    void on_projector_pos_z_valueChanged(double arg1);
    void on_projector_dir_x_valueChanged(double arg1);
    void on_projector_dir_y_valueChanged(double arg1);
    void on_projector_dir_z_valueChanged(double arg1);
    void on_spin_inner_angle_valueChanged(double arg1);
    void on_spin_outer_angle_valueChanged(double arg1);



    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::CubeSettingsWindow *ui;
    Params& p;
};

#endif // CUBESETTINGSWINDOW_H
