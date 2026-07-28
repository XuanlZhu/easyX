//
// Created by admin on 2026/7/28.
//

#pragma once
#include <string>
#include <vector>

#include "Graphics/CEffect.h"
#include "../func/Global.h"
#include "ResourceManager/CAnimaManager.h"

class CEffect_circle:  public CEffect
{
public:
    CEffect_circle();
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
    std::vector<IMAGE>& mAnimation = Global::animaManager->GetAnimation(0);
    int mFrame=0;
    float mFrameTime=0;
};
