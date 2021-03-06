#pragma once

#include "InputController.hpp"
#include "GeometryEngine.hpp"
#include <memory>
#include <QBasicTimer>
#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLWidget>
#include <QQuaternion>
#include <QVector2D>

class GeometryEngine;

class MainWindow : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT

public:
    using QOpenGLWidget::QOpenGLWidget;

protected:
    void mousePressEvent(QMouseEvent *e) override;

    void mouseMoveEvent(QMouseEvent *e) override;

    void wheelEvent(QWheelEvent *e) override;

    void timerEvent(QTimerEvent *e) override;

    void keyPressEvent(QKeyEvent *event) override;

    void initializeGL() override;

    void resizeGL(int w, int h) override;

    void paintGL() override;

    void initShaders(unsigned int currentShader);

private:
    std::unique_ptr<InputController> inputCtrl;

    QBasicTimer timer;
    QOpenGLShaderProgram program;
    QVector<std::shared_ptr<GeometryEngine>> m_objects;

    QMatrix4x4 projection;

    QVector2D mouseCurrentPosition;
    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed = 0;
    QQuaternion rotation;

    Window morphWindow = {1, 30, 5};
    float m_z;

    int frame_ = 0;
};
