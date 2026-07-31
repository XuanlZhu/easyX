//
// Created by admin on 2026/7/29.
//

#include "CBuffManager.h"

#include <iostream>

#include "CBuff.h"
#include "../unit/CUnit.h"
#include <memory>

#include "Global.h"
#include "ResourceManager/CUnitManager.h"

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
                return _buff->IsDead();
            }
        ),
        mBuffTable.end()
    );
}
//创建，分配
std::weak_ptr<CBuff> CBuffManager::AddNewModifier(CUnit* _target, CUnit* _caster, CAbility* _ability, std::string _name, json _tab) {
    std::shared_ptr<CBuff> buff = std::make_shared<CBuff>();
    // std::cout << "进入AddNewModifier" << std::endl;
    buff->mOwner = Global::unitManager->GetSharedPtr(_target);
    buff->mCaster = Global::unitManager->GetSharedPtr(_caster);
    buff->mAbility = _caster->GetSharedPtrAbility(_ability);
    // std::cout << "完成buff成员赋值" << std::endl;
    if(_tab.contains("duration"))
    {
        buff->mDuration = _tab["duration"];//设置duration
    }
    mBuffTable.push_back(buff);
    _target->mBuffSystem.AddBuff(buff.get());//添加buff到单位
    buff->OnCreated();//触发OnCreated
    // std::cout << "添加buff到单位" << std::endl;
    return buff;
}

