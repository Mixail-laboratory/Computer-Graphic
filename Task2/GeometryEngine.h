#ifndef TASK2_GEOMETRYENGINE_H
#define TASK2_GEOMETRYENGINE_H

#include "GLWindow.h"
#include <QBasicTimer>
#include <QColorDialog>
#include <QMouseEvent>

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include "Window.hpp"

class CubeWindow final : public GLWindow {
public:
    void init() override;

    void render() override;

    void makeCube(const float size, const int points);

    void mousePressEvent(QMouseEvent *e) override;

    void mouseReleaseEvent(QMouseEvent *e) override;

    void mouseDoubleClickEvent(QMouseEvent *e) override;

    void timerEvent(QTimerEvent *e) override;

    void keyPressEvent(QKeyEvent *e) override;

    void setFactor(const float size, const int n_parts);

    ~CubeWindow();

private:
    // Attributes and uniforms handlers.
    GLint posAttr_ = 0;
    GLint colorUniform_ = 0;
    GLint matrixUniform_ = 0;
    GLint morphUniform_ = 0;

    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer indexBuffer{QOpenGLBuffer::IndexBuffer};

    QVector4D color{1.0f, 0.0f, 1.0f, 0.2f};

    QVector2D mousePressPosition;
    QVector3D rotationAxis{0.0f, 1.0f, 0.0f};

    QBasicTimer timer;

    float morph_parameter = 0.0f;
    int morph_direction = 1;

    int n_points = 2;

    // Shader program handler.
    std::unique_ptr<QOpenGLShaderProgram> program_ = nullptr;


    // Frame counter for animation.
    int frame_ = 0;
    class Window window;
    class Window MorphWindow = {-20, 325, 1};

};


#endif //TASK2_GEOMETRYENGINE_H
