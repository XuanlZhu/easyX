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
        ApplyDamage(DamageContext{mCaster,unit.get(),56});
        // std::cout << "开始附加buff" << std::endl;
        // unit->AddNewModifier(mCaster,this,"buff",json{
        //     {"duration", 1}
        // });

        // std::cout << "buff附加完成" << std::endl;
    }
    // ApplyDamage(DamageContext{mCaster,mCaster,100});
    static int a=0;
    if (!a) {
        mCaster->AddNewModifier(mCaster,this,"CBuff_test",json{
            {"duration", 5}
        });
        a++;
    }

    // std::cout << "技能释放完毕" << std::endl;
}

bool CAbility::IsCooldownReady() {
    if ((GetNowTime()-mLastCastTime)>=mCoolDown) {
        return true;
    }
    return false;
}
