//
// Created by admin on 2026/7/30.
//

#include "CEffect_stunned.h"

#include <iostream>

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
#include "Scene/SpriteList.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);

CEffect_stunned::CEffect_stunned(CSprite* _sprite){
    mLifeTime = 9999;
    mAttacher = Global::spriteList->GetSharedPtr(_sprite);;
}

void CEffect_stunned::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    auto unit = mAttacher.lock();
    if (unit) {
        mPos = unit->GetPos();
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

void CEffect_stunned::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 65;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation[mFrame]);
}
