#ifndef STORMWORKSMESH_H
#define STORMWORKSMESH_H

#include <QObject>
#include "mesh.h"
#include "mesh_parser.h"
#include "obj_parser.h"

class StormworksMesh : public QObject
{
    Q_OBJECT
public:
    Mesh* mesh;
    QString location;

    explicit StormworksMesh(QObject *parent = nullptr);
    Q_INVOKABLE void parseMesh();
    Q_INVOKABLE void parseObj(QString source);
    Q_INVOKABLE void setLocation(QString path);
    Q_INVOKABLE Mesh* getMesh();

signals:

};

#endif // STORMWORKSMESH_H
