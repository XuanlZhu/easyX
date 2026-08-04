//
// Created by admin on 2026/7/27.
//

#pragma once
#include <nlohmann/json.hpp>

#include "Core/CVector2.h"


class CUnit;

class CAbility {
public:
    virtual void OnSpellStart();//当施法开始
    bool IsCooldownReady();//是否冷却完成
    virtual bool OnProjectileHit(CUnit* _unit,CVector2 _pos, nlohmann::json _data){return false;};

    CUnit* mCastTarget = nullptr;
    float mCoolDown = 3;//冷却
    float mLastCastTime = -1000;//上次施法时间
    CUnit* mCaster = nullptr;
};
