#ifndef VECTOR3_H
#define VECTOR3_H
#include <QObject>


class Vector3 : public QObject
{
    Q_OBJECT
public:
    Vector3();
    Vector3(float *x, float *y, float *z);
    float* x;
    float* y;
    float* z;
    bool init;

    Q_INVOKABLE void setVector(float x, float y, float z) {
        *this->x = x;
        *this->y = y;
        *this->y = y;
    }

    Q_INVOKABLE QString getVectorList() {
        return QString::number(*this->x) + ", " + QString::number(*this->y) + ", " + QString::number(*this->z);
    }
};

#endif // VECTOR3_H
