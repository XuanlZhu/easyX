//
// Created by admin on 2026/7/29.
//

#include "CBuffSystem.h"

#include <iostream>

#include "CBuffManager.h"
#include "Global.h"
#include "../func/CBuff.h"

CBuffSystem::CBuffSystem(CUnit* _unit) {
    mOwner = _unit;
}
//销毁所有buff
void CBuffSystem::OnDestroy() {
    auto buffTable = mBuffTbale; //复制一份
    for (auto buff : buffTable)
    {
        buff->Destroy();
    }
}

bool CBuffSystem::HasState(int _state) {
    return mStateTable[_state];
}

//记录buff
void CBuffSystem::AddBuff(CBuff* _buff) {
    _buff->mBuffSystem = this;
    //状态计数
    auto states = _buff->CheckState();
    for(auto& [state, enable] : states)
    {
        if(enable)
        {
            mStateTable[state]++;
        }
    }

    mBuffTbale.push_back(_buff);
    // std::cout << "添加buff到单位" << std::endl;
    _buff->OnCreated();
}

void CBuffSystem::DestroyBuff(CBuff* _buff)
{
    //状态计数
    auto states = _buff->CheckState();
    for(auto& [state, enable] : states)
    {
        if(enable)
        {
            mStateTable[state]--;
        }
    }
    auto it = std::find(mBuffTbale.begin(), mBuffTbale.end(), _buff);
    mBuffTbale.erase(it);//移除指针
}

