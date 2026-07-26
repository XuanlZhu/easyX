//
// Created by admin on 2026/7/26.
//

#pragma once
#include "Graphics/CEffect.h"


class CEffectNumber :  public CEffect
{
public:
    CEffectNumber();
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
};

