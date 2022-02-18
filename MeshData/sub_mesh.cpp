#include "sub_mesh.h"

SubMesh::SubMesh()
{
    triangles = QList<Triangle*>();
}
void SubMesh::addTriangle(Triangle *t) {
    triangles.append(t);
}

void SubMesh::setCullingMin(float *x, float *y, float *z) {
    if (!cullingMin == NULL)
    {
        cullingMin = new Vector3(x, y, z);
    }
    else
    {
        *cullingMin->x = *x < *cullingMin->x ? *x : *cullingMin->x;
        *cullingMin->y = *y < *cullingMin->y ? *y : *cullingMin->y;
        *cullingMin->z = *z < *cullingMin->z ? *z : *cullingMin->z;
    }
}

void SubMesh::setCullingMax(float *x, float *y, float *z) {
    if (!cullingMax == NULL)
    {
        cullingMax = new Vector3(x, y, z);
    }
    else
    {
        *cullingMax->x = *x > *cullingMax->x ? *x : *cullingMax->x;
        *cullingMax->y = *y > *cullingMax->y ? *y : *cullingMax->y;
        *cullingMax->z = *z > *cullingMax->z ? *z : *cullingMax->z;
    }
}

void SubMesh::setShader(quint16 *shaderID) {
    this->shaderID = shaderID;
}

void SubMesh::setColor(VertexColor *col) {
    this->color = col;
}
