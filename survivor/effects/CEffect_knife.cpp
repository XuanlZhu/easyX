//
// Created by admin on 2026/8/5.
//

#include "CEffect_knife.h"

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
#include "Scene/SpriteList.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);
extern void RotateImageAlpha(IMAGE* dst, IMAGE* src, float angle);

CEffect_knife::CEffect_knife(CSprite* _sprite){
    mLifeTime = 9999;
    mAttacher = Global::spriteList->GetSharedPtr(_sprite);
}

void CEffect_knife::SetParticleControl(int _controlPoint, CVector2 _pos) {
    CEffect::SetParticleControl(_controlPoint, _pos);

    RotateImageAlpha(&mImage2, mImage, _pos.ToAngle()-130);

    for (auto& img : mAnimation)
    {
        IMAGE rotated;
        RotateImageAlpha(&rotated, &img, _pos.ToAngle());
        mAnimation2.push_back(rotated);
    }
}

void CEffect_knife::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    auto unit = mAttacher.lock();
    if (unit) {
        mPos = unit->GetPos();
    }else {
        Destroy();
    }

    if(mFrameTime >= 0.04)
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

void CEffect_knife::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 100;

    // putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation2[mFrame]);
    putimage_alpha(screenPos.x-15,screenPos.y-15,30,30,mImage2);
}