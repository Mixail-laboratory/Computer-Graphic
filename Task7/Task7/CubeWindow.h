#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include "openglwindow.h"
#include <QOpenGLShaderProgram>
#include "Params.h"
#include <chrono>
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QPainter>

class CubeWindow final : public OpenGLWindow {
public:
    using OpenGLWindow::OpenGLWindow;

    CubeWindow(const Params &p);

    void initialize() override;

    void render() override;

    void draw_smth(const vectors &v);

private:
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_normAttr = 0;

    GLint m_perspMatrix = 0;
    GLint m_transCamMatrix = 0;
    GLint m_transCubeMatrix = 0;
    GLint m_rotMatrix = 0;

    GLint m_cameraPos = 0;
    GLint m_colUnif = 0;

    GLint m_lightPos = 0;
    GLint m_lightCol = 0;

    GLint m_dirDir = 0;
    GLint m_dirCol = 0;

    GLint m_projectorCol = 0;
    GLint m_projectorDir = 0;
    GLint m_projectorPos = 0;
    GLint m_innerAngle = 0;
    GLint m_outerAngle = 0;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;
    const Params &p;
    std::chrono::high_resolution_clock::time_point time_now;
    QOpenGLPaintDevice *m_device = 0;
    int FPS = 0;
};

#endif // CUBEWINDOW_H
