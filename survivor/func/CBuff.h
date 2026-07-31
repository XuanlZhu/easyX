//
// Created by admin on 2026/7/29.
//

#pragma once
#include <memory>
#include <unordered_map>

#include "CBuffSystem.h"

class CEffect;
class CAbility;
class CUnit;
#include "../func/GameDefine.h"

// #define DECLARE_ATTRIBUTE(name) \
// virtual float GetAttribute_##name() { return 0; } \
// virtual float GetAttributePercent_##name() { return 0; }

#define ATTRIBUTE_LIST \
X(attack_damage) \
X(strength) \
X(agility) \
X(intellect)

#define X(name) \
virtual float GetAttribute_##name() { return 0; } \
virtual float GetAttributePercent_##name() { return 0; }

class CBuff {
public:
    ~CBuff();
    void Update(float _deltaTime);//更新
    bool IsDead(){return mDeath;};
    void Destroy();//销毁
    void OnCreated();//当创建
    void OnDestroy();//当销毁
    // virtual std::unordered_map<int,bool> CheckState() {return std::unordered_map<int, bool>{};};//状态注册
    virtual std::unordered_map<int,bool> CheckState() {
        return std::unordered_map<int, bool>{
            {MODIFIER_STATE_STUNNED, true},
        };
    };//状态注册
    virtual std::vector<std::string> AffectingAttributes() {
        return std::vector<std::string>{

        };
    };//声明
    ATTRIBUTE_LIST//创建getter
    #undef X
    float GetAttributeFunc(std::string key)
    {
        #define X(name) \
        if(key == #name) return GetAttribute_##name();

        ATTRIBUTE_LIST
        #undef X
        return 0;
    }
    float GetAttributePercentFunc(std::string key)
    {
        #define X(name) \
        if(key == #name) return GetAttribute_##name();

        ATTRIBUTE_LIST
        #undef X
        return 0;
    }
    #undef ATTRIBUTE_LIST

    float mElapsedTime = 0;//逝去时间
    float mDuration = -1;//持续时间
    bool mDeath = false;
    // bool isDestroying = false;
    std::weak_ptr<CUnit> mOwner;
    std::weak_ptr<CUnit> mCaster;
    std::weak_ptr<CAbility> mAbility;
    std::weak_ptr<CEffect> mEffect;
    CBuffSystem* mBuffSystem;//buff系统




    // std::unordered_map<std::string, float(CBuff::*)()> funcsMap =
    // {
    //     {"attack_damage", &CBuff::GetAttribute_attack_damage},
    //     {"strength", &CBuff::GetAttribute_strength}
    // };

};
