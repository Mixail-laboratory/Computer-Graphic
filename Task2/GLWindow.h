#ifndef TASK2_GLWINDOW_H
#define TASK2_GLWINDOW_H

#include <QWindow>

#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>
#include <memory>

class QEvent;

class QExposeEvent;


class GLWindow : public QWindow, protected QOpenGLFunctions{
Q_OBJECT
public:
    explicit GLWindow(QWindow *parent = nullptr);

public:
    virtual void init();

    virtual void render();

    virtual void render(const QPainter &painter);

public:
    void setAnimated(bool animating = false);

public slots:

    void renderNow();

    void renderLater();

protected:
    bool event(QEvent *event) override;

    void exposeEvent(QExposeEvent *event) override;

private:
    bool animating_ = false;
    std::unique_ptr<QOpenGLContext> context_ = nullptr;
    std::unique_ptr<QOpenGLPaintDevice> device_ = nullptr;
};

#endif
