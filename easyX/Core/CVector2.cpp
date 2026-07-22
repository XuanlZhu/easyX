//
// Created by admin on 2026/7/16.
//

#include "CVector2.h"

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