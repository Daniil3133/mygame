#ifndef MATH_H
#define MATH_H





#include "vec.h"

//=======================MAT4X4=======================
struct mat4x4
{
    union{
        float m[4][4];
        float r[16];
        float a11,a12,a13,a14,
              a21,a22,a23,a24,
              a31,a32,a33,a34,
              a41,a42,a43,a44;
    };
    mat4x4(float _m[4][4]){
             a11=_m[0][0],a12=_m[0][1],a13=_m[0][2],a14=_m[0][3],
             a21=_m[1][0],a22=_m[1][1],a23=_m[1][2],a24=_m[1][3],
             a31=_m[2][0],a32=_m[2][1],a33=_m[2][2],a34=_m[2][3],
             a41=_m[3][0],a42=_m[3][1],a43=_m[3][2],a44=_m[3][3];
    }
    mat4x4(float _r[16]){
             a11=_r[0] ,a12=_r[1] ,a13=_r[2] ,a14=_r[3],
             a21=_r[4] ,a22=_r[5] ,a23=_r[6] ,a24=_r[7],
             a31=_r[8] ,a32=_r[9] ,a33=_r[10],a34=_r[11],
             a41=_r[12],a42=_r[13],a43=_r[14],a44=_r[15];
    }
    mat4x4(float _a11, float _a12, float _a13, float _a14,
           float _a21, float _a22, float _a23, float _a24,
           float _a31, float _a32, float _a33, float _a34,
           float _a41, float _a42, float _a43, float _a44){
             r[0] =_a11,r[1] =_a12,r[2] =_a13,r[3] =_a14,
             r[4] =_a21,r[5] =_a22,r[6] =_a23,r[7] =_a24,
             r[8] =_a31,r[9] =_a32,r[10]=_a33,r[11]=_a34,
             r[12]=_a41,r[13]=_a42,r[14]=_a43,r[15]=_a44;
    }
    mat4x4(const mat4x4& x){
             a11=x.r[0] ,a12=x.r[1] ,a13=x.r[2] ,a14=x.r[3],
             a21=x.r[4] ,a22=x.r[5] ,a23=x.r[6] ,a24=x.r[7],
             a31=x.r[8] ,a32=x.r[9] ,a33=x.r[10],a34=x.r[11],
             a41=x.r[12],a42=x.r[13],a43=x.r[14],a44=x.r[15];
    }
    static const mat4x4 Indentity;
};




const mat4x4 mat4x4::Indentity = mat4x4(1.f, 0.f, 0.f, 0.f,
                                        0.f, 1.f, 0.f, 0.f,
                                        0.f, 0.f, 1.f, 0.f,
                                        0.f, 0.f, 0.f, 1.f);
                            

mat4x4 operator + (const mat4x4& x, const mat4x4& y)
{
    return mat4x4
       (x.a11 + y.a11, x.a12 + y.a12, x.a13 + y.a13, x.a14 + y.a14,
        x.a21 + y.a21, x.a22 + y.a22, x.a23 + y.a23, x.a24 + y.a24,
        x.a31 + y.a31, x.a32 + y.a32, x.a33 + y.a33, x.a34 + y.a34,
        x.a41 + y.a41, x.a42 + y.a42, x.a43 + y.a43, x.a44 + y.a44);
}

mat4x4 operator - (const mat4x4& x, const mat4x4& y)
{
    return mat4x4
       (x.a11 - y.a11, x.a12 - y.a12, x.a13 - y.a13, x.a14 - y.a14,
        x.a21 - y.a21, x.a22 - y.a22, x.a23 - y.a23, x.a24 - y.a24,
        x.a31 - y.a31, x.a32 - y.a32, x.a33 - y.a33, x.a34 - y.a34,
        x.a41 - y.a41, x.a42 - y.a42, x.a43 - y.a43, x.a44 - y.a44);
}

mat4x4 operator - (const mat4x4& x)
{
    return mat4x4
       (-x.a11, -x.a12, -x.a13, -x.a14,
        -x.a21, -x.a22, -x.a23, -x.a24,
        -x.a31, -x.a32, -x.a33, -x.a34,
        -x.a41, -x.a42, -x.a43, -x.a44);
}

mat4x4 operator * (const mat4x4& x, const mat4x4& y)
{
    return mat4x4
       (x.a11 * y.a11 + x.a12 * y.a21 + x.a13 * y.a31 + x.a14 * y.a41,
        x.a11 * y.a12 + x.a12 * y.a22 + x.a13 * y.a32 + x.a14 * y.a42,
        x.a11 * y.a13 + x.a12 * y.a23 + x.a13 * y.a33 + x.a14 * y.a43,
        x.a11 * y.a14 + x.a12 * y.a24 + x.a13 * y.a34 + x.a14 * y.a44,
        
        x.a21 * y.a11 + x.a22 * y.a21 + x.a23 * y.a31 + x.a24 * y.a41,
        x.a21 * y.a12 + x.a22 * y.a22 + x.a23 * y.a32 + x.a24 * y.a42,
        x.a21 * y.a13 + x.a22 * y.a23 + x.a23 * y.a33 + x.a24 * y.a43,
        x.a21 * y.a14 + x.a22 * y.a24 + x.a23 * y.a34 + x.a24 * y.a44,
        
        x.a31 * y.a11 + x.a32 * y.a21 + x.a33 * y.a31 + x.a34 * y.a41,
        x.a31 * y.a12 + x.a32 * y.a22 + x.a33 * y.a32 + x.a34 * y.a42,
        x.a31 * y.a13 + x.a32 * y.a23 + x.a33 * y.a33 + x.a34 * y.a43,
        x.a31 * y.a14 + x.a32 * y.a24 + x.a33 * y.a34 + x.a34 * y.a44,
        
        x.a41 * y.a11 + x.a42 * y.a21 + x.a43 * y.a31 + x.a44 * y.a41,
        x.a41 * y.a12 + x.a42 * y.a22 + x.a43 * y.a32 + x.a44 * y.a42,
        x.a41 * y.a13 + x.a42 * y.a23 + x.a43 * y.a33 + x.a44 * y.a43,
        x.a41 * y.a14 + x.a42 * y.a24 + x.a43 * y.a34 + x.a44 * y.a44);
}

