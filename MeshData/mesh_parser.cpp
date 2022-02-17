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
    // pointers .....
    for (int i = 0; i < vc; i++) {
        char* vptr = pData+fi;
        Vector3 p = Vector3((float*)(vptr), (float*)(vptr+4), (float*)(vptr+8));
        VertexColor c = VertexColor((quint8*)(vptr+12), (quint8*)(vptr+13), (quint8*)(vptr+14), (quint8*)(vptr+15));
        Vector3 n = Vector3((float*)(vptr+16), (float*)(vptr+20), (float*)(vptr+24));

        Vertex v = Vertex(&p, &c, &n, i);
        vertices.append(&v);
        fi+=28;

        //std::cout << *v.normal->x << std::endl;
        //*v.normal->x = 23.0;
        //std::cout << *(float*)(vptr+16) << std::endl ;

    }
    for (int i = 0; i < 32; i ++) {
        std::cout << vertices[i]->index << std::endl;
    }

    // edge buffer
    quint32& eb = *(quint32*)(pData + fi);
    std::cout << eb << std::endl;

    quint32 tc = (eb *2/6);
    fi +=4;

    //vertex indexes for each triangle
    QVector<Triangle*> triangles = QVector<Triangle*>();
    for (quint32 i = 0; i < tc; i++) {
        char* tptr = pData + fi;
        quint16& p1 = *(quint16*)(tptr);
        quint16& p2 = *(quint16*)(tptr+2);
        quint16& p3 = *(quint16*)(tptr+4);
        Triangle t = Triangle(vertices[p1], vertices[p2], vertices[p3]);
        triangles.append(&t);
        //std::cout << *t.vertices[0]->position->x << std::endl;
        //*vertices[0]->position->x = 23.0;
        //std::cout << *t.vertices[0]->position->x << std::endl;
        fi+=6;
    }

    //sub meshes
    quint16& smc = *(quint16*)(pData+fi);
    fi += 2;
    QList<SubMesh*> submeshes = QList<SubMesh*>();
    for (quint16 i = 0; i < smc; i++) {
        SubMesh s = SubMesh();
        submeshes.append(&s);
        quint32& sms = *(quint32*)(pData + fi);
        fi += 4;
        quint32& sme = *(quint32*)(pData + fi);
        fi += 6; //skip 00 00 padding
        quint16& sid = *(quint16*)(pData + fi);
        fi += 2;

        float& cmnx = *(float*)(pData+fi);
        //std::cout << cmnx << std::endl;
        //cmnx = 24.0;
        //std::cout << *(float*)(pData+fi) << std::endl;
        fi+=4;
        float& cmny = *(float*)(pData+fi);
        fi+=4;
        float& cmnz = *(float*)(pData+fi);
        fi+=4;
        float& cmxx = *(float*)(pData+fi);
        fi+=4;
        float& cmxy = *(float*)(pData+fi);
        fi+=4;
        float& cmxz = *(float*)(pData+fi);
        fi+=4;
        Vector3 cullingMin = Vector3(&cmnx, &cmny, &cmnz);
        Vector3 cullingMax = Vector3(&cmxx, &cmxy, &cmxz);

        quint32 smts = sms/3;
        quint32 smtc = sme/3;
        for (quint32 j = smts; j < smts+smtc; j++) {
            s.triangles.append(triangles[j]);
        }
        s.setCullingMax(&cmxx, &cmxy, &cmxz);
        s.setCullingMin(&cmnx, &cmny, &cmnz);
        s.setShader(&sid);

        fi += 2;
        quint16& idLength = *(quint16*)(pData+fi);
        fi += idLength;
        fi+=14;
        //std::cout << *cullingMin.x << std::endl;


    }
    return m;
}
