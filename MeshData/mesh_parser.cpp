#include "mesh_parser.h"
#include <stdlib.h>
#include <iostream>
#include "vertex.h"
#include <QVector>
#include <QFile>


MeshParser::MeshParser()
{

}
void MeshParser::loadFile(QString path) {
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray da = file.readAll();
    file.close();
    MeshParser::parse(da);

}
Mesh MeshParser::parse(QByteArray &data) {
    Mesh m = Mesh();
    char *pData = data.data();

    // set the file iterator
    int fi = 0;

    // 6D 65 73 68 07 00 01 00
    // Vertex count
    quint16 vc = data[9] << 8 | data[8];
    fi += 14;

    QVector<Vertex> vertices = QVector<Vertex>();
    // this probably isnt memory safe, but who cares
    for (int i = 0; i < vc; i++) {
        char* vptr = pData+fi;
        float px = *(float*)(vptr);
        float py = *(float*)(vptr+4);
        float pz = *(float*)(vptr+8);
        VertexColor c = VertexColor(*(vptr+12), *(vptr+13), *(vptr+14), *(vptr+15));
        float nx = *(float*)(vptr+16);
        float ny = *(float*)(vptr+20);
        float nz = *(float*)(vptr+24);
        std::cout << c.r << std::endl;


    }
    return m;
}
