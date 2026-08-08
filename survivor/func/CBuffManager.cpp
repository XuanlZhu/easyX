//
// Created by admin on 2026/7/29.
//

#include "CBuffManager.h"

#include <iostream>

#include "../buffs/CBuff.h"
#include "../buffs/CBuff_test.h"
#include "../unit/CUnit.h"

#include <memory>

#include "Global.h"
#include "ResourceManager/CUnitManager.h"
#include "../func/CAttributeSystem.h"
#include "../buffs/CBuff_axe_thinker.h"
#include "../buffs/CBuff_cross_thinker.h"
#include "../buffs/CBuff_KingBook.h"
#include "../buffs/CBuff_damage_aura.h"
#include "../buffs/CBuff_AttributePrimary.h"



void CBuffManager::Update(float _deltaTime) {
    for(auto& buff : mBuffTable)
    {
        buff->Update(_deltaTime);
    }
    ClearList();//清理
}
void CBuffManager::ClearList() {
    mBuffTable.erase(
        std::remove_if(mBuffTable.begin(),mBuffTable.end(),
            [](std::shared_ptr<CBuff>& _buff)
            {
                return _buff->IsDestroy();
            }
        ),
        mBuffTable.end()
    );
}
//创建，分配
std::weak_ptr<CBuff> CBuffManager::AddNewModifier(CUnit* _target, CUnit* _caster, CAbility* _ability, std::string _name, json _tab) {
    // std::cout << "添加buff开始" << std::endl;
    if (_name==""){return {};}//buff为空
    std::shared_ptr<CBuff> buff;
    if (_name=="CBuff_test") {
        buff = std::make_shared<CBuff_test>();
    }else if (_name=="CBuff_axe_thinker") {
        buff = std::make_shared<CBuff_axe_thinker>();
    }else if (_name=="CBuff_cross_thinker") {
        buff = std::make_shared<CBuff_cross_thinker>();
    }else if (_name=="CBuff_KingBook") {
        buff = std::make_shared<CBuff_KingBook>();
    }else if (_name=="CBuff_damage_aura") {
        buff = std::make_shared<CBuff_damage_aura>();
    }else if (_name=="CBuff_AttributePrimary") {
        buff = std::make_shared<CBuff_AttributePrimary>();




    }else {
        buff = std::make_shared<CBuff>();
    }
    // std::cout << "进入AddNewModifier" << std::endl;
    buff->mOwner = Global::unitManager->GetSharedPtr(_target);
    buff->mCaster = Global::unitManager->GetSharedPtr(_caster);
    buff->mAbility = _caster->GetSharedPtrAbility(_ability);

    buff->mBuffSystem = &_target->mBuffSystem;
    buff->mAttributeSystem = &_target->mAttributeSystem;
    // std::cout << "完成buff成员赋值" << std::endl;
    if(_tab.contains("duration"))
    {
        buff->mDuration = _tab["duration"];//设置duration
    }
    mBuffTable.push_back(buff);
    _target->mBuffSystem.AddBuff(buff.get());//添加buff到单位
    _target->mAttributeSystem.RegisterModifier(buff.get());//添加到属性系统
    RegisterModifier(buff.get());//自己注册

    buff->OnCreated();//触发OnCreated
    // std::cout << "添加buff到单位" << std::endl;
    return buff;
}

//注册buff
void CBuffManager::RegisterModifier(CBuff* _buff) {
    if (_buff == nullptr)return;
    //标记该buff影响的属性
    for (auto& x : _buff->AffectingAttributes())
    {
        mAffectedBuffs[x].push_back(_buff);
    }

}
//注销buff
void CBuffManager::UnregisterModifier(CBuff *_buff) {
    if (_buff == nullptr)return;
    //移除该buff影响的属性
    for (auto& x : _buff->AffectingAttributes())
    {
        auto it = std::find(mAffectedBuffs[x].begin(), mAffectedBuffs[x].end(), _buff);
        mAffectedBuffs[x].erase(it);//移除指针
    }
}

