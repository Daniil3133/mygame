#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <string>

class IComponent
{
};


template<typename T>
struct TypeParseTraits;

//если не сущ-т компонент то ошибка компил<ции
#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
    { static const char* name; } ; const char* TypeParseTraits<X>::name = #X


template<typename T>
class Component:public IComponent, public T
{
    using TypeComponent = T;
    
public:
    static constexpr std::string name(){ return TypeParseTraits<T>::name;}
    TypeComponent* component();
    TypeComponent* component()const;
};


REGISTER_PARSE_TYPE(Transform);
REGISTER_PARSE_TYPE(PhysEngine::Object);

#endif // ICOMPONENT_H