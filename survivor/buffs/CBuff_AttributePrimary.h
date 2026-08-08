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
            "Health",
            "ArmorMagic",
            "AbsoluteNoDamagePhysical"
        };
    };
    float GetAttribute_AttackDamage() override {return mCaster.lock()->GetStrength();};
    float GetAttribute_Armor() override {return mCaster.lock()->GetAgility()/7;};//7敏捷1护甲
    float GetAttribute_Health() override {return mCaster.lock()->GetStrength()*20;};
    float GetAttribute_ArmorMagic() override {return mCaster.lock()->GetIntellect()/14;};//14智力1魔抗
    int GetAttribute_AbsoluteNoDamagePhysical(ModifierAttackEvent event) override {
        if (RandomInt(1,2)==2) {
            return 1;
        }
        return 0;
    };//物理免疫
};

