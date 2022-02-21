#ifndef VERTEX_H
#define VERTEX_H
#include <QtGlobal>
#include "Common/vector3.h"
#include "Common/vertex_color.h"
#include <QObject>


class Vertex : public QObject
{
    Q_OBJECT
public:
    Vector3 *position;
    VertexColor *color;
    Vector3 *normal;
    int index;

    Vertex();
    Vertex(Vector3 *position,VertexColor *color,Vector3 *normal, const int index);
    Q_INVOKABLE Vector3* getPosition() {return position;}
    Q_INVOKABLE Vector3* getNormal() {return normal;}
    Q_INVOKABLE VertexColor* getColor() {return color;}



};

#endif // VERTEX_H
