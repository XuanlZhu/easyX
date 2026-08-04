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
    CreateLinearProjectile(LinearProjectileContext{
        this,
        CVector2(),
        10,
        100,
        300,
        CVector2(100,100),
        mCaster,
        3,
        "CEffect_projectile",
        {}
    });
}

bool CAbility_flyingKnife::OnProjectileHit(CUnit *_unit, CVector2 _pos, nlohmann::json _data) {

    return true;
}