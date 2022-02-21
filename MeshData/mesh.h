#ifndef MESH_H
#define MESH_H
#include "sub_mesh.h"
#include <QList>
#include <QObject>


class Mesh:public QObject
{
    Q_OBJECT


public:
    QList<SubMesh*> submeshes;
    QByteArray data;

    Q_INVOKABLE Mesh(QByteArray data);
    Q_INVOKABLE Mesh();
    Q_INVOKABLE QByteArray & getData() {return data;}
    Q_INVOKABLE SubMesh* getSubmesh(int idx) {return submeshes[idx];}
    Q_INVOKABLE int getSubmeshCount() {return submeshes.length();}

    void addSubMesh(SubMesh *s);


};

#endif // MESH_H
