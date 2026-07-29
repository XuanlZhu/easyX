//
// Created by admin on 2026/7/17.
//

#include "CPlayer.h"
#include <cstdio>
#include <iostream>

#include "../ability/CAbility.h"

CPlayer::CPlayer(std::string _name) : CUnit(_name){
    mCanRespawn = true;//可以重生
    this->AddAbility("1");
    this->SetContextThink("auto_cast",[&] {
        // std::cout << "遍历技能" << std::endl;
        for(auto& ability : mAbilitys)
        {
            if (ability->IsCooldownReady()) {
                CastAbilityOnTarget(this, ability.get());
            }
        }
        return 0.5;
    },0);
}

void CPlayer::Update(float _deltaTime) {
    if (IsDeath())return;
    mPos.x += mChangeX * _deltaTime;
    mPos.y += mChangeY * _deltaTime;


    // outtextxy(100, 100, L"Hello EasyX");
    // std::cout << _deltaTime << std::endl;
    // std::cout << mChangeX << std::endl;
}
