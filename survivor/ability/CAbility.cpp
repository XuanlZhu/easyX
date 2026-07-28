//
// Created by admin on 2026/7/27.
//

#include "CAbility.h"

#include <iostream>

#include "../func/Global.h"
#include "ResourceManager/CSoundManager.h"

void CAbility::OnSpellStart() {
    mLastCastTime = GetNowTime();
    std::cout << "释放技能" << std::endl;
    Global::soundManager->Play("hoof_stomp");

}

bool CAbility::IsCooldownReady() {
    if ((GetNowTime()-mLastCastTime)>=mCoolDown) {
        return true;
    }
    return false;
}
