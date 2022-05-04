#include "SquareWindow.hpp"
#include <QColorDialog>
#include <QScreen>
#include <QtMath>
#include <iostream>
#include <QPainter>

SquareWindow::SquareWindow(QWidget *parent) : QOpenGLWidget(parent) {}

void SquareWindow::initializeGL() {
    initializeOpenGLFunctions();
    program_ = std::make_unique<QOpenGLShaderProgram>(this);
    program_->addShaderFromSourceFile(
            QOpenGLShader::Vertex,
            "phong_vertex.glsl");
    program_->addShaderFromSourceFile(
            QOpenGLShader::Fragment,
            "phong_fragment.glsl");
    program_->link();

    posAttr_ = program_->attributeLocation("posAttr");
    normAttr_ = program_->attributeLocation("normAttr");
    Q_ASSERT(posAttr_ != -1);


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    timer.start(30, this);
}

void SquareWindow::paintGL() {
    const auto retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    program_->bind();

    auto start = std::chrono::system_clock::now();

    init_cube(1.5f, n);

    for (int i = 0; i < n_cubes_in_row; i++) {
        for (int j = 0; j < n_cubes_in_row; ++j) {
            QMatrix4x4 view_matrix;
            view_matrix.setToIdentity();
            view_matrix.translate(-xAx + i * 2.5, -yAx + j * 2.5, -zAx);
            view_matrix.rotate(100.0 * frame_ / 59.0, rotationAxis);

            program_->setUniformValue("projection_matrix", projection_matrix);
            program_->setUniformValue("model", view_matrix);
            program_->setUniformValue("view_matrix", view_matrix);
            program_->setUniformValue("morph_param", morph_param);
            program_->setUniformValue("norm_matrix", view_matrix.normalMatrix());
            program_->setUniformValue("viewPos", QVector3D(0.0, 0.0, 0.0));
            program_->setUniformValue("lightPos", QVector3D(light_x_param, light_y_param, light_z_param));
            program_->setUniformValue("objectColor", cube_color);
            program_->setUniformValue("lightColor", light_color);

            program_->setAttributeBuffer(posAttr_, GL_FLOAT, 0, 3, sizeof(VertexData));
            program_->enableAttributeArray(posAttr_);

            program_->setAttributeBuffer(normAttr_, GL_FLOAT, sizeof(QVector3D), 3, sizeof(VertexData));
            program_->enableAttributeArray(normAttr_);
            glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, nullptr);
            program_->disableAttributeArray(posAttr_);

        }
    }
    program_->release();

    ++frame_;
    auto end = std::chrono::system_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    fps = (10e8 / time);
    std :: cout << "FPS: " << std::round(FPS()) << std::endl;
}

void SquareWindow::resizeGL(const int w, const int h) {
    const auto aspect = w / static_cast<double>(h);
    projection_matrix.setToIdentity();
    projection_matrix.perspective(60.0f, aspect, 0.01f, 100.0f);
}

void SquareWindow::change_morph_param(float value) {
    morph_param = value / 1000;
    update();
}

void SquareWindow::change_light_x_param(float value) {
    light_x_param = value;
    update();
}

void SquareWindow::change_light_y_param(float value) {
    light_y_param = value;
    update();
}

void SquareWindow::change_light_z_param(float value) {
    light_z_param = value;
    update();
}

void SquareWindow::mousePressEvent(QMouseEvent *e) {
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
}

void SquareWindow::mouseReleaseEvent(QMouseEvent *e) {
    // Mouse release position - mouse press position
    const auto diff = QVector2D(e->localPos()) - mousePressPosition;

    // Rotation axis is perpendicular to the mouse position difference
    // vector
    rotationAxis = QVector3D(diff.y(), diff.x(), 0.0).normalized();
}

void SquareWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key::Key_Plus) {
        const auto chosen_color = QColorDialog::getColor();
        cube_color =
                QVector3D(chosen_color.red() / 255.0f,
                          chosen_color.green() / 255.0f,
                          chosen_color.blue() / 255.0f);
    }
    else if(e->key() == Qt::Key::Key_Minus){
        const auto chosen_color = QColorDialog::getColor();
        light_color =
                QVector3D(chosen_color.red() / 255.0f,
                          chosen_color.green() / 255.0f,
                          chosen_color.blue() / 255.0f);
    }
}

void SquareWindow::timerEvent(QTimerEvent * /*event*/) { update(); }

void SquareWindow::init_cube(const float width, const int N) {

    auto width_div_2 = width / 2.0f;
    auto step = width / float(N - 1);

    std::vector<VertexData> vertexes;
    vertexes.reserve(6 * pow(N, 2));
    for (auto z = -width_div_2; z <= width_div_2; z += width) {
        for (auto j = 0; j < N; j++) {
            for (auto i = 0; i < N; i++) {
                vertexes.emplace_back(
                        VertexData(QVector3D(-z + i * step * z / width_div_2,
                                             -width_div_2 + j * step, z),
                                   QVector3D(0.0, 0.0, z / width_div_2)));
            }
        }
    }
    for (auto x = -width_div_2; x <= width_div_2; x += width) {
        for (auto k = 0; k < N; k++) {
            for (auto j = 0; j < N; j++) {
                vertexes.emplace_back(
                        VertexData(QVector3D(x, -width_div_2 + j * step,
                                             -x + x * k * step / width_div_2),
                                   QVector3D(x / width_div_2, 0.0, 0.0)));
            }
        }
    }
    for (auto y = -width_div_2; y <= width_div_2; y += width) {
        for (auto i = 0; i < N; i++) {
            for (auto k = 0; k < N; k++) {
                vertexes.emplace_back(
                        VertexData(QVector3D(-width_div_2 + i * step, y,
                                             -y + y * k * step / width_div_2),
                                   QVector3D(0.0, y / width_div_2, 0.0)));
            }
        }
    }

    std::vector<GLuint> indexes;
    int vertex_count = 36 * pow(N - 1, 2);
    indexes.reserve(vertex_count);
    for (int i = 0; i < 6 * N * N; i += N * N) {
        for (int j = 0; j < (N - 1) * (N - 1); j += N) {
            for (int k = 0; k < (N - 1); k++) {
                indexes.emplace_back(i + j + k + N);
                indexes.emplace_back(i + j + k + 0);
                indexes.emplace_back(i + j + k + N + 1);
                indexes.emplace_back(i + j + k + N + 1);
                indexes.emplace_back(i + j + k + 0);
                indexes.emplace_back(i + j + k + 1);
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

void SquareWindow::change_cube_color() {
    const auto chosen_color = QColorDialog::getColor();
    cube_color =
            QVector3D(chosen_color.red() / 255.0f,
                      chosen_color.green() / 255.0f,
                      chosen_color.blue() / 255.0f);
    update();
}

void SquareWindow::change_light_color() {
    const auto chosen_color = QColorDialog::getColor();
    light_color =
            QVector3D(chosen_color.red() / 255.0f,
                      chosen_color.green() / 255.0f,
                      chosen_color.blue() / 255.0f);
    update();
}

void SquareWindow::changeN(int new_n) {
    n = new_n;
    update();
}

void SquareWindow::change_num_of_cubes(int num) {
    n_cubes_in_row = num;
    update();
}


void SquareWindow::changeyAx(float val) {
    yAx = val;
    update();
}

void SquareWindow::changexAx(float val) {
    xAx = val;
    update();
}

float SquareWindow::FPS() {
    update();
    return fps;
}

void SquareWindow::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        zAx -= 1;
    } else if (event->angleDelta().y() < 0) {
        zAx += 1;
    }
    update();
}

