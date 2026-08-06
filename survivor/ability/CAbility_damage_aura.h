//
// Created by admin on 2026/8/6.
//

#pragma once
#include "CAbility.h"


class CAbility_damage_aura :public CAbility
{
public:
    std::string GetIntrinsicModifierName() override{return"CBuff_damage_aura";};//被动buff
};

