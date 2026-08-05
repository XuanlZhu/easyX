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

    EmitSoundOn("riki_backstab");
    auto it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(100,-40),nullptr).lock();//创建特效
    it->SetParticleControl(0,CVector2(0,0));
    auto units = FindUnitsInLine(3, mCaster->GetPos()+CVector2(0,-40),mCaster->GetPos()+CVector2(200,-40),25);
    for (auto& x: units) {
        auto unit = x.lock();
        ApplyDamage(DamageContext{mCaster,unit.get(),1});
    }

    EmitSoundOn("riki_backstab");
    it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(100,40),nullptr).lock();//创建特效
    it->SetParticleControl(0,CVector2(180,0));
    units = FindUnitsInLine(3, mCaster->GetPos()+CVector2(0,40),mCaster->GetPos()+CVector2(200,40),25);
    for (auto& x: units) {
        auto unit = x.lock();
        ApplyDamage(DamageContext{mCaster,unit.get(),1});
    }

    EmitSoundOn("riki_backstab");
    it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(-100,-40),nullptr).lock();//创建特效
    it->SetParticleControl(0,CVector2(0,0));
    units = FindUnitsInLine(3, mCaster->GetPos()+CVector2(0,-40),mCaster->GetPos()+CVector2(-200,-40),25);
    for (auto& x: units) {
        auto unit = x.lock();
        ApplyDamage(DamageContext{mCaster,unit.get(),1});
    }

    EmitSoundOn("riki_backstab");
    it = CreateEffect("CEffect_whip",mCaster->GetPos()+CVector2(-100,40),nullptr).lock();//创建特效
    it->SetParticleControl(0,CVector2(180,0));
    it->SetParticleControl(0,CVector2(0,0));
    units = FindUnitsInLine(3, mCaster->GetPos()+CVector2(0,40),mCaster->GetPos()+CVector2(-200,40),25);
    for (auto& x: units) {
        auto unit = x.lock();
        ApplyDamage(DamageContext{mCaster,unit.get(),1});
    }

}