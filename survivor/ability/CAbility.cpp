//
// Created by admin on 2026/7/27.
//

#include "CAbility.h"

#include <iostream>

#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "Core/CVector2.h"
#include "ResourceManager/CEffectManager.h"
#include "ResourceManager/CSoundManager.h"

void CAbility::OnSpellStart() {
    mLastCastTime = GetNowTime();
    // std::cout << "释放技能" << std::endl;
    EmitSoundOn("hoof_stomp");
    CreateEffect("CEffect_circle",mCaster->GetPos());

}

bool CAbility::IsCooldownReady() {
    if ((GetNowTime()-mLastCastTime)>=mCoolDown) {
        return true;
    }
    return false;
}
