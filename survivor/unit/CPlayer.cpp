//
// Created by admin on 2026/7/17.
//

#include "CPlayer.h"
#include <cstdio>
#include <iostream>
#include "../func/Global.h"
#include <memory>

#include "../ability/CAbility.h"
#include "../sprite/CXpGem.h"

vector<int> xp_table={};
CPlayer::CPlayer(std::string _name) : CUnit(_name){
    mCanRespawn = true;//可以重生

    int xp = 10;
    for (int i = 0; i < 100; i++) {
        xp_table.push_back(xp);
        xp += 10;
    }
}

void CPlayer::OnCreate() {
    this->AddAbility("CAbility_damage_aura");
    // this->AddAbility("CAbility_KingBook");
    // this->AddAbility("CAbility_stamp");
    // this->AddAbility("CAbility_flyingKnife");
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

    if (mChangeX ==0 && mChangeY ==0) {
    }else{mLookat = CVector2(mChangeX,mChangeY).Normalize();}

    //搜索宝石
    std::vector<std::shared_ptr<CXpGem>> result;
    for(auto& sprite : Global::spriteList->mSprites)
    {
        auto gem = std::dynamic_pointer_cast<CXpGem>(sprite);
        if(gem){result.push_back(gem);}//过滤宝石
    }
    for(auto& gem : result)
    {
        if(gem->isflying)continue;
        // 距离判断
        float distance = (gem->GetPos() - mPos).Length();

        if(distance <= 30)
        {
            gem->Pickup();
        }
    }

}
//通过经验判断等级
int GetLevelByXP(int _xp)
{
    int level = 1;int totalXP = 0;

    for(int i = 0; i < xp_table.size(); i++)
    {
        totalXP += xp_table[i];
        if(_xp >= totalXP){level++;}else{break;}
    }
    return level;
}

void CPlayer::AddExperience(int _v) {
    mXP +=_v;
    int newLevel = GetLevelByXP(mXP);
    if (newLevel>mLevel) {
        for(int i = 0; i < newLevel-mLevel; i++) {
            OnLevelUp();
        }
        mLevel = newLevel;
        EmitSoundOn("level_up");
        CreateEffect("CEffect_levelup2",this->GetPos(),this);
    }
}
//当升级
void CPlayer::OnLevelUp() {
    //属性提升，直接修改base
    // mAttributeSystem.base["attack_damage"];
    mAttributeSystem.ModifyBase("strength",2.6);
    mAttributeSystem.ModifyBase("agility",2.6);
    mAttributeSystem.ModifyBase("intellect",2.6);
}

