//
// Created by admin on 2026/7/27.
//

#include "CAbility.h"

#include <iostream>

#include "../func/CBuffManager.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"
#include "Graphics/CEffect.h"
#include "ResourceManager/CEffectManager.h"
#include "ResourceManager/CSoundManager.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void CAbility::OnSpellStart() {
    mLastCastTime = GetNowTime();
    // std::cout << "释放技能" << std::endl;
    EmitSoundOn("hoof_stomp");
    auto effect = CreateEffect("CEffect_circle",mCaster->GetPos(),nullptr).lock();
    effect->SetParticleControl(0,CVector2(150,0));

    auto units = FindUnitsInRadius(3, mCaster->GetPos(),150,0);
    for (auto& x: units) {
        auto unit = x.lock();
        ApplyDamage(DamageContext{mCaster,unit.get(),100});
        unit->AddNewModifier(mCaster,this,"buff",json{
            {"duration", 1}
        });
    }
}

bool CAbility::IsCooldownReady() {
    if ((GetNowTime()-mLastCastTime)>=mCoolDown) {
        return true;
    }
    return false;
}
