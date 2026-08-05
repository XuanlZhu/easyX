//
// Created by admin on 2026/8/5.
//

#include "CEffect_gem.h"

#include <iostream>

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
#include "Scene/SpriteList.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);

CEffect_gem::CEffect_gem(CSprite* _sprite){
    mLifeTime = 9999;
    mAttacher = Global::spriteList->GetSharedPtr(_sprite);;
}

void CEffect_gem::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    auto unit = mAttacher.lock();
    if (unit) {
        mPos = unit->GetPos() + mControlPoint0;
    }else{Destroy();}

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

void CEffect_gem::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 20;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation[mFrame]);
}