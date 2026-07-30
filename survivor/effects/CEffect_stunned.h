//
// Created by admin on 2026/7/30.
//

#pragma once
#include <vector>

#include "Graphics/CEffect.h"
#include "../func/Global.h"
#include "ResourceManager/CAnimaManager.h"

class CEffect_stunned:public CEffect
{
public:
    CEffect_stunned(CSprite* _sprite);
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
    std::vector<IMAGE>& mAnimation = Global::animaManager->GetAnimation(11);
    int mFrame=0;
    float mFrameTime=0;
};
