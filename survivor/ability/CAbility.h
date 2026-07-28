//
// Created by admin on 2026/7/27.
//

#pragma once


class CUnit;

class CAbility {
public:
    void OnSpellStart();//当施法开始
    bool IsCooldownReady();//是否冷却完成

    CUnit* mCastTarget = nullptr;
    float mCoolDown = 3;//冷却
    float mLastCastTime = -1000;//上次施法时间
    CUnit* mCaster = nullptr;
};
