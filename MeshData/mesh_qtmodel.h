#ifndef MESHQTMODEL_H
#define MESHQTMODEL_H
#include <QtQuick3D/QQuick3D>
#include <QtQuick3D/QQuick3DGeometry>
#include "stormworks_mesh.h"


class MeshQtModel : public QQuick3DGeometry
{
    Q_OBJECT
    QML_NAMED_ELEMENT(MeshQtModel)
public:
    MeshQtModel();
    Q_INVOKABLE void setMesh(StormworksMesh* swmesh) {this->swmesh = swmesh;}
    Q_INVOKABLE void updateData(bool isMesh);
    Q_INVOKABLE void addSwMesh(QString path);
    StormworksMesh* swmesh;


};


#endif // MESHQTMODEL_H
