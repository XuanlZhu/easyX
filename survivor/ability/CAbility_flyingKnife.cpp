//
// Created by admin on 2026/8/3.
//

#include "CAbility_flyingKnife.h"

#include "../func/CBuffManager.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"
#include "Graphics/CEffect.h"
#include "ResourceManager/CEffectManager.h"
#include "ResourceManager/CSoundManager.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void CAbility_flyingKnife::OnSpellStart() {
    mLastCastTime = GetNowTime();//记录施法时间
    EmitSoundOn("hoof_stomp");
    // CreateCSprite("CProjectile",mCaster->GetPos());

    auto tab =LinearProjectileContext{
        this,
        CVector2(),
        10,
        100,
        300,
        CVector2(150,150),
        mCaster,
        3,
        "CEffect_projectile",
        {}
    };

    auto units = FindUnitsInRadius(3, mCaster->GetPos(),300,0);
    for (auto& x: units) {
        auto unit = x.lock();
        tab.vVelocity = (unit->GetPos()-mCaster->GetPos()).Normalize()*150;
        CreateLinearProjectile(tab);
    }
}

bool CAbility_flyingKnife::OnProjectileHit(CUnit *_unit, CVector2 _pos, nlohmann::json _data) {

    return true;
}