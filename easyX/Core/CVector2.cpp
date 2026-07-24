//
// Created by admin on 2026/7/16.
//

#include "CVector2.h"

#include <cmath>

CVector2::CVector2()
{
    x = 0;
    y = 0;
}

CVector2::CVector2(float _x,float _y)
{
    x = _x;
    y = _y;
}



CVector2 CVector2::operator+(const CVector2& _other) const
{
    return CVector2(x + _other.x,y + _other.y);
}



CVector2 CVector2::operator-(const CVector2& _other) const
{
    return CVector2(x - _other.x,y - _other.y);
}



CVector2 CVector2::operator*(float _value) const
{
    return CVector2(x * _value,y * _value);
}

float CVector2::Length() const {
    return std::sqrt(x * x + y * y);
}

CVector2 CVector2::Normalize() const {
    float len = Length();
    //防止除0
    if(len == 0)
    {
        return CVector2(0, 0);
    }
    return CVector2(x / len,y / len);
}
