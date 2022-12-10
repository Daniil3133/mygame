#include "transform.h"



void Transform::setPos(const vec2& p)
{
    m_pos = p;
}

vec2 Transform::pos()const
{
    return m_pos;
}

vec2 Transform::pos()
{
    return m_pos;
}