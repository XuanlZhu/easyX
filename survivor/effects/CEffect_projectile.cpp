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

void RotateImageAlpha(IMAGE* dst, IMAGE* src, float angle)
{
    int srcW = src->getwidth();
    int srcH = src->getheight();

    float rad = angle * 3.1415926f / 180.0f;

    float sinA = fabs(sin(rad));
    float cosA = fabs(cos(rad));

    // 新图片大小
    int dstW = (int)(srcW * cosA + srcH * sinA);
    int dstH = (int)(srcW * sinA + srcH * cosA);


    // 创建目标图片
    *dst = IMAGE(dstW, dstH);


    DWORD* srcBuffer = GetImageBuffer(src);
    DWORD* dstBuffer = GetImageBuffer(dst);


    float srcCX = srcW / 2.0f;
    float srcCY = srcH / 2.0f;

    float dstCX = dstW / 2.0f;
    float dstCY = dstH / 2.0f;


    float cosR = cos(rad);
    float sinR = sin(rad);


    for(int y=0;y<dstH;y++)
    {
        for(int x=0;x<dstW;x++)
        {

            // 目标像素相对于中心
            float dx = x - dstCX;
            float dy = y - dstCY;


            // 反向旋转
            float srcX =
                dx * cosR +
                dy * sinR +
                srcCX;

            float srcY =
               -dx * sinR +
                dy * cosR +
                srcCY;


            int ix = (int)srcX;
            int iy = (int)srcY;


            DWORD color = 0;


            if(ix>=0 && ix<srcW &&
               iy>=0 && iy<srcH)
            {
                color = srcBuffer[iy * srcW + ix];
            }
            else
            {
                // 完全透明
                color = 0x00000000;
            }


            dstBuffer[y * dstW + x] = color;
        }
    }
}

CEffect_projectile::CEffect_projectile(CSprite* _sprite){
    mLifeTime = 9999;
    mAttacher = _sprite;
}

void CEffect_projectile::SetParticleControl(int _controlPoint, CVector2 _pos) {
    CEffect::SetParticleControl(_controlPoint, _pos);

    for (auto& img : mAnimation)
    {
        IMAGE rotated;
        RotateImageAlpha(&rotated, &img, _pos.ToAngle());
        mAnimation2.push_back(rotated);
    }
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
    // putimage(screenPos.x,screenPos.y,&mAnimation2[mFrame]);
    putimage_alpha(screenPos.x-length/2-30,screenPos.y-length/2,length,length,mAnimation2[mFrame]);
}

