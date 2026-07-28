//
// Created by admin on 2026/7/20.
//

#include "CUnit.h"
#include "../func/Global.h"
#include <iostream>
#include <nlohmann/json_fwd.hpp>

#include "../ability/CAbility.h"
#include "ResourceManager/CImageManager.h"
#include "ResourceManager/CSoundManager.h"
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
    if (IsDeath())return;
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

void CUnit::CastAbilityOnTarget(CUnit* _target, CAbility* _ability) {
    _ability->mCastTarget = _target;
    _ability->OnSpellStart();
}

