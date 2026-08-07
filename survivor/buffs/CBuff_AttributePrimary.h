//
// Created by admin on 2026/8/7.
//

#pragma once
#include <string>
#include <vector>
#include "../survivor/buffs/CBuff.h"
#include "../unit/CUnit.h"

class CBuff_AttributePrimary : public CBuff
{
public:
    std::vector<std::string> AffectingAttributes() override {
        return std::vector<std::string>{
            "AttackDamage",
            "Armor",
            "Health"
        };
    };
    float GetAttribute_AttackDamage() override {return mCaster.lock()->GetStrength();};
    float GetAttribute_Armor() override {return mCaster.lock()->GetAgility()/7;};
    float GetAttribute_Health() override {return mCaster.lock()->GetStrength()*20;};
};

