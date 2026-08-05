//
// Created by admin on 2026/8/5.
//

#pragma once
#include <vector>

#include "Graphics/CEffect.h"
#include "../func/Global.h"
#include "ResourceManager/CAnimaManager.h"
#include "ResourceManager/CImageManager.h"

class CEffect_knife:public CEffect
{
public:
    CEffect_knife(CSprite* _sprite);
    void SetParticleControl(int _controlPoint,CVector2 _pos) override;
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
    std::vector<IMAGE>& mAnimation = Global::animaManager->GetAnimation(36);
    std::vector<IMAGE> mAnimation2;
    IMAGE* mImage = Global::imgManager->GetImage("PNG/knife.png");//图片
    IMAGE mImage2;
    int mFrame=0;
    float mFrameTime=0;
};
