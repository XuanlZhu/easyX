//
// Created by admin on 2026/7/14.
//

#pragma once
#include "Core/CVector2.h"


class CCamera
{
public:
    CCamera();
    void SetPosition(CVector2 _pos);//设置相机位置
    void Move(float _x, float _y);//移动相机
    //世界坐标转屏幕坐标
    CVector2 WorldToScreen(CVector2 _worldPos);
    //获取位置
    CVector2 GetPosition();
private:
    //相机世界坐标
    CVector2 mPosition;
};

