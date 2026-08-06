//
// Created by admin on 2026/8/6.
//

#pragma once
#include <nlohmann/json.hpp>

#include "CProjectile.h"
#include "../ability/CAbility.h"
#include "Core/CVector2.h"
#include "Graphics/CSprite.h"


class CEffect;

class CProjectile_Tracking:public CProjectile
{
public:
    CProjectile_Tracking();
    void Update(float _deltaTime) override;

    float iMoveSpeed=100;
    std::weak_ptr<CUnit> Target;//目标
};
