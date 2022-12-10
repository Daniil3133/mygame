#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vec2.h"

class Transform
{
    vec2 m_pos;
public:
    Transform(){}
    void setPos(const vec2&);
    vec2 pos()const;
    vec2 pos();
};

#endif // TRANSFORM_H