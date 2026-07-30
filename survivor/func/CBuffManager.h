//
// Created by admin on 2026/7/29.
//

#pragma once
#include <string>
#include <memory>
#include <nlohmann/json.hpp>

class CBuff;
class CAbility;
class CUnit;
using json = nlohmann::json;

class CBuffManager {
public:
    void Update(float _deltaTime);//更新
    std::weak_ptr<CBuff> AddNewModifier(CUnit* _target,CUnit* _caster,CAbility* _ability,std::string _name,json _tab);//添加buff
    void ClearList();//清理表
    // void RemoveBuff(_buff);

    std::vector<std::shared_ptr<CBuff>> mBuffTable;
};
