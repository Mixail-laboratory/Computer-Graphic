#ifndef CUBEWINDOW_H
#define CUBEWINDOW_H

#include "openglwindow.h"
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "Params.h"
#include <chrono>
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QPainter>

class SphereWindow final: public OpenGLWindow
{
public:
    using OpenGLWindow::OpenGLWindow;

    SphereWindow(const Params& p);
    void initialize() override;
    void render() override;

private:
    void draw_smth(const vectors &v);

    GLint m_posAttr = 0;

    GLint m_perspMatrix = 0;
    GLint m_transCamMatrix = 0;
    GLint m_rotMatrix = 0;

    GLint m_dirDir = 0;
    GLint m_dirCol = 0;

    QOpenGLTexture* texture_normal_ = nullptr;
    QOpenGLTexture* texture_color_ = nullptr;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;
    const Params& p;
    std::chrono::high_resolution_clock::time_point time_now;
    int FPS = 0;
    QOpenGLPaintDevice* m_device = 0;
};

#endif // CUBEWINDOW_H