mat4x4 operator * (const mat4x4& x, float c)
{
    return mat4x4
       (x.a11 * c, x.a12 * c, x.a13 * c, x.a14 * c,
        x.a21 * c, x.a22 * c, x.a23 * c, x.a24 * c,
        x.a31 * c, x.a32 * c, x.a33 * c, x.a34 * c,
        x.a41 * c, x.a42 * c, x.a43 * c, x.a44 * c);
}

vec4 operator * (const mat4x4& x, const vec4& v)
{
    return vec4
       (x.a11 * v.x + x.a12 * v.y + x.a13 * v.z + x.a14 * v.w,
        x.a21 * v.x + x.a22 * v.y + x.a23 * v.z + x.a24 * v.w,
        x.a31 * v.x + x.a32 * v.y + x.a33 * v.z + x.a34 * v.w,
        x.a41 * v.x + x.a42 * v.y + x.a43 * v.z + x.a44 * v.w);
}


//=======================MAT3X3=======================
struct mat3x3
{
    union{
        float m[3][3];
        float r[9];
        float a11,a12,a13,
              a21,a22,a23,
              a31,a32,a33;
    };
    mat3x3(float _m[3][3]){
             a11=_m[1][1],a12=_m[1][2],a13=_m[1][3],
             a21=_m[2][1],a22=_m[2][2],a23=_m[2][3],
             a31=_m[3][1],a32=_m[3][2],a33=_m[3][3];
    }
    mat3x3(float _r[8]){
             a11=_r[0] ,a12=_r[1] ,a13=_r[2],
             a21=_r[3] ,a22=_r[4] ,a23=_r[5],
             a31=_r[6] ,a32=_r[7] ,a33=_r[8];
    }
    mat3x3(float _a11, float _a12, float _a13,
           float _a21, float _a22, float _a23,
           float _a31, float _a32, float _a33){
             r[0] =_a11,r[1] =_a12,r[2] =_a13,
             r[3] =_a21,r[4] =_a22,r[5] =_a23,
             r[6] =_a31,r[7] =_a32,r[8] =_a33;
    }
    mat3x3(const mat3x3& x){
             a11=x.r[0] ,a12=x.r[1] ,a13=x.r[2],
             a21=x.r[4] ,a22=x.r[5] ,a23=x.r[6],
             a31=x.r[8] ,a32=x.r[9] ,a33=x.r[10];
    }
    static const mat3x3 Indentity;
};




const mat3x3 mat3x3::Indentity = mat3x3(1.f, 0.f, 0.f,
                                        0.f, 1.f, 0.f,
                                        0.f, 0.f, 1.f);
                            

mat3x3 operator + (const mat3x3& x, const mat3x3& y)
{
    return mat3x3
       (x.a11 + y.a11, x.a12 + y.a12, x.a13 + y.a13,
        x.a21 + y.a21, x.a22 + y.a22, x.a23 + y.a23,
        x.a31 + y.a31, x.a32 + y.a32, x.a33 + y.a33);
}

mat3x3 operator - (const mat3x3& x, const mat3x3& y)
{
    return mat3x3
       (x.a11 - y.a11, x.a12 - y.a12, x.a13 - y.a13,
        x.a21 - y.a21, x.a22 - y.a22, x.a23 - y.a23,
        x.a31 - y.a31, x.a32 - y.a32, x.a33 - y.a33);
}

mat3x3 operator - (const mat3x3& x)
{
    return mat3x3
       (-x.a11, -x.a12, -x.a13,
        -x.a21, -x.a22, -x.a23,
        -x.a31, -x.a32, -x.a33);
}

mat3x3 operator * (const mat3x3& x, const mat3x3& y)
{
    return mat3x3
       (x.a11 * y.a11 + x.a12 * y.a21 + x.a13 * y.a31,
        x.a11 * y.a12 + x.a12 * y.a22 + x.a13 * y.a32,
        x.a11 * y.a13 + x.a12 * y.a23 + x.a13 * y.a33,
        
        x.a21 * y.a11 + x.a22 * y.a21 + x.a23 * y.a31,
        x.a21 * y.a12 + x.a22 * y.a22 + x.a23 * y.a32,
        x.a21 * y.a13 + x.a22 * y.a23 + x.a23 * y.a33,
        
        x.a31 * y.a11 + x.a32 * y.a21 + x.a33 * y.a31,
        x.a31 * y.a12 + x.a32 * y.a22 + x.a33 * y.a32,
        x.a31 * y.a13 + x.a32 * y.a23 + x.a33 * y.a33);
}

mat3x3 operator * (const mat3x3& x, float c)
{
    return mat3x3
       (x.a11 * c, x.a12 * c, x.a13 * c,
        x.a21 * c, x.a22 * c, x.a23 * c,
        x.a31 * c, x.a32 * c, x.a33 * c);
}

vec3 operator * (const mat3x3& x, const vec3& v)
{
    return vec3
       (x.a11 * v.x + x.a12 * v.y + x.a13 * v.z,
        x.a21 * v.x + x.a22 * v.y + x.a23 * v.z,
        x.a31 * v.x + x.a32 * v.y + x.a33 * v.z);
}

    
#endif // MATH_H
