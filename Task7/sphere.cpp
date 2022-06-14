#include "sphere.h"

void Sphere::update_vertices()
{
    vertices_.clear();
    for (int lt = 0; lt <= latitude_bins_; ++lt)
    {
        for (int ln = 0; ln <= longitude_bins_; ++ln)
        {
            vertices_.emplace_back(radius_, 3.14 / latitude_bins_ * lt, 6.29 / longitude_bins_ * ln);
        }
    }
}
void Sphere::update_indices()
{
    indices_.clear();
    for (int lt = 0; lt < latitude_bins_; ++lt)
    {
        indices_.emplace_back();
        for (int lg = 0; lg <= longitude_bins_; ++lg)
        {
            indices_[lt].push_back(lg + lt * (longitude_bins_ + 1));
            indices_[lt].push_back(lg + (lt + 1) * (longitude_bins_ + 1));
        }
    }
}

Sphere::Sphere(float radius, int latitude_bins, int longitude_bins)
    : radius_(radius), latitude_bins_(latitude_bins), longitude_bins_(longitude_bins)
{
    update_vertices();
    update_indices();
}

void Sphere::set_latitude_bins(int latitude_bins)
{
    if (latitude_bins_ == latitude_bins)
    {
        return;
    }
    latitude_bins_ = latitude_bins;
    update_vertices();
    update_indices();
}

void Sphere::set_longitude_bins(int longitude_bins)
{
    if (longitude_bins_ == longitude_bins)
    {
        return;
    }
    longitude_bins_ = longitude_bins;
    update_vertices();
    update_indices();
}

void Sphere::set_radius(int radius)
{
    if (radius_ == radius)
    {
        return;
    }
    radius_ = radius;
    update_vertices();
}

const std::vector<QVector3D>& Sphere::get_vertices() const
{
    return vertices_;
}
const std::vector<std::vector<GLuint>>& Sphere::get_indices() const
{
    return indices_;
}
