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



private:
    void initCubeGeometry();

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};


