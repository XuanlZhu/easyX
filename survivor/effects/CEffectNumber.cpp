//
// Created by admin on 2026/7/26.
//

#include "CEffectNumber.h"

#include "Graphics/CCamera.h"

CEffectNumber::CEffectNumber(){
    mLifeTime = 0.5f;
}

void CEffectNumber::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mPos.y -= 30*_deltaTime;
}

void CEffectNumber::Draw(CCamera &_camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);
    outtextxy(screenPos.x,screenPos.y,L"你好 世界！");
}
