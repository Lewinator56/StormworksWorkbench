#ifndef VERTEX_COLOR_H
#define VERTEX_COLOR_H
#include <QtGlobal>


class VertexColor
{
public:
    VertexColor();
    VertexColor(const quint8 &r, const quint8 &g, const quint8 &b, const quint8 &a);
    quint8 r;
    quint8 g;
    quint8 b;
    quint8 a;
    bool init;
};

#endif // VERTEX_COLOR_H
