#ifndef SUBMESH_H
#define SUBMESH_H
#include <QtGlobal>
#include "triangle.h"
#include <QList>
#include <QObject>
#include <QVariantList>


class SubMesh : public QObject
{
    Q_OBJECT
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

    Q_INVOKABLE Triangle* getTriangle(int idx) {return triangles[idx];}
    Q_INVOKABLE quint16 & getShaderID () {return *shaderID;}
    Q_INVOKABLE int getTriangleCount() {return triangles.length();}


};

#endif // SUBMESH_H
