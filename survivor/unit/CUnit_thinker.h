//
// Created by admin on 2026/8/5.
//

#pragma once
#include "CUnit.h"


class CUnit_thinker:public CUnit
{
public:
    using CUnit::CUnit;
    void Update(float _deltaTime) override;
    std::weak_ptr<CBuff> thinker_buff;
};
