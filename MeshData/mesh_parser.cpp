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

    QVector<Vertex*> vertices = QVector<Vertex*>();
    // this probably isnt memory safe, but who cares
    for (int i = 0; i < vc; i++, fi+=28) {
        char* vptr = pData+fi;
        Vector3 p = Vector3((float*)(vptr), (float*)(vptr+4), (float*)(vptr+8));
        VertexColor c = VertexColor((quint8*)(vptr+12), (quint8*)(vptr+13), (quint8*)(vptr+14), (quint8*)(vptr+15));
        Vector3 n = Vector3((float*)(vptr+16), (float*)(vptr+20), (float*)(vptr+24));
        //std::cout << *n.x << std::endl;
        //*n.x = 23.0;
        //std::cout << *(float*)(vptr+16) << std::endl ;


    }
    return m;
}
