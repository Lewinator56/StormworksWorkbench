#ifndef VERTEX_H
#define VERTEX_H
#include <QtGlobal>
#include "Common/vector3.h"
#include "Common/vertex_color.h"


class Vertex
{
public:
    Vector3 *position;
    VertexColor *color;
    Vector3 *normal;
    int index;

    Vertex();
    Vertex(Vector3 *position,VertexColor *color,Vector3 *normal, const int index);


};

#endif // VERTEX_H
