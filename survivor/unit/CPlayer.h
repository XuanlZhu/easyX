//
// Created by admin on 2026/7/17.
//

#pragma once
#include "CUnit.h"
#include "Scene/CScene.h"


class CPlayer : public CUnit
{
public:
    // using CUnit::CUnit;
    CPlayer(std::string _name);
    void OnCreate() override;
    void Update(float _deltaTime) override;
    void AddExperience(int _v);
    void OnLevelUp();
    void DoAttack(CUnit* target);
    void ProcessAttack(CUnit* target);

    int mXP=0;
    int mLevel=1;
};
