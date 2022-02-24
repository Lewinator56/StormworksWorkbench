#include "mesh_qtmodel.h"

MeshQtModel::MeshQtModel()
{
    //StormworksMesh *sm = new StormworksMesh();
    //sm->setLocation("D:\\Program Files\\Steam\\steamapps\\common\\Stormworks\\rom\\meshes\\island_36_dock.mesh");
    //sm->parseMesh();
    //swmesh = sm;

    updateData(false);
}

void MeshQtModel::addSwMesh(QString path) {
    swmesh = new StormworksMesh();
    swmesh->setLocation(path);
    swmesh->parseMesh();
    updateData(1);

}

void MeshQtModel::updateData(bool isMesh) {
    clear();
    QByteArray v;
    QByteArray n;
    QByteArray c;



    if (isMesh == true) {
        std::cout << "updating mesh" << std::endl;
        for(int i =0; i < swmesh->getMesh()->getSubmeshCount(); i++) { // loop submeshes

            for (int j = 0; j < swmesh->getMesh()->getSubmesh(i)->getTriangleCount(); j++) { // loop triangles
                for (int k = 0; k < 3; k++) { // loop positions
                    // vertices
                    float vx = *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->position->x;
                    float vy = *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->position->y;
                    float vz = *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->position->z;

                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&vx), 4);
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&vy), 4);
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&vz), 4);

                    float nx = *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->normal->x;
                    float ny = *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->normal->y;
                    float nz = *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->normal->z;
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&nx), 4);
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&ny), 4);
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&nz), 4);

                    QByteArray ca = QByteArray();

                    float r = 2.0 / 255.0 * *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->color->r ;
                    float g = 2.0 / 255.0 * *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->color->g;
                    float b = 2.0 / 255.0 * *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->color->b;
                    float a = 2.0 / 255.0 * *swmesh->getMesh()->getSubmesh(i)->getTriangle(j)->getVertex(k)->color->a;

                    std::cout << r << std::endl;

                    /**
                    float r = 2;
                    float g = 0.0;
                    float b = 0.0;
                    float a = 1.0;
                    **/
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&r), 4);
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&g), 4);
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&b), 4);
                    v += QByteArray::fromRawData(reinterpret_cast<const char*>(&a), 4);

                    //v += ca;


                }

            }
        }

        setVertexData(v);

        setStride(40);

        setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);

        addAttribute(QQuick3DGeometry::Attribute::PositionSemantic, 0, QQuick3DGeometry::Attribute::F32Type);
        addAttribute(QQuick3DGeometry::Attribute::NormalSemantic, 12, QQuick3DGeometry::Attribute::F32Type);
        addAttribute(QQuick3DGeometry::Attribute::ColorSemantic, 24, QQuick3DGeometry::Attribute::F32Type);
    } else {
        v.resize(3 * 3 * sizeof(float));
        float *p = reinterpret_cast<float *>(v.data());

        // a triangle, front face = counter-clockwise
        *p++ = -1.0f; *p++ = -1.0f; *p++ = 0.0f;
        *p++ = 1.0f; *p++ = -1.0f; *p++ = 0.0f;
        *p++ = 0.0f; *p++ = 1.0f; *p++ = 0.0f;

        setVertexData(v);
        setStride(3 * sizeof(float));

        setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);

        addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                     0,
                     QQuick3DGeometry::Attribute::F32Type);
    }
    update();


}
