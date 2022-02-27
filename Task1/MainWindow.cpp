#include "MainWindow.h"
#include <QMouseEvent>
#include <QScreen>

void MainWindow::mousePressEvent(QMouseEvent *e) {
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
}


void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    mouseCurrentPosition = QVector2D(e->localPos()) - mousePressPosition;

    // Rotation axis is perpendicular to the mouse position difference
    // vector
    QVector3D n = QVector3D(mouseCurrentPosition.y(), mouseCurrentPosition.x(), 0.0).normalized();

    // Accelerate angular speed relative to the length of the mouse sweep
    qreal acc = mouseCurrentPosition.length() / 100.0;

    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    // Increase angular speed
    angularSpeed = acc;

}

void MainWindow::timerEvent(QTimerEvent *) {

    rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

    update();
}

void MainWindow::initializeGL() {
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    initShaders();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);

    glEnable(GL_MULTISAMPLE);

    geometries = std::make_unique<GeometryEngine>();

    // Use QBasicTimer because its faster than QTimer
    timer.start(12, this);
}

void MainWindow::initShaders() {
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                         "Shaders/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                         "Shaders/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}

void MainWindow::resizeGL(int w, int h) {
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
}

void MainWindow::paintGL() {
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(0.0, 0.0, -5.0f);
    matrix.rotate(rotation);
    // Set modelview-projection matrix
    program.setUniformValue("mvp_matrix", projection * matrix);

    // Draw cube geometry
    geometries->drawCubeGeometry(&program);

    ++frame_;
}

