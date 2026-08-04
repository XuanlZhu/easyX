//
// Created by admin on 2026/8/3.
//

#pragma once
#include <nlohmann/json.hpp>

#include "../ability/CAbility.h"
#include "Core/CVector2.h"
#include "Graphics/CSprite.h"


class CEffect;

class CProjectile:public CSprite
{
public:
    CProjectile();
    void Update(float _deltaTime) override;

    std::weak_ptr<CEffect> mEffect;
    CVector2 vSpawnOrigin;//刷新位置
    float fStartRadius=12.5;//开始大小
    float fEndRadius=100;//结束大小
    float fDistance=100;//距离
    float fExpireTime = 1;//时间
    float fAge=0;
    CVector2 vVelocity = CVector2(10,0);//速度
    int iUnitTargetTeam=3;//目标类型
    std::string EffectName="CEffect_stunned";//特效名
    nlohmann::json ExtraData={};//额外
    bool isInit = false;

    std::weak_ptr<CUnit> Source;//释放者
    std::weak_ptr<CAbility> Ability;//技能
};
