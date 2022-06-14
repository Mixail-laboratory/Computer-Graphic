#include "SphereWindow.hpp"
#include <QColorDialog>
#include <QOpenGLContext>
#include <QScreen>
#include <QtMath>
#include <vector>

SphereWindow::SphereWindow(QWidget *parent) : QOpenGLWidget(parent) {}

void SphereWindow::initializeGL() {
    initializeOpenGLFunctions();
    program_ = std::make_unique<QOpenGLShaderProgram>(this);
    program_->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                      "Shaders/cube_vertex.glsl");
    program_->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                      "Shaders/cube_fragment.glsl");
    program_->link();
    posAttr_ = program_->attributeLocation("posAttr");
    Q_ASSERT(posAttr_ != -1);
    normAttr_ = program_->attributeLocation("normAttr");
    Q_ASSERT(normAttr_ != -1);
    textureAttr_ = program_->attributeLocation("textureAttr");
    Q_ASSERT(textureAttr_ != -1);
    tangentAttr_ = program_->attributeLocation("tangentAttr");
    Q_ASSERT(tangentAttr_ != -1);
    bitangentAttr_ = program_->attributeLocation("bitangentAttr");
    Q_ASSERT(bitangentAttr_ != -1);

    init_textures();
    init_sphere(1.0f);
    earth.initialize();
    glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    timer.start(30, this);
}

void SphereWindow::paintGL() {
    const auto retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program_->bind();
    QMatrix4x4 view_matrix;
    QMatrix4x4 model_matrix;

    view_matrix.translate(0.0, 0.0, -1.5);
    model_matrix.translate(0.0, 0.0, -1.25);
//    model_matrix.rotate(45, {0, 1, 0});
//    model_matrix.rotate(90, {1, 0, 0});
//    model_matrix.rotate(90, {0, 1, 0});

//      QMatrix4x4 view_matrix;
    view_matrix.setToIdentity();
    view_matrix.rotate(10.0 * frame_ / 59.0, rotationAxis);
    model_matrix.rotate(10.0 * frame_ / 59.0, rotationAxis);
    view_matrix.scale(0.7f, 0.7f, 0.7f);
    model_matrix.scale(0.7f, 0.7f, 0.7f);

    program_->setUniformValue("projection_matrix", projection_matrix);
    program_->setUniformValue("model", model_matrix);
    program_->setUniformValue("view_matrix", view_matrix);
    program_->setUniformValue("norm_matrix", model_matrix.normalMatrix());
    program_->setUniformValue("viewPos", QVector3D(0.0, 0.0, 0.0));
    program_->setUniformValue("lightPos", QVector3D(0, 0, 2.0));

    texture->bind(0);
    program_->setUniformValue("texture_for_cube", 0);
    normal_map->bind(1);
    program_->setUniformValue("norm_map", 1);

    vertexBuffer.bind();

    float offset = 0;

    program_->enableAttributeArray(posAttr_);
    program_->setAttributeBuffer(posAttr_, GL_FLOAT, offset, 3,
                                 sizeof(VertexData));

    offset += sizeof(QVector3D);
    program_->enableAttributeArray(normAttr_);
    program_->setAttributeBuffer(normAttr_, GL_FLOAT, offset, 3,
                                 sizeof(VertexData));
    offset += sizeof(QVector3D);
    program_->enableAttributeArray(textureAttr_);
    program_->setAttributeBuffer(textureAttr_, GL_FLOAT, offset, 2,
                                 sizeof(VertexData));
    offset += sizeof(QVector2D);
    program_->enableAttributeArray(tangentAttr_);
    program_->setAttributeBuffer(tangentAttr_, GL_FLOAT, offset, 3,
                                 sizeof(VertexData));
    offset += sizeof(QVector3D);
    program_->enableAttributeArray(bitangentAttr_);
    program_->setAttributeBuffer(bitangentAttr_, GL_FLOAT, offset, 3,
                                 sizeof(VertexData));
    indexBuffer.bind();
    context()->functions()->glDrawElements(GL_TRIANGLES, indexBuffer.size(),
                                           GL_UNSIGNED_INT, nullptr);

    program_->disableAttributeArray(posAttr_);
    program_->disableAttributeArray(normAttr_);
    program_->disableAttributeArray(textureAttr_);
    program_->disableAttributeArray(tangentAttr_);
    program_->disableAttributeArray(bitangentAttr_);
    program_->release();
    ++frame_;
}

