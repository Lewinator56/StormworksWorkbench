#ifndef MESHPARSER_H
#define MESHPARSER_H
#include "mesh.h"
#include <QList>
#include <QtGlobal>



class MeshParser
{
public:
    MeshParser();
    static Mesh* parseMesh(QByteArray &data);
    static Mesh* loadMesh(QString path);
    static Mesh* loadObj(QString path);
    //static Mesh* parseObj(QVector<QString> &data);

    QList<SubMesh*> submeshes;
};

#endif // MESHPARSER_H
