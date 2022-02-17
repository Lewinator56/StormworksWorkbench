#include "vertex.h"

Vertex::Vertex() {

}

Vertex::Vertex(Vector3 *position, VertexColor *color,Vector3 *normal,int index)
{
    this->position = position;
    this->normal = normal;
    this->color = color;
    this->index = index;
}
