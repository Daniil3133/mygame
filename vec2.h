#ifndef VEC2_H
#define VEC2_H

#include <SFML/System/Vector2.hpp>
#include <cmath>
//--------------VEC2------------
struct vec2
{
	float x,y;
	sf::Vector2f vecsf()const{return sf::Vector2f(x,y);}
	vec2()=default;
	template<typename T>
	vec2(const sf::Vector2<T>& v):x(v.x),y(v.y){}
	vec2(float _x, float _y):x(_x),y(_y){}
	inline vec2 operator+=(vec2 v)
	{
		this->x += v.x;
		this->y += v.y;
		return *this;
	}
	inline vec2 operator-=(vec2 v)
	{
		this->x -= v.x;
		this->y -= v.y;
		return *this;
	}
	inline vec2 operator*=(float c)
	{
		this->x *= c;
		this->y *= c;
		return *this;
	}
	inline vec2 operator/=(float c)
	{
		this->x /= c;
		this->y /= c;
		return *this;
	}
	inline float magnitude()
	{
		float d = sqrt(x*x+y*y);
		if(d==0) d =1.f;
		return d;
	}
	inline float distance(vec2 v)
	{
		return sqrt((x-v.x)*(x-v.x) + (y-v.y)*(y-v.y));
	}
	inline float normSquared()
	{
		return (x*x + y*y);
	}
	inline vec2 normalized()
	{
		float d = magnitude();
		return vec2(x/d,y/d);
	}
	inline float dotProduct(vec2 v)
	{
		return (x*v.x + y*v.y);
	}
	inline float dot(vec2 n)
	{
		return (dotProduct(n) / n.magnitude());
	}
};
inline vec2 operator*(vec2 v, int c)
{
	return vec2(v.x*c,v.y*c);
}
inline vec2 operator*(int c, vec2 v)
{
	return operator*(v,c);
}
inline vec2 operator*(vec2 v, float c)
{
	return vec2(v.x*c,v.y*c);
}
inline vec2 operator*(float c, vec2 v)
{
	return operator*(v,c);
}
inline vec2 operator/(vec2 v, float c)
{
	return vec2(v.x/c,v.y/c);
}
inline vec2 operator-(const vec2& right)
{
	return vec2(-right.x, -right.y);
}

inline vec2 operator-(vec2 left, vec2 right)
{
	return vec2(left.x - right.x, left.y - right.y);
}
inline vec2 operator+(const vec2& left, const vec2& right)
{
	return vec2(left.x + right.x, left.y + right.y);
}
//--------------VEC2-END------------

#endif // VEC2_H