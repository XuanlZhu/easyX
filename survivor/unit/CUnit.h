//
// Created by admin on 2026/7/20.
//

#pragma once
#include "Graphics/CSprite.h"
#include <string>
#include <memory>


class CAbility;

class CUnit : public CSprite
{
public:
    CUnit(std::string _name);
    std::weak_ptr<CUnit> mAttackTarget;//攻击对象
    void SetAttackTarget(std::weak_ptr<CUnit> _unit);//设置攻击对象
    void Update(float _deltaTime) override;
    bool IsDeath();
    void CastAbilityOnTarget(CUnit* _target,CAbility* _ability);
    CAbility* AddAbility(std::string _name);
    int GetTeam(){return mTeam;};
    void OnDeath();//销毁

    float mHp = 100;//生命值
    float mAttackRange=35;//攻击距离
    float mAttackInterval = 1;//攻击间隔
    float mAttackDamage=4;//攻击力
    int mAttackType=1;//0无攻击，1近战，2远程
    int mTeam=3;//队伍

    std::vector<std::shared_ptr<CAbility>> mAbilitys;//技能表
    bool mIsDeath = false;//是否死亡
    float mLastAttackTime = 0;//上次攻击时间
    bool mCanRespawn = false;//无法重生，死亡后移除
};
