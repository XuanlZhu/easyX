//
// Created by admin on 2026/7/28.
//

#include "CEffect_circle.h"

#include "Graphics/CCamera.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);

CEffect_circle::CEffect_circle(){
    mLifeTime = 0.8f;
}

void CEffect_circle::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    if(mFrameTime >= 0.05)
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

void CEffect_circle::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = mControlPoint0.x/0.38;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation[mFrame]);
}
