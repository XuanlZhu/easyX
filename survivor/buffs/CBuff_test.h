//
// Created by admin on 2026/7/31.
//

#pragma once
#include <string>
#include <vector>
#include "../survivor/buffs/CBuff.h"

class CBuff_test : public CBuff
{
public:
    std::vector<std::string> AffectingAttributes() override {
        return std::vector<std::string>{
            "attack_damage",
        };
    };
    float GetAttribute_attack_damage() override{ return 10; };
    float GetAttributePercent_attack_damage() override{ return 100; };
};
