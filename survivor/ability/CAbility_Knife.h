//
// Created by admin on 2026/8/5.
//

#pragma once

#include "CAbility.h"


class CAbility_Knife :public CAbility
{
public:
    CAbility_Knife();
    void OnSpellStart() override;//当施法开始
    bool OnProjectileHit(CUnit *_unit, CVector2 _pos, nlohmann::json _data) override;
};

