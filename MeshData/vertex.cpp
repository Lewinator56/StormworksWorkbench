#include "vertex.h"

Vertex::Vertex() {

}

Vertex::Vertex(const Vector3 &position, const VertexColor &color, const Vector3 &normal, const int &index)
{
    this->position = position;
    this->normal = normal;
    this->color = color;
    this->index = index;
}
