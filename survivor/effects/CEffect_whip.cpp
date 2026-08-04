//
// Created by admin on 2026/8/4.
//

#include "CEffect_whip.h"

#include "Graphics/CCamera.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);
extern void RotateImageAlpha(IMAGE* dst, IMAGE* src, float angle);

CEffect_whip::CEffect_whip(){
    mLifeTime = 0.5f;
}

void CEffect_whip::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    if(mFrameTime >= 0.03)
    {
        mFrameTime = 0;
        mFrame++;
        // 循环
        if(mFrame >= mAnimation.size())
        {
            mFrame = 0;
        }
    }
}

void CEffect_whip::SetParticleControl(int _controlPoint, CVector2 _pos) {
    CEffect::SetParticleControl(_controlPoint, _pos);

    for (auto& img : mAnimation)
    {
        IMAGE rotated;
        RotateImageAlpha(&rotated, &img, mControlPoint0.x-30);
        mAnimation2.push_back(rotated);
    }
}


void CEffect_whip::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 200;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation2[mFrame]);
}
