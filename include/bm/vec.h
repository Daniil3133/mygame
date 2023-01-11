#ifndef VEC_H
#define VEC_H

#include <SFML/System/Vector2.hpp>
#include <cmath>





//--------------VEC4------------

struct vec4
{
	float x,y,z,w;
	//sf::Vector2f vecsf()const{return sf::Vector2f(x,y);}
	vec4()=default;
	vec4(float _x, float _y, float _z, float _w):x(_x),y(_y),z(_z),w(_w){}
	inline vec4 operator+=(vec4 v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w += v.w;
		return *this;
	}
	inline vec4 operator-=(vec4 v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;
		return *this;
	}
	inline vec4 operator*=(float c)
	{
		this->x *= c;
		this->y *= c;
		this->z *= c;
		this->w *= c;
		return *this;
	}
	inline vec4 operator/=(float c)
	{
		this->x /= c;
		this->y /= c;
		this->z /= c;
		this->w /= c;
		return *this;
	}
	inline float magnitude()
	{
		float d = sqrt(x * x + y * y + z * z + w * w);
		if(d == 0) return 1.f;
		return d;
	}
	inline float distance(vec4 v)
	{
		return sqrt((x-v.x)*(x-v.x) + (y-v.y)*(y-v.y) + (z-v.z)*(z-v.z) + (w-v.w)*(w-v.w));
	}
	inline float normSquared()
	{
		return (x*x + y*y + z*z + w*w);
	}
	inline vec4 normalized()
	{
		float d = magnitude();
		return vec4(x/d, y/d, z/d, w/d);
	}
	inline float dotProduct(vec4 v)
	{
		return (x*v.x + y*v.y + z*v.z + w*v.w);
	}
	inline float dot(vec4 n)
	{
		return (dotProduct(n) / n.magnitude());
	}
};
inline vec4 operator*(vec4 v, int c)
{
	return vec4(v.x*c, v.y*c, v.z*c, v.w*c);
}
inline vec4 operator*(int c, vec4 v)
{
	return operator*(v,c);
}
inline vec4 operator*(vec4 v, float c)
{
	return vec4(v.x*c, v.y*c, v.z*c, v.w*c);
}
inline vec4 operator*(float c, vec4 v)
{
	return operator*(v,c);
}
inline vec4 operator/(vec4 v, float c)
{
	return vec4(v.x/c, v.y/c, v.z/c, v.w/c);
}
inline vec4 operator-(const vec4& v)
{
	return vec4(-v.x, -v.y, -v.z, -v.w);
}

inline vec4 operator-(vec4 left, vec4 right)
{
	return vec4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}
inline vec4 operator+(const vec4& left, const vec4& right)
{
	return vec4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + left.w);
}
//--------------VEC4-END------------


//--------------VEC3------------
struct vec3
{
	float x,y,z;
	//sf::Vector2f vecsf()const{return sf::Vector2f(x,y);}
	vec3()=default;
	vec3(float _x, float _y, float _z):x(_x),y(_y),z(_z){}
	inline vec3 operator+=(vec3 v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		return *this;
	}
	inline vec3 operator-=(vec3 v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		return *this;
	}
	inline vec3 operator*=(float c)
	{
		this->x *= c;
		this->y *= c;
		this->z *= c;
		return *this;
	}
	inline vec3 operator/=(float c)
	{
		this->x /= c;
		this->y /= c;
		this->z /= c;
		return *this;
	}
	inline float magnitude()
	{
		float d = sqrt(x * x + y * y + z * z);
		if(d == 0) return 1.f;
		return d;
	}
	inline float distance(vec3 v)
	{
		return sqrt((x-v.x)*(x-v.x) + (y-v.y)*(y-v.y) + (z-v.z)*(z-v.z));
	}
	inline float normSquared()
	{
		return (x*x + y*y + z*z);
	}
	inline vec3 normalized()
	{
		float d = magnitude();
		return vec3(x/d, y/d, z/d);
	}
	inline float dotProduct(vec3 v)
	{
		return (x*v.x + y*v.y + z*v.z);
	}
	inline float dot(vec3 n)
	{
		return (dotProduct(n) / n.magnitude());
	}
};
inline vec3 operator*(vec3 v, int c)
{
	return vec3(v.x*c, v.y*c, v.z*c);
}
inline vec3 operator*(int c, vec3 v)
{
	return operator*(v,c);
}
inline vec3 operator*(vec3 v, float c)
{
	return vec3(v.x*c, v.y*c, v.z*c);
}
inline vec3 operator*(float c, vec3 v)
{
	return operator*(v,c);
}
inline vec3 operator/(vec3 v, float c)
{
	return vec3(v.x/c, v.y/c, v.z/c);
}
inline vec3 operator-(const vec3& v)
{
	return vec3(-v.x, -v.y, -v.z);
}

inline vec3 operator-(vec3 left, vec3 right)
{
	return vec3(left.x - right.x, left.y - right.y, left.z - right.z);
}
inline vec3 operator+(const vec3& left, const vec3& right)
{
	return vec3(left.x + right.x, left.y + right.y, left.z + right.z);
}


//--------------VEC3-END------------

#endif // VEC_H