//
// Created by admin on 2026/8/3.
//

#include "CXpGem.h"
#include "../func/Global.h"
#include "../unit/CUnit.h"
#include "ResourceManager/CImageManager.h"
#include "../unit/CPlayer.h"

CXpGem::CXpGem() {
    mImage = Global::imgManager->GetImage("PNG/gem1.png");
    mLength = 25;
}

void CXpGem::Pickup() {
    isflying = true;
    auto dir = (Global::player->GetPos()-mPos).Normalize();
    SetPosition(mPos-dir*20);
}

void CXpGem::Update(float _deltaTime) {
    if (isflying) {
        // 距离判断
        float distance = (Global::player->GetPos() - mPos).Length();
        if (distance<=5) {
            Global::player->AddExperience(BountyXP);
            EmitSoundOn("pickup_gem");
            Destroy();
        }
        mSpeed +=1;
        auto dir = (Global::player->GetPos()-mPos).Normalize()*_deltaTime*mSpeed;
        SetPosition(mPos+dir);
    }
}

