//
// Created by admin on 2026/8/6.
//

#include "CEffect_cross.h"

#include "Graphics/CCamera.h"
#include "Graphics/CSprite.h"
#include "ResourceManager/CImageManager.h"
#include "Scene/SpriteList.h"
// #include "../func/Global.h"
// #include "ResourceManager/CAnimaManager.h"
extern void putimage_alpha(float x,float y,float dstW,float dstH,IMAGE& img);
extern void RotateImageAlpha(IMAGE* dst, IMAGE* src, float angle);

CEffect_cross::CEffect_cross(CSprite* _sprite){
    mLifeTime = 9999;
    mAttacher = Global::spriteList->GetSharedPtr(_sprite);

    auto axe = Global::imgManager->GetImage("PNG/cross.png");
    float angele = 0;
    for (int i = 0; i < 12; i++)
    {
        IMAGE rotated;angele += 30;
        RotateImageAlpha(&rotated, axe, angele);
        mAnimation2.push_back(rotated);
    }
}

void CEffect_cross::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mFrameTime += _deltaTime;

    auto unit = mAttacher.lock();
    if (unit) {
        mPos = unit->GetPos();
    }else{Destroy();}

    if(mFrameTime >= 0.03)
    {
        mFrameTime = 0;
        mFrame++;
        // 循环
        if(mFrame >= mAnimation2.size())
        {
            mFrame = 0;
        }
    }
}

void CEffect_cross::Draw(CCamera& _camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);

    float length = 65;

    putimage_alpha(screenPos.x-length/2,screenPos.y-length/2,length,length,mAnimation2[mFrame]);
}