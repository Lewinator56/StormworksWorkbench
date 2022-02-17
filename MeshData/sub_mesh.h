#ifndef SUBMESH_H
#define SUBMESH_H
#include <QtGlobal>
#include "triangle.h"
#include <QList>


class SubMesh
{
public:
    QList<Triangle> triangles;
    quint8 *shaderID;
    Vector3 *cullingMax;
    Vector3 *cullingMin;
    VertexColor *color;

    SubMesh();
    void addTriangle(const Triangle &t);
    void setCullingMin(float *x, float *y, float *z);
    void setCullingMax(float *x, float *y, float *z);
    void setShader(quint8 *shaderID);
    void setColor(VertexColor *col);
};

#endif // SUBMESH_H
