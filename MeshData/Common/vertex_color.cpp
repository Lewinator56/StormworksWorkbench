#include "vertex_color.h"

VertexColor::VertexColor() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}
VertexColor::VertexColor(quint8 r, quint8 g, quint8 b, quint8 a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
