#ifndef VERTEX_COLOR_H
#define VERTEX_COLOR_H
#include <QtGlobal>
#include <QObject>


class VertexColor : public QObject
{
    Q_OBJECT
public:
    VertexColor();
    VertexColor(quint8 *r, quint8 *g, quint8 *b, quint8 *a);
    quint8* r;
    quint8* g;
    quint8* b;
    quint8* a;
    bool init;

    Q_INVOKABLE void setColor(quint8 r, quint8 g, quint8 b, quint8 a) {
        *this->r = r;
        *this->g = g;
        *this->b = b;
        *this->a = a;
    }

    Q_INVOKABLE QString getColorList() {
        return QString::number(*this->r) + ", " + QString::number(*this->g) + ", " + QString::number(*this->b) + ", " + QString::number(*this->a);
    }
};

#endif // VERTEX_COLOR_H
