#include "sub_mesh.h"

SubMesh::SubMesh()
{
    triangles = QList<Triangle>();
}
void SubMesh::addTriangle(const Triangle &t) {
    triangles.append(t);
}

void SubMesh::setCullingMin(const float &x, const float &y, const float &z) {
    if (!cullingMin.init)
    {
        cullingMin = Vector3(x, y, z);
    }
    else
    {
        cullingMin.x = x < cullingMin.x ? x : cullingMin.x;
        cullingMin.y = y < cullingMin.y ? y : cullingMin.y;
        cullingMin.z = z < cullingMin.z ? z : cullingMin.z;
    }
}

void SubMesh::setCullingMax(const float &x, const float &y, const float &z) {
    if (!cullingMax.init)
    {
        cullingMax = Vector3(x, y, z);
    }
    else
    {
        cullingMax.x = x > cullingMax.x ? x : cullingMax.x;
        cullingMax.y = y > cullingMax.y ? y : cullingMax.y;
        cullingMax.z = z > cullingMax.z ? z : cullingMax.z;
    }
}

void SubMesh::setShader(const quint8 &shaderID) {
    this->shaderID = shaderID;
}

void SubMesh::setColor(const VertexColor &col) {
    this->color = col;
}