void SphereWindow::resizeGL(const int w, const int h) {
    const auto aspect = w / static_cast<double>(h);
    projection_matrix.setToIdentity();
    projection_matrix.perspective(60.0f, aspect, 0.1f, 100.0f);
}

void SphereWindow::init_textures() {
    texture = std::make_shared<QOpenGLTexture>(
            QImage("Textures/et.jpg").mirrored());
    normal_map = std::make_shared<QOpenGLTexture>(
            QImage("Textures/en.jpg").mirrored());

    texture->setMinificationFilter(QOpenGLTexture::Nearest);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
    texture->setWrapMode(QOpenGLTexture::Repeat);

    normal_map->setMinificationFilter(QOpenGLTexture::Nearest);
    normal_map->setMagnificationFilter(QOpenGLTexture::Linear);
    normal_map->setWrapMode(QOpenGLTexture::Repeat);
}

void SphereWindow::mousePressEvent(QMouseEvent *e) {
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
    QWidget::mousePressEvent(e);
}

void SphereWindow::mouseReleaseEvent(QMouseEvent *e) {
    // Mouse release position - mouse press position
    const auto diff = QVector2D(e->localPos()) - mousePressPosition;
    rotationAxis = QVector3D(diff.y(), diff.x(), 0.0).normalized();

    update();
}

void SphereWindow::timerEvent(QTimerEvent *) { update(); }



void SphereWindow::init_sphere(float radius) {
    auto lats_ = 100, longs_ = 100;
    auto latStep = 2 * M_PI / static_cast<float>(lats_);
    auto longStep = M_PI / static_cast<float>(longs_);

    std::vector<VertexData> vertexes;
    for (auto i = 0u; i <= longs_; ++i) {
        auto stack_angle = M_PI / 2 - static_cast<float>(i) * longStep;
        auto xy = radius * cos(stack_angle);
        GLfloat z = radius * sin(stack_angle);

        for (auto j = 0u; j <= lats_; ++j) {
            GLfloat sector_angle = static_cast<float>(j) * latStep;
            GLfloat x = xy * cos(sector_angle);
            GLfloat y = xy * sin(sector_angle);

            vertexes.emplace_back(QVector3D{x, y, z},
                                  QVector3D{x / radius, y / radius, z / radius},
                                  QVector2D{static_cast<float>(j) / lats_, static_cast<float>(i) / longs_},
                                  QVector3D{1, 1, 1},
                                  QVector3D{y / radius - z / radius,
                                            z / radius - x / radius,
                                            x / radius - y / radius});
        }
    }

    std::vector<GLuint> indexes;
    for (auto i = 0u; i < lats_; ++i) {
        auto k1 = i * (longs_ + 1);
        auto k2 = k1 + longs_ + 1;

        for (auto j = 0u; j < longs_; ++j, ++k1, ++k2) {
            if (i != 0) {
                indexes.push_back(k1);
                indexes.push_back(k2);
                indexes.push_back(k1 + 1u);
            }

            if (i != (lats_ - 1)) {
                indexes.push_back(k1 + 1u);
                indexes.push_back(k2);
                indexes.push_back(k2 + 1u);
            }
        }
    }

    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(vertexes.data(),
                          static_cast<int>(vertexes.size() * sizeof(VertexData)));

    indexBuffer.create();
    indexBuffer.bind();
    indexBuffer.allocate(indexes.data(),
                         static_cast<int>(indexes.size() * sizeof(GLuint)));
}