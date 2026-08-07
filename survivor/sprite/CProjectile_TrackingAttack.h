//
// Created by admin on 2026/8/7.
//

#pragma once
#include <nlohmann/json.hpp>

#include "CProjectile.h"
#include "CProjectile_Tracking.h"
#include "../ability/CAbility.h"
#include "Core/CVector2.h"
#include "Graphics/CSprite.h"


class CEffect;

class CProjectile_TrackingAttack:public CProjectile_Tracking
{
public:
    CProjectile_TrackingAttack();
    void Update(float _deltaTime) override;

    float iMoveSpeed=100;
    std::weak_ptr<CUnit> Target;//目标
};
