#include "CubeWindow.h"
#include <QScreen>
#include <iostream>
#include <cmath>

CubeWindow::CubeWindow(const Params &p)
        : p(p) {
    time_now = std::chrono::high_resolution_clock::now();
}

void CubeWindow::initialize() {
    if (m_program) {
        delete m_program;
    }
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "vertexShader2");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "fragmentShader2");
    m_program->link();
    glClearColor(0, 0.5, 0.3, 1);

    m_posAttr = m_program->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_normAttr = m_program->attributeLocation("normAttr");
    Q_ASSERT(m_normAttr != -1);

    m_perspMatrix = m_program->uniformLocation("perspMatrix");
    Q_ASSERT(m_perspMatrix != -1);
    m_transCamMatrix = m_program->uniformLocation("transCamMatrix");
    Q_ASSERT(m_transCamMatrix != -1);
    m_rotMatrix = m_program->uniformLocation("rotMatrix");
    Q_ASSERT(m_rotMatrix != -1);

    m_cameraPos = m_program->uniformLocation("cameraPos");
    Q_ASSERT(m_cameraPos != -1);
    m_colUnif = m_program->uniformLocation("colUnif");
    Q_ASSERT(m_colUnif != -1);

    m_lightPos = m_program->uniformLocation("lightPos");
    Q_ASSERT(m_lightPos != -1);
    m_lightCol = m_program->uniformLocation("lightCol");
    Q_ASSERT(m_lightCol != -1);

    m_dirDir = m_program->uniformLocation("directedDir");
    Q_ASSERT(m_dirDir != -1);
    m_dirCol = m_program->uniformLocation("directedCol");
    Q_ASSERT(m_dirCol != -1);

    m_projectorCol = m_program->uniformLocation("projectorCol");
    Q_ASSERT(m_projectorCol != -1);
    m_projectorDir = m_program->uniformLocation("projectorDir");
    Q_ASSERT(m_projectorDir != -1);
    m_projectorPos = m_program->uniformLocation("projectorPos");
    Q_ASSERT(m_projectorPos != -1);
    m_innerAngle = m_program->uniformLocation("innerAngle");
    Q_ASSERT(m_innerAngle != -1);
    m_outerAngle = m_program->uniformLocation("outerAngle");
    Q_ASSERT(m_outerAngle != -1);
}

void CubeWindow::render() {
    if (m_frame % 10 == 0) {
        auto new_time = std::chrono::high_resolution_clock::now();
        auto delta_t = std::chrono::duration_cast<std::chrono::microseconds>(new_time - time_now).count();
        time_now = new_time;
        FPS = std::round(1000000.0f / delta_t * 10);
    }
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    m_program->bind();

    m_program->setUniformValue(m_cameraPos, p.camera_pos);
    m_program->setUniformValue(m_colUnif, p.ambient_col);

    m_program->setUniformValue(m_lightPos, p.point_light_pos);
    m_program->setUniformValue(m_lightCol, p.point_light_col);

    m_program->setUniformValue(m_dirDir, p.dir_light_dir);
    m_program->setUniformValue(m_dirCol, p.dir_light_col);

    m_program->setUniformValue(m_projectorCol, p.projector_col);
    m_program->setUniformValue(m_projectorDir, p.projector_dir);
    m_program->setUniformValue(m_projectorPos, p.projector_pos);
    m_program->setUniformValue(m_innerAngle, p.inner_angle);
    m_program->setUniformValue(m_outerAngle, p.outer_angle);

    QMatrix4x4 p_matrix;
    p_matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    m_program->setUniformValue(m_perspMatrix, p_matrix);

    QMatrix4x4 trans_cam_matrix;
    trans_cam_matrix.translate(-p.camera_pos);
    m_program->setUniformValue(m_transCamMatrix, trans_cam_matrix);

    QMatrix4x4 rot_matrix;
    rot_matrix.rotate(50.0f * m_frame / screen()->refreshRate(), 0, 0.1, 0);
    m_program->setUniformValue(m_rotMatrix, rot_matrix);

    draw_smth(p.v);

    m_program->release();

    ++m_frame;
    if (!m_device) {
        m_device = new QOpenGLPaintDevice;
    }
    m_device->setSize(size() * devicePixelRatio());
    m_device->setDevicePixelRatio(devicePixelRatio());
    QPainter painter{m_device};
    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 16));
    painter.drawText(QRect(0, 0, 100, 100), Qt::AlignLeft, "FPS: " + QString::number(FPS));
    Q_UNUSED(&painter);
}

void CubeWindow::draw_smth(const vectors &v) {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, v.vertices.data());
    glVertexAttribPointer(m_normAttr, 3, GL_FLOAT, GL_FALSE, 0, v.normals.data());

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_normAttr);

    glDrawElements(GL_TRIANGLES, v.v_indices.size(), GL_UNSIGNED_INT, v.v_indices.data());

    glDisableVertexAttribArray(m_normAttr);
    glDisableVertexAttribArray(m_posAttr);
}
