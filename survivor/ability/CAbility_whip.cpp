//
// Created by admin on 2026/8/4.
//

#include "CAbility_whip.h"

#include "../func/CBuffManager.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"
#include "Graphics/CEffect.h"
#include "ResourceManager/CEffectManager.h"
#include "ResourceManager/CSoundManager.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void CAbility_whip::OnSpellStart() {
    mLastCastTime = GetNowTime();//记录施法时间

    auto it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(100,-30),nullptr).lock();//创建特效
    it->SetParticleControl(0,CVector2(0,0));
    // it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(100,30),nullptr).lock();//创建特效
    // it->SetParticleControl(0,CVector2(180,0));
    // it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(-100,-30),nullptr).lock();//创建特效
    // it->SetParticleControl(0,CVector2(0,0));
    // it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(-100,30),nullptr).lock();//创建特效
    // it->SetParticleControl(0,CVector2(180,0));

    auto units = FindUnitsInLine(3, mCaster->GetPos()+CVector2(0,0),mCaster->GetPos()+CVector2(200,0),30);
    for (auto& x: units) {
        auto unit = x.lock();
        ApplyDamage(DamageContext{mCaster,unit.get(),1});
        EmitSoundOn("ice_impact");
    }
}