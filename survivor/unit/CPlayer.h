//
// Created by admin on 2026/7/17.
//

#pragma once
#include "CUnit.h"
#include "Scene/CScene.h"


class CPlayer : public CUnit
{
public:
    using CUnit::CUnit;
    void Update(float _deltaTime) override;
};
