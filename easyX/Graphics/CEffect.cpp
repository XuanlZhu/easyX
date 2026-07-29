//
// Created by admin on 2026/7/26.
//

#include "CEffect.h"

#include <iostream>

#include "CCamera.h"

CEffect::CEffect() {
}

// CEffect::CEffect(CVector2 _pos)
// {
//     mPos = _pos;
// }

void CEffect::Update(float _deltaTime)
{
    mAge += _deltaTime;
}
//绘制
void CEffect::Draw(CCamera &_camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);
    outtextxy(screenPos.x,screenPos.y,L"Hello EasyX");
    // std::cout << "特效绘制" << std::endl;
}

bool CEffect::IsDead()
{
    if (mAge >= mLifeTime) {
        mIsDead = true;
    }
    return mIsDead;
}

void CEffect::SetParticleControl(int _controlPoint, CVector2 _pos) {
    if (_controlPoint==0) {
        mControlPoint0 = _pos;
    }else if (_controlPoint==1) {
        mControlPoint1 = _pos;
    }else if (_controlPoint==2) {
        mControlPoint2 = _pos;
    }else if (_controlPoint==3) {
        mControlPoint3 = _pos;
    }
}


// void CEffect::Draw()
// {
//     if(IsDead())
//         return;
//     //计算透明度
//     // float progress = mAge / mLifeTime;
//
//     // int alpha = 255 * (1.0f - progress);
//
//     //EasyX设置透明
//     // setlinecolor(RGB(255,255,0));
//
//
//     // circle(mPos.x,mPos.y,mRadius);
// }