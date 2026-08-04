//
// Created by admin on 2026/8/4.
//

#pragma once
#include <string>
#include <vector>

#include "Graphics/CEffect.h"
#include "../func/Global.h"
#include "ResourceManager/CAnimaManager.h"

class CEffect_whip:  public CEffect
{
public:
    CEffect_whip();
    void Update(float _deltaTime) override;//更新
    void Draw(CCamera& _camera) override;//绘制
    void SetParticleControl(int _controlPoint,CVector2 _pos) override;
    std::vector<IMAGE>& mAnimation = Global::animaManager->GetAnimation(47);
    std::vector<IMAGE> mAnimation2;
    int mFrame=0;
    float mFrameTime=0;
};
