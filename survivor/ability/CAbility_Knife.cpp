//
// Created by admin on 2026/8/5.
//

#include "CAbility_Knife.h"

#include "../func/CBuffManager.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"
#include "Graphics/CEffect.h"
#include "ResourceManager/CEffectManager.h"
#include "ResourceManager/CSoundManager.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

CAbility_Knife::CAbility_Knife() {
    mCoolDown = 1;
}

void CAbility_Knife::OnSpellStart() {
    mLastCastTime = GetNowTime();//记录施法时间

    auto tab =LinearProjectileContext{
        this,
        CVector2(),
        10,
        10,
        250,
        CVector2(150,150),
        mCaster,
        3,
        "CEffect_knife",
        {}
    };

    tab.vVelocity = mCaster->mLookat.Normalize()*350;
    for (int i = 0; i < 4; i++) {
        tab.vSpawnOrigin = RandomVector(20);
        CreateLinearProjectile(tab);
    }

    EmitSoundOn("stifling_dagger_cast");
}

bool CAbility_Knife::OnProjectileHit(CUnit* _unit, CVector2 _pos, nlohmann::json _data) {
    ApplyDamage(DamageContext{mCaster,_unit,50});
    EmitSoundOn("attack_long01");
    // unit->AddNewModifier(mCaster,this,"buff",json{{"duration", 1}});
    return true;
}