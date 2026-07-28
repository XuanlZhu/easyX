//
// Created by admin on 2026/7/26.
//

#include "CEffectManager.h"

#include <iostream>

#include "../../survivor/effects/CEffectNumber.h"
#include "Graphics/CEffect.h"
#include "../../survivor/effects/CEffect_circle.h"


void CEffectManager::Update(float _deltaTime) {
    for(auto& effect : mEffects)
    {
        effect->Update(_deltaTime);
        // std::cout << "特效更新" << std::endl;
    }
    DestroyEffects();//销毁
}

void CEffectManager::Draw(CCamera& _camera) {
    for(auto& effect : mEffects)
    {
        effect->Draw(_camera);
        // std::cout << "特效绘制" << std::endl;
    }
}

//销毁
void CEffectManager::DestroyEffects()
{
    mEffects.erase(
        std::remove_if(mEffects.begin(),mEffects.end(),
            [](std::shared_ptr<CEffect>& _effect)
            {
                return _effect->IsDead();
            }
        ),
        mEffects.end()
    );
}
//创建effect
std::weak_ptr<CEffect> CEffectManager::CreateEffect(std::string _className, CVector2 _pos) {
    std::shared_ptr<CEffect> effect;
    if (_className == "CEffectNumber") {
        effect = std::make_shared<CEffectNumber>();//创建effecf
    }else if (_className == "CEffect_circle") {
        effect = std::make_shared<CEffect_circle>();
    }
    else {
        effect = std::make_shared<CEffect>();
    }
    effect->mPos = _pos;
    mEffects.push_back(effect);
    // std::cout << "特效入表" << std::endl;
    return effect;
}
// std::weak_ptr<CEffect> CEffectManager::CreateEffect() {
//     std::shared_ptr<CEffect> effect = std::make_shared<CEffect>();//创建effect
//     // effect->mAttacher = _owner;
//     // thinker->mName = _name;
//     mEffects.push_back(effect);
//     return effect;
// }
