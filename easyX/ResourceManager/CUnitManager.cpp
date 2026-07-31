//
// Created by admin on 2026/7/29.
//

#include "CUnitManager.h"

#include <iostream>

#include "../../survivor/unit/CUnit.h"

void CUnitManager::Update(float _deltaTime) {
    mTime += _deltaTime;
    // std::cout << "单位数"<<mUnits.size() << std::endl;
    ClearList();//清理表
    // if (mTime>=1) {//清理周期1秒
    //     mTime=0;
    //     ClearList();//清理表
    // }
}
void CUnitManager::ClearList()
{
    mUnits.erase(
        std::remove_if(mUnits.begin(),mUnits.end(),
            [](std::shared_ptr<CUnit>& _unit)
            {
                if (_unit->IsDeath() && !_unit->mCanRespawn) {
                    _unit->OnDestroy();
                    return true;
                }
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
