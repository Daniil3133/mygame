#ifndef PHYSENGINE_H
#define PHYSENGINE_H


#include "AABB.h"
#include <vector>

namespace PhysEngine
{
class Transform;
class Object
{
    Transform* transform;
public:
    
    virtual void update(float dt);
};

//--------------PHYSIC_ENGINE------------
class PhysEngine
{
    std::vector<Object*> m_objs;
    float m_updateTime;
public:
    PhysEngine();
    bool addObj(Object*);
	void update();
	void setUpdateTime(float);
private:
	
private:
};
//--------------PHYSIC_ENGINE-END-----------

} // namespace

#endif // PHYSENGINE_H