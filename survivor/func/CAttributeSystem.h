//
// Created by admin on 2026/7/31.
//

#pragma once
#include <iostream>

#include "CBuff.h"


class CUnit;
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct AttributeStruct
{
    float base = 0;
    float flat = 0;
    float pct = 0;
    float final = 0;
};


class CAttributeSystem {
public:
    CAttributeSystem(CUnit* _unit);
    float Get(std::string _key);//获取属性
    float RecalculateKey(std::string _key);
    void RegisterModifier(CBuff* _buff);//注册buff
    void UnregisterModifier(CBuff* _buff);//注销buff
    void Print() {
        std::cout << "属性表" << std::endl;
        for (auto x : cache) {
            std::cout << x.first << " : " << x.second.final << std::endl;
        }
    };

    CUnit* mOwner;
    std::unordered_map<std::string, std::vector<CBuff*>> mAffectedBuffs;//受影响buff
    std::unordered_map<std::string,float> base{
        {"attack_damage", 56},
        {"strength", 23},
        {"agility", 17},
        {"intellect", 19},
    };//基础数值
    std::unordered_map<std::string,AttributeStruct> cache{
        // {"attack_damage", AttributeStruct()},
    };//缓存数值
    std::unordered_map<std::string,bool> dirty;//脏数据表
};
