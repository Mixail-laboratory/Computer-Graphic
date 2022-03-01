#pragma once
#include "QOpenGLBuffer"
#include "QOpenGLFunctions"
#include "QOpenGLShaderProgram"
#include "QVector3D"

class GeometryEngine: protected QOpenGLFunctions{
public:
    GeometryEngine();
    virtual ~GeometryEngine();

    void drawCubeGeometry(QOpenGLShaderProgram *program);

    void setColor(QVector3D RGBColors);



private:
    void initCubeGeometry();
    QVector3D color = {1, 0 ,0};

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};


