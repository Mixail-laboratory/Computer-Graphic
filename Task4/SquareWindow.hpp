#pragma once

#include "GLWindow.hpp"
#include <QBasicTimer>
#include <QColor>
#include <QColorDialog>
#include <QKeyEvent>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QVector3D>
#include <memory>

struct VertexData {
    VertexData() {}
    VertexData(QVector3D p, QVector3D n) : position(p), normal(n) {}
    QVector3D position;
    QVector3D normal;
};

class SquareWindow : public QOpenGLWidget, protected QOpenGLFunctions {

Q_OBJECT

public:
    explicit SquareWindow(QWidget *parent = nullptr);
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void change_morph_param(float value);
    void keyPressEvent(QKeyEvent *e) override;

    void change_light_x_param(float value);
    void change_light_y_param(float value);
    void change_light_z_param(float value);

    void change_num_of_cubes(int num);


    void changeyAx(float val);
    void changexAx(float val);

    void change_cube_color();
    void change_light_color();

    void changeN(int new_n);

    float FPS();
    void wheelEvent(QWheelEvent *e) override;
private:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

    void timerEvent(QTimerEvent *e) override;
    void init_cube(float width, int N);
    ~SquareWindow() override = default;

    // Attributes and uniforms handlers.
    GLint posAttr_ = 0;
    GLint normAttr_ = 0;

    // Shader program handler.
    std::unique_ptr<QOpenGLShaderProgram> program_ = nullptr;

    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer indexBuffer{QOpenGLBuffer::IndexBuffer};

    float morph_param = 1.0;
    float light_x_param = 1.0;
    float light_y_param = 1.0;
    float light_z_param = 1.0;
    QMatrix4x4 projection_matrix;

    QVector3D cube_color{1.0f, 0.0f, 0.0f};
    QVector3D light_color{1.0f, 1.0f, 1.0f};

    int n = 2;
    int n_cubes_in_row = 3;
    float zAx = 8;
    float xAx = 2.5;
    float yAx = 2.5;

    float fps = 0;

    // Frame counter for animation.
    int frame_ = 0;

    QVector2D mousePressPosition{0., 0.};
    QVector3D rotationAxis{0., 0., 1.};
    QBasicTimer timer;
};