//
// Created by admin on 2026/7/29.
//

#pragma once
#include <memory>
#include <unordered_map>

#include "../func/CBuffSystem.h"

class CAttributeSystem;
class CEffect;
class CAbility;
class CUnit;
#include "../func/ConstantTable.h"

// #define DECLARE_ATTRIBUTE(name) \
// virtual float GetAttribute_##name() { return 0; } \
// virtual float GetAttributePercent_##name() { return 0; }

#define ATTRIBUTE_LIST \
X(AttackDamage) \

#define X(name) \
virtual float GetAttribute_##name() { return 0; } \
virtual float GetAttributePercent_##name() { return 0; }

class CBuff {
public:
    ~CBuff();
    virtual void Update(float _deltaTime);//更新
    bool IsDestroy(){return mDestroying;};
    void Destroy();//销毁
    virtual void OnCreated();//当创建
    virtual void OnDestroy();//当销毁
    virtual void OnIntervalThink(){};//当销毁
    // virtual std::unordered_map<int,bool> CheckState() {return std::unordered_map<int, bool>{};};//状态注册
    virtual std::unordered_map<int,bool> CheckState() {
        return std::unordered_map<int, bool>{
            {MODIFIER_STATE_STUNNED, true},
        };
    };//状态注册
    virtual std::vector<std::string> AffectingAttributes() {
        return std::vector<std::string>{
            "attack_damage",
            "strength",
            "agility",
            "intellect",
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
        if(key == #name) return GetAttributePercent_##name();

        ATTRIBUTE_LIST
        #undef X
        return 0;
    }
    #undef ATTRIBUTE_LIST

    float think_time = 0;//思考时间
    float think_interval = -1;//思考间隔
    float mElapsedTime = 0;//逝去时间
    float mDuration = -1;//持续时间
    bool mDestroying = false;//销毁中
    bool isPassive = false;//被动
    // bool isDestroying = false;
    std::string effect_name = "";//特效名
    //记录
    std::weak_ptr<CUnit> mOwner;
    std::weak_ptr<CUnit> mCaster;
    std::weak_ptr<CAbility> mAbility;
    std::weak_ptr<CEffect> mEffect;
    CBuffSystem* mBuffSystem;//buff系统
    CAttributeSystem* mAttributeSystem;//属性系统



    // std::unordered_map<std::string, float(CBuff::*)()> funcsMap =
    // {
    //     {"attack_damage", &CBuff::GetAttribute_attack_damage},
    //     {"strength", &CBuff::GetAttribute_strength}
    // };

};
