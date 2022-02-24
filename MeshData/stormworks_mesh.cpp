#include "stormworks_mesh.h"

StormworksMesh::StormworksMesh(QObject *parent)
    : QObject{parent}
{

}

void StormworksMesh::parseMesh() {
    this->mesh = MeshParser::loadMesh(this->location);
}

void StormworksMesh::parseObj(QString source) {
    ObjParser::parseObj(source.toStdString(), location.toStdString());
}

void StormworksMesh::setLocation(QString path) {
    this->location = path;
}

Mesh* StormworksMesh::getMesh() {
    return this->mesh;
}

