#ifndef MESHPARSER_H
#define MESHPARSER_H
#include "mesh.h"
#include <QList>
#include <QtGlobal>



class MeshParser
{
public:
    MeshParser();
    static Mesh* parse(QByteArray &data);
    static Mesh* loadFile(QString path);

    QList<SubMesh*> submeshes;
};

#endif // MESHPARSER_H
