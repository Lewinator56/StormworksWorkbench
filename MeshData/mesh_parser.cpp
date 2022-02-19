#include "mesh_parser.h"
#include <stdlib.h>
#include <iostream>
#include "vertex.h"
#include <QVector>
#include <QFile>
#include <QTextStream>


MeshParser::MeshParser()
{

}
Mesh* MeshParser::loadMesh(QString path) {
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray da = file.readAll();
    file.close();
    return MeshParser::parseMesh(da);

}

/**
 * @brief MeshParser::parse
 * @param data Reference to the array of data to parse
 * @return the structured mesh data referencing the raw array
 *
 * This iterates through the raw mesh data supplied and creates a reference-type data structure to
 * that can be easily iterated through to find and edit mesh properties. The struture uses pointers
 * to ensure that any raw data that is accesses is always reading from the mesh data array rather than
 * any copies that could be created. This means that when writing the data back out to a file, the data in
 * Mesh.data can simply be dumped and will contain any changes made by accessing positions, colors and normals in
 * the data structure.
 *
 * This was a bloody pain to write.
 **/
Mesh* MeshParser::parseMesh(QByteArray &data) {
    Mesh *m = new Mesh(data);
    char *pData = m->data.data();

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
        Vector3 *p = new Vector3((float*)(vptr), (float*)(vptr+4), (float*)(vptr+8));
        VertexColor *c = new VertexColor((quint8*)(vptr+12), (quint8*)(vptr+13), (quint8*)(vptr+14), (quint8*)(vptr+15));
        Vector3 *n = new Vector3((float*)(vptr+16), (float*)(vptr+20), (float*)(vptr+24));

        Vertex *v = new Vertex(p, c, n, i);
        vertices.append(v);
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
        Triangle *t = new Triangle(vertices[p1], vertices[p2], vertices[p3]);
        triangles.append(t);
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
        SubMesh *s = new SubMesh();
        submeshes.append(s);
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
        //Vector3 cullingMin = Vector3(&cmnx, &cmny, &cmnz);
        //Vector3 cullingMax = Vector3(&cmxx, &cmxy, &cmxz);

        quint32 smts = sms/3;
        quint32 smtc = sme/3;
        for (quint32 j = smts; j < smts+smtc; j++) {
            s->triangles.append(triangles[j]);
        }
        s->setCullingMax(&cmxx, &cmxy, &cmxz);
        s->setCullingMin(&cmnx, &cmny, &cmnz);
        s->setShader(&sid);

        fi += 2;
        quint16& idLength = *(quint16*)(pData+fi);
        fi += idLength;
        fi+=14;
        //std::cout << *cullingMin.x << std::endl;
        m->addSubMesh(s);


    }
    return m;
}

Mesh* MeshParser::loadObj(QString path) {
    QVector<QString> fs = QVector<QString>();
    QFile f(path);
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream in(&f);
        while(!in.atEnd()) {
            fs.append(in.readLine());
        }
        f.close();
    }
    return new Mesh();
    //return MeshParser::parseObj(fs);
}



