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

}

bool CAbility::IsCooldownReady() {
    if ((GetNowTime()-mLastCastTime)>=mCoolDown) {
        return true;
    }
    return false;
}
