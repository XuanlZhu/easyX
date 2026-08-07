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
        };
    };
    float GetAttribute_AttackDamage() override {
        return mCaster.lock()->GetStrength();
    };
};

