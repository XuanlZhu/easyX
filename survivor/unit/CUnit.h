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
    bool IsDeath();

    float mHp = 100;//生命值
    float mAttackRange=50;//攻击距离
    float mAttackInterval = 1;//攻击间隔
    float mAttackDamage=13;//攻击力
    int mAttackType=1;//0无攻击，1近战，2远程

    bool mIsDeath = false;//是否死亡
    float mLastAttackTime = 0;//上次攻击时间

};
