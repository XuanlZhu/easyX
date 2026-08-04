//
// Created by admin on 2026/8/3.
//

#pragma once
#include "CAbility.h"


class CAbility_flyingKnife :public CAbility
{
public:
    void OnSpellStart() override;//当施法开始
    bool OnProjectileHit(CUnit *_unit, CVector2 _pos, nlohmann::json _data) override;
};
