#include "mesh.h"
#include "sub_mesh.h"


Mesh::Mesh(QByteArray data)
{
    this->data = data;
    submeshes = QList<SubMesh*>();
}
Mesh::Mesh() {
    submeshes = QList<SubMesh*>();
}
void Mesh::addSubMesh(SubMesh *s) {
    submeshes.append(s);
}
