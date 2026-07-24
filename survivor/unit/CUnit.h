//
// Created by admin on 2026/7/20.
//

#pragma once
#include "Graphics/CSprite.h"
#include <string>
#include <memory>



class CUnit : public CSprite
{
public:
    CUnit(std::string _name);
    std::weak_ptr<CUnit> mAttackTarget;//攻击对象
    void SetAttackTarget(std::weak_ptr<CUnit> _unit);//设置攻击对象
    void Update(float _deltaTime) override;
};
