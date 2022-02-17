#include "mesh.h"
#include "sub_mesh.h"


Mesh::Mesh()
{
    submeshes = QList<SubMesh*>();
}
void Mesh::addSubMesh(SubMesh *s) {
    submeshes.append(s);
}
