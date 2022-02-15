#include "triangle.h"

Triangle::Triangle(const Vertex &v1, const Vertex &v2, const Vertex &v3)
{
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
}
