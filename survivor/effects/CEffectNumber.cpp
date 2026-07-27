//
// Created by admin on 2026/7/26.
//

#include "CEffectNumber.h"

#include "Graphics/CCamera.h"
#include <string>

CEffectNumber::CEffectNumber(){
    mLifeTime = 0.5f;
}

CEffectNumber::CEffectNumber(std::string _value) {
    mLifeTime = 0.5f;
    mValue = _value;
}

void CEffectNumber::Update(float _deltaTime) {
    CEffect::Update(_deltaTime);
    mPos.y -= 30*_deltaTime;
}

void CEffectNumber::Draw(CCamera &_camera) {
    if(IsDead())return;
    CVector2 screenPos = _camera.WorldToScreen(mPos);
    std::wstring value(mValue.begin(), mValue.end());
    outtextxy(screenPos.x,screenPos.y,value.c_str());
}
