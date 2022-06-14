#include "SphereWindow.h"
#include <QScreen>
#include <cmath>

SphereWindow::SphereWindow(const Params &p)
        : p(p) {
    time_now = std::chrono::high_resolution_clock::now();
}

void SphereWindow::initialize() {
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "vertexShader3");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "fragmentShader3");
    m_program->link();


    glClearColor(0, 0.5, 0.3, 1);

    m_posAttr = m_program->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);

    m_perspMatrix = m_program->uniformLocation("perspMatrix");
    Q_ASSERT(m_perspMatrix != -1);
    m_transCamMatrix = m_program->uniformLocation("transCamMatrix");
    Q_ASSERT(m_transCamMatrix != -1);
    m_rotMatrix = m_program->uniformLocation("rotMatrix");
    Q_ASSERT(m_rotMatrix != -1);

    m_dirDir = m_program->uniformLocation("directedDir");
    Q_ASSERT(m_dirDir != -1);
    m_dirCol = m_program->uniformLocation("directedCol");
    Q_ASSERT(m_dirCol != -1);

    /*m_textureNormalMap = m_program->uniformLocation("textureNormalMap");
    Q_ASSERT(m_textureNormalMap != -1);*/
    texture_normal_ = new QOpenGLTexture{QImage("Models/Earth_NormalMap.jpg")};
    texture_color_ = new QOpenGLTexture{QImage("Models/Earth_Albedo.jpg")};
}


void SphereWindow::render() {
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

    m_program->setUniformValue(m_dirDir, p.dir_light_dir);
    m_program->setUniformValue(m_dirCol, p.dir_light_col);

    QMatrix4x4 p_matrix;
    p_matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    m_program->setUniformValue(m_perspMatrix, p_matrix);

    QMatrix4x4 trans_cam_matrix;
    trans_cam_matrix.translate(-p.camera_pos);
    m_program->setUniformValue(m_transCamMatrix, trans_cam_matrix);

    QMatrix4x4 rot_matrix;
    rot_matrix.rotate(30.0f * m_frame / screen()->refreshRate(), 0, 1, 0);
    m_program->setUniformValue(m_rotMatrix, rot_matrix);

    m_program->setUniformValue("textureNormalMap", 0);
    glActiveTexture(GL_TEXTURE0 + 0);
    texture_normal_->bind();
    m_program->setUniformValue("textureColorMap", 1);
    glActiveTexture(GL_TEXTURE0 + 1);
    texture_color_->bind();
    //draw_sphere(p.sphere);
    texture_normal_->release();

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

void SphereWindow::draw_smth(const vectors &v) {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

