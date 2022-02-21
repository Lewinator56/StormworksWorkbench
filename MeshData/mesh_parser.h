#ifndef MESHPARSER_H
#define MESHPARSER_H
#include "mesh.h"
#include <QList>
#include <QtGlobal>
#include <QObject>




class MeshParser:public QObject
{
    Q_OBJECT

public:
    MeshParser();
    Q_INVOKABLE static Mesh* parseMesh(QByteArray &data);
    Q_INVOKABLE static Mesh* loadMesh(QString path);
    Q_INVOKABLE static Mesh* loadObj(QString path);
    //static Mesh* parseObj(QVector<QString> &data);

    QList<SubMesh*> submeshes;
};

#endif // MESHPARSER_H
