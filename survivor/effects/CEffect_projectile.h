//
// Created by admin on 2026/8/4.
//

#pragma once

#include <vector>

#include "Graphics/CEffect.h"
#include "../func/Global.h"
#include "ResourceManager/CAnimaManager.h"

class CEffect_projectile:public CEffect
{
public:
    CEffect_projectile(CSprite* _sprite);
    void SetParticleControl(int _controlPoint,CVector2 _pos) override;
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
    std::vector<IMAGE>& mAnimation = Global::animaManager->GetAnimation(38);
    std::vector<IMAGE> mAnimation2;
    int mFrame=0;
    float mFrameTime=0;
};
