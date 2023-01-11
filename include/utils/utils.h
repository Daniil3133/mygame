#ifndef UTILS_H
#define UTILS_H


#define SINGLETON(Class)       \
public:                        \
    static Class& Instance()   \
    {                          \
        static Class obj;      \
        return obj;            \
    }


#define NONCOPYABLE(Class)            \
Class(const Class&)=delete;           \
void operator=(const Class&)=delete; 


#endif // UTILS_H