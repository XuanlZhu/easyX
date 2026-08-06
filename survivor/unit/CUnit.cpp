//
// Created by admin on 2026/7/20.
//

#include "CUnit.h"
#include "../func/Global.h"
#include <iostream>
#include <memory>
#include <nlohmann/json_fwd.hpp>

#include "../ability/CAbility.h"
#include "../func/CBuffManager.h"
#include "ResourceManager/CImageManager.h"
#include "ResourceManager/CSoundManager.h"
#include "../sprite/CXpGem.h"
#include "../ability/CAbility_stamp.h"
#include "../ability/CAbility_ice.h"
#include "../ability/CAbility_whip.h"
#include "../ability/CAbility_Knife.h"
#include "../ability/CAbility_axe.h"
#include "../ability/CAbility_cross.h"
#include "../ability/CAbility_KingBook.h"
#include "../ability/CAbility_damage_aura.h"



using json = nlohmann::json;

// CUnit::CUnit() {
// }
//
CUnit::CUnit(std::string _name) {
    auto& table= Global::unitJson;
    // std::cout<<table<<std::endl;
    if(!table.contains(_name))
    {
        std::cout<<"单位不存在:"<<_name<<std::endl;
        return;
    }
    json data = table[_name];
    // cout<<data<<endl;
    if (data.contains("img")) {
        std::string img = "PNG/" + data["img"].get<std::string>() + ".png";
        mImage = Global::imgManager->GetImage(img);
    }
    if(data.contains("mSpeed")){mSpeed = data["mSpeed"].get<float>();}
}



void CUnit::SetAttackTarget(std::weak_ptr<CUnit> _unit) {
    mAttackTarget = _unit;
}

void CUnit::Update(float _deltaTime) {
    if (IsDeath()) {OnDeath();return;};//当前帧需清除
    if (IsStunned()) {return;};

    auto target = mAttackTarget.lock();
    if(target)
    {
        if (CalcDistanceBetweenEntityOBB(this,target.get())>10) {
            mPos = mPos+(target->mPos-mPos).Normalize()*mSpeed*_deltaTime;
        }
        // std::cout << "移动" << std::endl;
        //如果在攻击范围内
        if (CalcDistanceBetweenEntityOBB(this,target.get())<=mAttackRange && (GetNowTime()-mLastAttackTime)>=mAttackInterval && !target->IsDeath()) {
            //攻击目标
            Global::soundManager->Play("injuried");
            ApplyDamage(DamageContext{this,target.get(),mAttackDamage});
            mLastAttackTime = GetNowTime();
        }
    }
}

bool CUnit::IsDeath() {
    if(mHp<=0) {
        mIsDeath = true;
    }
    return mIsDeath;
}
void CUnit::OnDeath() {//触发时机：是Update时
    if (!mCanRespawn) {//无法重生
        this->isdraw = false;//标记精灵表删除
    }
    this->mIsDeath = true;//标记死亡
    //创建宝石
    std::cout << GetName() << std::endl;
    if (GetName()!="CUnit_thinker") {
        auto it = CreateCSprite("CXpGem",mPos).lock();
        std::dynamic_pointer_cast<CXpGem>(it)->BountyXP = jsonKV.value("BountyXP", 0);//设置经验
    }
}

void CUnit::CastAbilityOnTarget(CUnit* _target, CAbility* _ability) {
    _ability->mCastTarget = _target;
    _ability->OnSpellStart();
}

CAbility* CUnit::AddAbility(std::string _name) {
    std::shared_ptr<CAbility> ability;
    if (_name=="CAbility_stamp") {
        ability = std::make_shared<CAbility_stamp>();
    }else if (_name=="CAbility_ice") {
        ability = std::make_shared<CAbility_ice>();
    }else if (_name=="CAbility_whip") {
        ability = std::make_shared<CAbility_whip>();
    }else if (_name=="CAbility_Knife") {
        ability = std::make_shared<CAbility_Knife>();
    }else if (_name=="CAbility_axe") {
        ability = std::make_shared<CAbility_axe>();
    }else if (_name=="CAbility_cross") {
        ability = std::make_shared<CAbility_cross>();
    }else if (_name=="CAbility_KingBook") {
        ability = std::make_shared<CAbility_KingBook>();
    }else if (_name=="CAbility_damage_aura") {
        ability = std::make_shared<CAbility_damage_aura>();




    }else {
        ability = std::make_shared<CAbility>();
    }

    ability->mCaster = this;
    mAbilitys.push_back(ability);//添加技能
    ability->OnCreated();
    return ability.get();
}


void CUnit::OnDestroy() {
    mBuffSystem.OnDestroy();//触发Destroy链
}

void CUnit::OnCreate() {
}

std::weak_ptr<CBuff> CUnit::AddNewModifier(CUnit* _caster, CAbility* _ability, std::string _name, nlohmann::json _tab) {
    if (_caster->IsDeath()) {return {};}
    if (_name==""){return {};}//buff为空
    return Global::buffManager->AddNewModifier(this,_caster,_ability,_name,_tab);
}

std::shared_ptr<CAbility> CUnit::GetSharedPtrAbility(CAbility *_ability) {
    for (auto& it : mAbilitys)
    {
        if (it.get() == _ability)
        {
            return it;
        }
    }
    return nullptr;
}
