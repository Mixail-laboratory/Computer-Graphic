#ifndef TASK1_MAINWINDOW_H
#define TASK1_MAINWINDOW_H

#include "GeometryEngine.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

#include <memory>

class GeometryEngine;

class MainWindow : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT

public:
    using QOpenGLWidget::QOpenGLWidget;

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent* e) override;
    void timerEvent(QTimerEvent *e) override;


    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();

private:


    QBasicTimer timer;
    QOpenGLShaderProgram program;
    std::unique_ptr<GeometryEngine> geometries = nullptr;

    QMatrix4x4 projection;

    QVector2D mousePressPosition;
    QVector2D mouseCurrentPosition;
    QVector3D rotationAxis;
    qreal angularSpeed = 0;
    QQuaternion rotation;

    int frame_ = 0;
};

#endif //TASK1_MAINWINDOW_H
