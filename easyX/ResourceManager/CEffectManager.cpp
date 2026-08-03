//
// Created by admin on 2026/7/26.
//

#include "CEffectManager.h"

#include <iostream>

#include "../../survivor/effects/CEffectNumber.h"
#include "Graphics/CEffect.h"
#include "../../survivor/effects/CEffect_circle.h"
#include "../../survivor/effects/CEffect_stunned.h"
#include "../../survivor/effects/CEffect_levelup.h"
#include "../../survivor/effects/CEffect_levelup2.h"

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
std::weak_ptr<CEffect> CEffectManager::CreateEffect(std::string _className, CVector2 _pos,CSprite* _attacher) {
    std::shared_ptr<CEffect> effect;
    if (_className == "CEffectNumber") {
        effect = std::make_shared<CEffectNumber>();//创建effecf
    }else if (_className == "CEffect_circle") {
        effect = std::make_shared<CEffect_circle>();
    }else if (_className == "CEffect_stunned") {
        effect = std::make_shared<CEffect_stunned>(_attacher);
    }else if (_className == "CEffect_levelup") {
        effect = std::make_shared<CEffect_levelup>(_attacher);
    }else if (_className == "CEffect_levelup2") {
        effect = std::make_shared<CEffect_levelup2>(_attacher);
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
