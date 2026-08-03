//
// Created by admin on 2026/8/3.
//

#include "CEffect_levelup2.h"

#include "Graphics/CSprite.h"

extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);

CEffect_levelup2::CEffect_levelup2(CSprite* _sprite){
    // mLifeTime = 0.65f;
    mLifeTime = 1.2f;
    mAttacher = _sprite;
}

void CEffect_levelup2::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    try{mPos = mAttacher->GetPos();}catch(const char* msg){
        Destroy();//附着者失效就销毁
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
    //绑定
    // try{mPos = mAttacher->GetPos();}catch(const char* msg){
    //     Destroy();//附着者失效就销毁
    // }
}

void CEffect_levelup2::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 170;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2+30,length,length/2,mAnimation[mFrame]);
}
