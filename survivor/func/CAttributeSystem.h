//
// Created by admin on 2026/7/31.
//

#pragma once
#include <iostream>

#include "../buffs/CBuff.h"


class CUnit;
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct AttributeStruct{float base = 0;float flat = 0;float pct = 0;float final = 0;};

class CAttributeSystem {
public:
    CAttributeSystem(CUnit* _unit);
    float GetAttribute(std::string _key);//获取属性
    float GetCacheAttribute(std::string _key){return cache[_key].final;};//获取缓存属性
    void SetAttributeBase(std::string key);//设置基础属性
    float RecalculateKey(std::string _key);
    void RegisterModifier(CBuff* _buff);//注册buff
    void UnregisterModifier(CBuff* _buff);//注销buff
    void MarkDirty(std::string _key);//标记脏
    void ModifyBase(std::string _key,float _value);//修改基础值
    float GetBase(std::string _key){return base[_key];};//获取基础值
    void Print() {
        std::cout << "属性表" << std::endl;
        for (auto x : cache) {
            std::cout << x.first << " : " << GetAttribute(x.first) << std::endl;
        }
    };
    //注册属性依赖
    void AddDependency(std::string _source,std::string _target)
    {
        mDependency[_source].push_back(_target);
    }

    CUnit* mOwner;
    std::unordered_map<std::string, std::vector<CBuff*>> mAffectedBuffs;//受影响buff
    std::unordered_map<std::string,float> base{
        // {"AttackDamage", 56},
        // {"Strength", 23},
        // {"Agility", 17},
        // {"Intellect", 19},
    };//基础数值
    std::unordered_map<std::string,AttributeStruct> cache{
        // {"attack_damage", AttributeStruct()},
    };//缓存数值
    std::unordered_map<std::string,bool> dirty;//脏数据表
    std::unordered_map<std::string,std::vector<std::string>> mDependency={
        {"Strength", {"AttackDamage"}},
        // {"Agility", {"AttackDamage"}},
        // {"Intellect", {"AttackDamage"}},
    };//属性依赖表
};
