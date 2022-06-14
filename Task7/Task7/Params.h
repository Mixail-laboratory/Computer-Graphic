#ifndef PARAMS_H
#define PARAMS_H

#include "parser.h"

struct Params final
{
    vectors v;

    QVector3D camera_pos;

    QVector3D ambient_col;

    QVector3D point_light_pos;
    QVector3D point_light_col;

    QVector3D dir_light_dir;
    QVector3D dir_light_col;

    QVector3D projector_dir;
    QVector3D projector_pos;
    QVector3D projector_col;
    float inner_angle = 0;
    float outer_angle = 0;
};

#endif // PARAMS_H
