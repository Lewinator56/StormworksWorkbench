#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MeshData/mesh_parser.h"
#include "MeshData/obj_parser.h"
#include "MeshData/stormworks_mesh.h"
#include "MeshData/mesh_qtmodel.h"
#include <QtQuick3D/QQuick3D>
#include <QtQuick3D/QQuick3DGeometry>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<StormworksMesh>("meshdata.swmesh", 1, 0, "SwMesh");
    qmlRegisterType<MeshQtModel>("meshdata.meshqtmodel", 1, 0, "MeshQtModel");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/StormworksWorkbench/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);




    //Mesh *m = MeshParser::loadMesh(QString("C:/Users/lewis/Desktop/m_component_mwindow_edge.mesh"));
    //op.parseObj("C:/Users/lewis/source/repos/swcpmc/swcpmc/out/build/x64-Debug/swcpmc/tactical_log.obj", "C:/Users/lewis/source/repos/swcpmc/swcpmc/out/build/x64-Debug/swcpmc/tactical_log.mesh");

    return app.exec();
}
