#include "parser.h"
#include <sstream>

Parser::Parser()
{

}

vectors Parser::parse(std::istream& is)
{
    vectors res;
    for (std::string line; std::getline(is, line);)
    {
        std::stringstream ss{line};
        std::string head;
        ss >> head;
        if (head == "v")
        {
            float x, y, z;
            ss >> x >> y >> z;
            res.vertices.emplace_back(x, y, z);
        }
        else if (head == "vt")
        {
            float x, y;
            ss >> x >> y;
            res.tex_coords.emplace_back(x, y);
        }
        else if (head == "vn")
        {
            float x, y, z;
            ss >> x >> y >> z;
            res.normals.emplace_back(x, y, z);
        }
        else if (head == "f")
        {
            int vi, uvi, vni;
            char s;
            for (int i = 0; i < 3; ++i)
            {
                ss >> vi >> s >> uvi >> s >> vni;
                res.v_indices.emplace_back(vi - 1);
                res.uv_indices.emplace_back(uvi - 1);
                res.n_indices.emplace_back(vni - 1);
            }
        }
    }
    return res;
}
