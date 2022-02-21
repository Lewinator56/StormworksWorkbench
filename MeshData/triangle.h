#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vertex.h"
#include <QObject>


class Triangle : public QObject
{
    Q_OBJECT
public:
    Vertex *vertices[3];

    Triangle(Vertex *v1,Vertex *v2,Vertex *v3);

    Q_INVOKABLE Vertex* getVertex(qint16 id) {return vertices[id];}
};

#endif // TRIANGLE_H
