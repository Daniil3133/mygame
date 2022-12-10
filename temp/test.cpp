#include <vector>
#include <sstream>
#include <stdio.h>

template<typename T, std::size_t n>
struct vec
{
    
    using value = vec<T,n>;
    constexpr vec(std::initializer_list<T> list)
    {
//        std::initializer_list<T
        std::size_t i = 0;
        for(auto it=list.begin();it != list.end();it++,i++)
            _vec[i] = *it;
    }
    vec(){}
    T operator [] (const std::size_t& x)
    {
        return _vec[x];
    }
    
    union{
    T _vec[n];
    };
};

template<typename LHS, typename RHS>
struct vecsum;

template<typename LHS, typename RHS>
vecsum<LHS,RHS> operator+(const LHS& lhs, const RHS& rhs)
{
    return vecsum<LHS,RHS>(lhs,rhs);
}


template<typename T, std::size_t n>
struct Vec;

template<typename LHS, typename RHS>
struct vecsum
{
    using value_type = typename LHS::value_type;
    
    vecsum(const LHS& lhs, const RHS& rhs):lhs(lhs),rhs(rhs){}
    value_type operator()(int k)
    {
        return lhs(k) + rhs(k);
    }
    const value_type operator()(int k)const
    {
        return lhs(k) + rhs(k);
    }
    const LHS& lhs;
    const RHS& rhs;
};


template<typename T>
struct cw
{
    union{
    T w;};
};

template<typename T>
struct Vec<T,3>
{
    using value_type = T;
    T x,y,z;
    Vec(){static int i=0;i++;
        printf("{%i}\n",i);}
    Vec(const std::initializer_list<T>& list)
    :x(*list.begin()),y(*(list.begin()+1)),z(*(list.begin()+2))
    {}
    T& operator [] (std::size_t j)
    {
        return j == 0? x : j == 1? y : z;
    }
    T& operator () (std::size_t j)
    {
        return j == 0? x : j == 1? y : z;
    }
    const T& operator () (std::size_t j)const
    {
        return j == 0? x : j == 1? y : z;
    }
    template<typename Expr>
    Vec& operator = (const Expr& expr)
    {
        for(int i = 0; i < 3; i++) operator[](i) = expr(i);
        return *this;
    }
};

/*template <typename T,typename T1, std::size_t n = 3>
vec<T,n> operator+(const vec<T,n>& lhs, const vec<T,n>& rhs)
{
    vec<T,n> result;
    for(size_t i = 0; i < n; ++i)
    {
        result[i] = lhs(i) + rhs(i);
    }
    return result;
}*/

template<typename T>
struct Vec<T,4>
{
    T x,y,z,w;
};


template <template <typename T1,std::size_t n1>class T1>
struct print{
    print()=default;
template<typename T, std::size_t n>
    print( T1<T,n> v){*this(v);}
template<typename T, std::size_t n>
    void operator () ( T1<T,n> v)
    {
        static std::size_t ww=0;
        ww++;
        printf("{%i} ",ww);
        std::stringstream ss;
        for(std::size_t i = 0; i < n; i++)
        {
            ss << v[i] << " ";
        }
        printf("  %s\n",ss.str().c_str());
    }
};




int main()
{
    /*vec<int,3> v({1,2,3});
    vec<int,3> f;
    print<vec>()(v);
    //print(vec<int,4>({2,3,4,5}));
    */
    
    Vec<int,3> w({1,2,3}),r({3,2,1}),t({10,10,10});
    //w[0]=1;
    using v3 = vec<int,3>;
    w = r + t + t + w;
    
    
    print<Vec>()(w);
    //printf("%i",w);
    
    
}