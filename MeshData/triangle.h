#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vertex.h"


class Triangle
{
public:
    Vertex *vertices[3];

    Triangle(Vertex *v1,Vertex *v2,Vertex *v3);
};

#endif // TRIANGLE_H
