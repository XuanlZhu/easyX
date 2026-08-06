//
// Created by admin on 2026/7/27.
//

#include "CAbility.h"

#include "../func/CBuffManager.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;


CAbility::~CAbility() {
    auto buff = mIntrinsicModifier.lock();
    if (buff) {buff->Destroy();}
}

bool CAbility::IsCooldownReady() {
    if ((GetNowTime()-mLastCastTime)>=mCoolDown) {
        return true;
    }
    return false;
}

void CAbility::OnCreated() {
    mIntrinsicModifier = mCaster->AddNewModifier(mCaster, this, GetIntrinsicModifierName(), json{});
    auto buff = mIntrinsicModifier.lock();
    if (buff) {buff->isPassive = true;}
}
