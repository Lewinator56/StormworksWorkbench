#include "vector3.h"

Vector3::Vector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    init = false;
}

Vector3::Vector3(const float &x, const float &y, const float &z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    init = true;
}
