//
// Created by admin on 2026/7/29.
//

#include "CUnitManager.h"

#include <iostream>

#include "../../survivor/unit/CUnit.h"

void CUnitManager::Update(float _deltaTime) {
    mTime += _deltaTime;
    if (mTime>=1) {//清理周期1秒
        mTime=0;
        ClearList();//清理表
    }
}
void CUnitManager::ClearList()
{
    std::cout << "清理单位表" << std::endl;
    mUnits.erase(
        std::remove_if(mUnits.begin(),mUnits.end(),
            [](std::shared_ptr<CUnit>& _unit)
            {
                return _unit->IsDeath() && !_unit->mCanRespawn;
            }
        ),
        mUnits.end()
    );
}

void CUnitManager::Append(std::shared_ptr<CUnit> _unit) {
    mUnits.push_back(_unit);
}

std::shared_ptr<CUnit> CUnitManager::GetSharedPtr(CUnit* _unit)
{
    for (auto& unit : mUnits)
    {
        if (unit.get() == _unit)
        {
            return unit;
        }
    }
    return nullptr;
}
