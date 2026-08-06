//
// Created by admin on 2026/8/6.
//

#include "CEffect_damage_aura.h"

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
#include "Scene/SpriteList.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);

CEffect_damage_aura::CEffect_damage_aura(CSprite* _sprite){
    mLifeTime = 0.5f;
    mAttacher = Global::spriteList->GetSharedPtr(_sprite);;
}

void CEffect_damage_aura::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    auto unit = mAttacher.lock();
    if (unit) {
        mPos = unit->GetPos();
    }else{Destroy();}

    if(mFrameTime >= 0.07)
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

void CEffect_damage_aura::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = mControlPoint0.x/0.8*2;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation[mFrame]);
}