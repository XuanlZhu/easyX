//
// Created by admin on 2026/8/3.
//

#include "CEffect_levelup.h"

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);

CEffect_levelup::CEffect_levelup(CSprite* _sprite){
    mLifeTime = 1.2f;
    mAttacher = _sprite;
}

void CEffect_levelup::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    try{mPos = mAttacher->GetPos();}catch(const char* msg){
        Destroy();//附着者失效就销毁
    }

    if(mFrameTime >= 0.08)
    {
        mFrameTime = 0;
        mFrame++;
        // 循环
        if(mFrame >= mAnimation.size())
        {
            mFrame = 0;
        }
    }
    //绑定
    // try{mPos = mAttacher->GetPos();}catch(const char* msg){
    //     Destroy();//附着者失效就销毁
    // }
}

void CEffect_levelup::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 85;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation[mFrame]);
}