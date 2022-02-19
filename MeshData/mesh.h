#ifndef MESH_H
#define MESH_H
#include "sub_mesh.h"
#include <QList>


class Mesh
{
public:
    QList<SubMesh*> submeshes;
    QByteArray data;

    Mesh(QByteArray data);
    Mesh();
    void addSubMesh(SubMesh *s);

};

#endif // MESH_H
