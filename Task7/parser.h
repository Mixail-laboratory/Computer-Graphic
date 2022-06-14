#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include <vector>
#include <QVector2D>
#include <QVector3D>

struct vectors
{
    std::vector<QVector3D> vertices;
    std::vector<QVector3D> normals;
    std::vector<QVector2D> tex_coords;
    std::vector<int> v_indices;
    std::vector<int> uv_indices;
    std::vector<int> n_indices;
};

class Parser
{
public:
    Parser();
    vectors parse(std::istream& is);
};

#endif // PARSER_H
