//
// Created by admin on 2026/8/5.
//

#pragma once
#include <vector>

#include "Graphics/CEffect.h"
#include "../func/Global.h"
#include "ResourceManager/CAnimaManager.h"

class CEffect_gem:public CEffect
{
public:
    CEffect_gem(CSprite* _sprite);
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
    std::vector<IMAGE>& mAnimation = Global::animaManager->GetAnimation(11);
    int mFrame=0;
    float mFrameTime=0;
};

