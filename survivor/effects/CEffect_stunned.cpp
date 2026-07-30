//
// Created by admin on 2026/7/30.
//

#include "CEffect_stunned.h"

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(int x,int y,int dstW,int dstH,IMAGE& img);

CEffect_stunned::CEffect_stunned(CSprite* _sprite){
    mLifeTime = 9999;
    mAttacher = _sprite;
}

void CEffect_stunned::Update(float _deltaTime) {
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
}

void CEffect_stunned::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 65;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation[mFrame]);
}
