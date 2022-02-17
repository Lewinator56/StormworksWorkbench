#ifndef SUBMESH_H
#define SUBMESH_H
#include <QtGlobal>
#include "triangle.h"
#include <QList>


class SubMesh
{
public:
    QList<Triangle*> triangles;
    quint16 *shaderID;
    Vector3 *cullingMax;
    Vector3 *cullingMin;
    VertexColor *color;

    SubMesh();
    void addTriangle(Triangle *t);
    void setCullingMin(float *x, float *y, float *z);
    void setCullingMax(float *x, float *y, float *z);
    void setShader(quint16 *shaderID);
    void setColor(VertexColor *col);
};

#endif // SUBMESH_H
