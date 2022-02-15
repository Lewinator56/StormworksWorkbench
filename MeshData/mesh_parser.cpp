#include "mesh_parser.h"


MeshParser::MeshParser()
{

}
Mesh MeshParser::parse(quint8 *data) {
    Mesh m = Mesh();

    // set the file iterator
    int fi = 0;

    // 6D 65 73 68 07 00 01 00
    // Vertex count
    quint16 vc = data[9] << 8 | data[8];
    fi += 14;

    QList<Vertex> vertices = QList<Vertex>();
    for (int i = 0; i < vc; i++) {
        float px = data[fi];
        float py = data[fi + 4];

    }
    return m;
}
