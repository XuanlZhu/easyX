//
// Created by admin on 2026/7/20.
//

#pragma once
#include "Graphics/CSprite.h"
#include <string>
#include <memory>
#include <nlohmann/json.hpp>

#include "../func/CBuffSystem.h"
#include "../func/ConstantTable.h"
#include "../func/CAttributeSystem.h"
#include "../func/Global.h"

class CAbility;

class CUnit : public CSprite
{
public:
    CUnit(std::string _name);
    void SetAttackTarget(std::weak_ptr<CUnit> _unit);//设置攻击对象
    void Update(float _deltaTime) override;
    bool IsDeath();
    void CastAbilityOnTarget(CUnit* _target,CAbility* _ability);
    CAbility* AddAbility(std::string _name);
    int GetTeam(){return mTeam;};
    void OnDeath();//当死亡
    void OnDestroy();//当销毁
    virtual void OnCreate();//当创建
    float GetAttribute(std::string key){ return mAttributeSystem.GetAttribute(key);};
    float GetCacheAttribute(std::string key){ return mAttributeSystem.GetCacheAttribute(key);};
    void SetAttributeBase(std::string key) {mAttributeSystem.SetAttributeBase(key);};
    float GetMoveSpeed(){return GetAttribute("MovementSpeed");};//获取移速
    float GetAttackDamage(){return GetAttribute("AttackDamage");};//获取攻击力
    float GetAttackSpeed(){return GetAttribute("AttackSpeed");};//获取攻击速度
    float GetAttackRange(){return GetAttribute("AttackRange");};//获取攻击距离
    float GetProjectileSpeed(){return GetAttribute("ProjectileSpeed");};//获取弹道速度
    float GetStrength(){return GetAttribute("Strength");};//获取力量
    float GetAgility(){return GetAttribute("Agility");};//获取敏捷
    float GetIntellect(){return GetAttribute("Intellect");};//获取智力
    float GetMaxHealth(){return GetAttribute("Health");};//获取最大生命值
    float GetArmor(){return GetAttribute("Armor");};//获取护甲
    float GetArmorMagic(){return GetAttribute("ArmorMagic");};//获取魔抗

    float GetAttackInterval() {return GetAttribute("AttackRate")/(1+(GetAttackSpeed()-100)/100);};//获取攻击间隔

    std::weak_ptr<CBuff> AddNewModifier(CUnit* _caster,CAbility* _ability,std::string _name, nlohmann::json _tab);
    std::shared_ptr<CAbility> GetSharedPtrAbility(CAbility* _ability);
    bool IsStunned() {
        return mBuffSystem.mStateTable[MODIFIER_STATE_STUNNED];
    };

    json jsonKV={};
    float mHp = 100;//生命值
    float attack_cd=0;

    float mAttackDamage=4;//攻击力
    int mAttackType=1;//0无攻击，1近战，2远程
    int mTeam=3;//队伍
    bool mIsDeath = false;//是否死亡
    bool mCanRespawn = false;//无法重生，死亡后移除
    bool mInvincible = false;//无敌

    CBuffSystem mBuffSystem = CBuffSystem(this);//buff系统
    CAttributeSystem mAttributeSystem = CAttributeSystem(this);//属性系统
    std::vector<std::shared_ptr<CAbility>> mAbilitys;//技能表
    std::weak_ptr<CUnit> mAttackTarget;//攻击对象
};
