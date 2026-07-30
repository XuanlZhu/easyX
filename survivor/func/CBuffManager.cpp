//
// Created by admin on 2026/7/29.
//

#include "CBuffManager.h"
#include "CBuff.h"
#include "../unit/CUnit.h"
#include <memory>

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

    buff->mOwner = std::shared_ptr<CUnit>(_target);
    buff->mCaster = std::shared_ptr<CUnit>(_caster);
    buff->mAbility = std::shared_ptr<CAbility>(_ability);

    if(_tab.contains("duration"))
    {
        buff->mDuration = _tab["duration"];//设置duration
    }
    _target->mBuffSystem.AddBuff(buff.get());//添加buff到单位

    return buff;
}

