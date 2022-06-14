#pragma once

#include <GL/glut.h>
#include <string>
#include <vector>
#include <QVector2D>
#include <QVector3D>
#include <QFile>
#include <QDebug>

struct Vertex { // вершина
    GLuint v_i; // индекс вершины
    GLuint vt_i; // индекс текстурной вершины
    GLuint vn_i; // индекс вершины нормали
};

struct Face{ // грань
    std::vector<Vertex> v; // три вершины у треугольника - полигона
    Face(Vertex v1, Vertex v2, Vertex v3){ // полигон (грань)
        v.push_back(v1);
        v.push_back(v2);
        v.push_back(v3);
    }
};

class MeshObjectLoader {
    std::vector<std::string> coord;
    std::vector<QVector3D> vertex;
    std::vector<QVector2D> uvs;
    std::vector<QVector3D> normals;
    std::vector<Face> faces;

public:
    MeshObjectLoader() = default;

    std::vector<Face> getFaces() const{
        return faces;
    };

    std::vector<QVector3D> getNormals() const{
        return normals;
    };

    std::vector<QVector3D> getVertex() const{
        return vertex;
    };
    std::vector<QVector2D> getUVS() const{
        return uvs;

    };
    GLuint load(const QString &filename); // загрузка по названию файла
    GLuint draw(GLfloat offset = 0);

};


