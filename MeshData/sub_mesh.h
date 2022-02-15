#ifndef SUBMESH_H
#define SUBMESH_H
#include <QtGlobal>
#include "triangle.h"
#include <QList>


class SubMesh
{
public:
    QList<Triangle> triangles;
    quint8 shaderID;
    Vector3 cullingMax;
    Vector3 cullingMin;
    VertexColor color;

    SubMesh();
    void addTriangle(const Triangle &t);
    void setCullingMin(const float &x, const float &y, const float &z);
    void setCullingMax(const float &x, const float &y, const float &z);
    void setShader(const quint8 &shaderID);
    void setColor(const VertexColor &col);
};

#endif // SUBMESH_H
