#ifndef MESHPARSER_H
#define MESHPARSER_H
#include "mesh.h"
#include <QList>
#include <QtGlobal>



class MeshParser
{
public:
    MeshParser();
    static Mesh parse(quint8 data[]);
};

#endif // MESHPARSER_H
