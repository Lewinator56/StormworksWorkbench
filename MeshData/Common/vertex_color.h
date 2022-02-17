#ifndef VERTEX_COLOR_H
#define VERTEX_COLOR_H
#include <QtGlobal>


class VertexColor
{
public:
    VertexColor();
    VertexColor(quint8 *r, quint8 *g, quint8 *b, quint8 *a);
    quint8* r;
    quint8* g;
    quint8* b;
    quint8* a;
    bool init;
};

#endif // VERTEX_COLOR_H
