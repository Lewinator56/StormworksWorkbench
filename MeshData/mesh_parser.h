#ifndef MESHPARSER_H
#define MESHPARSER_H
#include "mesh.h"
#include <QList>
#include <QtGlobal>



class MeshParser
{
public:
    MeshParser();
    static Mesh parse(QByteArray &data);
    static void loadFile(QString path);
};

#endif // MESHPARSER_H
