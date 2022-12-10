#ifndef AABB_H
#define AABB_H

#include "../vec2.h"

struct AABB // axis aligned bounding box
{
	vec2 min,max;
	AABB(vec2 _min, vec2 _max):min(_min),max(_max){}
	inline static bool test(const AABB& a, const AABB& b)
	{
		if(a.max.x < b.min.x || a.min.x > b.max.x) return false;
		if(a.max.y < b.min.y || a.min.y > b.max.y) return false;
		return true;
	}
};

struct BS // Bounding sphere
{
	vec2 m_pos;
	float m_r;
	BS(vec2 pos, float r):m_pos(pos),m_r(r){}
	BS()=default;
	inline static bool test(const BS& a, const BS& b)
	{
		return ((a.m_pos - b.m_pos).normSquared() < (a.m_r + b.m_r) * (a.m_r + b.m_r));
	}
};

#endif