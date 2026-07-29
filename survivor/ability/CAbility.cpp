//
// Created by admin on 2026/7/27.
//

#include "CAbility.h"

#include <iostream>

#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"
#include "Graphics/CEffect.h"
#include "ResourceManager/CEffectManager.h"
#include "ResourceManager/CSoundManager.h"

void CAbility::OnSpellStart() {
    mLastCastTime = GetNowTime();
    // std::cout << "释放技能" << std::endl;
    EmitSoundOn("hoof_stomp");
    auto effect = CreateEffect("CEffect_circle",mCaster->GetPos()).lock();
    effect->SetParticleControl(0,CVector2(150,0));

    auto units = FindUnitsInRadius(3, mCaster->GetPos(),150,0);
    for (auto& x: units) {
        auto unit = x.lock();
        // unit->OnDeath();
        ApplyDamage(DamageContext{mCaster,unit.get(),1});
    }
}

bool CAbility::IsCooldownReady() {
    if ((GetNowTime()-mLastCastTime)>=mCoolDown) {
        return true;
    }
    return false;
}
