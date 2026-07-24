//
// Created by admin on 2026/7/16.
//

#pragma once

class CVector2
{
public:
    float x;
    float y;
    CVector2();
    CVector2(float _x, float _y);
    //加法
    CVector2 operator+(const CVector2& _other) const;
    //减法
    CVector2 operator-(const CVector2& _other) const;
    //乘法
    CVector2 operator*(float _value) const;
    float Length() const;//长度
    CVector2 Normalize() const;//归1化
};
