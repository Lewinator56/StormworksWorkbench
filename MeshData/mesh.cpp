#include "mesh.h"


Mesh::Mesh()
{
    submeshes = QList<SubMesh>();
}
void Mesh::addSubMesh(const SubMesh &s) {
    submeshes.append(s);
}
