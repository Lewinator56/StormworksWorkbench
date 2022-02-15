#include "vertex_color.h"

VertexColor::VertexColor() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
    init = false;
}
VertexColor::VertexColor(const quint8 &r, const quint8 &g, const quint8 &b, const quint8 &a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
    init = true;
}
