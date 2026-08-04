//
// Created by admin on 2026/8/4.
//

#include "CEffect_projectile.h"

#include <iostream>

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);

CEffect_projectile::CEffect_projectile(CSprite* _sprite){
    mLifeTime = 9999;
    mAttacher = _sprite;
}

void CEffect_projectile::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    try{mPos = mAttacher->GetPos();}catch(const char* msg){
        std::cout << "CEffect_stunned捕捉到异常" << std::endl;
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

void CEffect_projectile::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 100;

    putimage_alpha(screenPos.x-length/2-30,screenPos.y-length/2,length,length,mAnimation[mFrame]);
}
