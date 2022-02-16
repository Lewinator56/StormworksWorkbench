#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MeshData/mesh_parser.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/StormworksWorkbench/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    MeshParser::loadFile(QString("C:/Users/lewis/Desktop/m_component_mwindow_edge.mesh"));

    return app.exec();
}
