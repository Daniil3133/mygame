#include "PhysEngine.h"

#include "../transform.h"

#include "../math.h"

namespace PhysEngine
{
    void Object::update(float dt)
    {
       // auto transform = dynamic_cast<Transform*>(this);
        
    }
    
    
    PhysEngine::PhysEngine()
    {
        m_updateTime = 10;
    }
    bool PhysEngine::addObj(Object* obj)
    {
        if(std::find(m_objs.begin(),m_objs.end(),obj) != m_objs.end()) return false;
       
        m_objs.push_back(obj);
        
        return true;
    }
    void PhysEngine::update()
    {
        for(auto& obj:m_objs)
        {
            obj->update(m_updateTime);   
        }
    }
    void PhysEngine::setUpdateTime(float dt)
    {
        m_updateTime = dt;
    }
}