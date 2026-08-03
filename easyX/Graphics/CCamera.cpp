//
// Created by admin on 2026/7/14.
//

#include "CCamera.h"
//构造函数
CCamera::CCamera()
{
}

void CCamera::SetPosition(CVector2 _pos) {
    mPosition.x = _pos.x;mPosition.y = _pos.y;
}

void CCamera::Move(float _x,float _y)
{
    mPosition.x += _x;mPosition.y += _y;
}
//世界坐标转屏幕坐标
CVector2 CCamera::WorldToScreen(CVector2 _worldPos)
{
    return CVector2(_worldPos.x - mPosition.x,_worldPos.y - mPosition.y);
}

CVector2 CCamera::GetPos()
{
    return mPosition;
}