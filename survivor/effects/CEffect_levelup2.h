//
// Created by admin on 2026/8/3.
//

#pragma once
#include <vector>

#include "Graphics/CEffect.h"
#include "../func/Global.h"
#include "ResourceManager/CAnimaManager.h"

class CEffect_levelup2:  public CEffect
{
public:
    CEffect_levelup2(CSprite* _sprite);
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
    std::vector<IMAGE>& mAnimation = Global::animaManager->GetAnimation(29);
    int mFrame=0;
    float mFrameTime=0;
};
