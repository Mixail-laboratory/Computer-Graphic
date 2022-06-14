#ifndef SPHERE_H
#define SPHERE_H

#include <vector>
#include <QVector3D>
#include "QOpenGLWidget"


class Sphere
{
    float radius_;
    int latitude_bins_;
    int longitude_bins_;
    std::vector<QVector3D> vertices_;
    std::vector<std::vector<GLuint>> indices_;

    void update_vertices();
    void update_indices();

public:
    Sphere(float radius, int latitude_bins, int longitude_bins);
    void set_latitude_bins(int latitude_bins);
    void set_longitude_bins(int longitude_bins);
    void set_radius(int radius);
    const std::vector<QVector3D>& get_vertices() const;
    const std::vector<std::vector<GLuint>>& get_indices() const;

};

#endif // SPHERE_H
