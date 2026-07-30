//
// Created by admin on 2026/7/29.
//

#pragma once
#include <memory>
#include <vector>
class CUnit;

class CUnitManager {
public:
    void Update(float _deltaTime);
    void ClearList();//清理表
    void Append(std::shared_ptr<CUnit> _unit);//添加单位
    std::shared_ptr<CUnit> GetSharedPtr(CUnit* _unit);
    std::vector<std::shared_ptr<CUnit>> mUnits;

    float mTime=0;
};
