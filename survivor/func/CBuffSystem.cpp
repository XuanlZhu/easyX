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
//析构,销毁所有buff
CBuffSystem::~CBuffSystem() {
    auto buffTable = mBuffTbale; //复制一份
    for (auto buff : buffTable)
    {
        buff->Destroy();
    }
}

//记录buff
void CBuffSystem::AddBuff(CBuff* _buff) {
    mBuffTbale.push_back(_buff);
    std::cout << "添加buff到单位" << std::endl;
    _buff->OnCreated();
}

void CBuffSystem::DestroyBuff(CBuff* _buff)
{
    auto it = std::find(mBuffTbale.begin(), mBuffTbale.end(), _buff);
    mBuffTbale.erase(it);//移除指针
}
