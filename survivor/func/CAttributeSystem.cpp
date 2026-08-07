//
// Created by admin on 2026/7/31.
//

#include "CAttributeSystem.h"
#include <algorithm>
#include "../unit/CUnit.h"

CAttributeSystem::CAttributeSystem(CUnit *_unit) {
    mOwner = _unit;
    //初始化
    for (auto& [k,v] : base) {
        RecalculateKey(k);
    }
}

float CAttributeSystem::GetAttribute(std::string _key) {
    if (dirty[_key]) {//如果脏数据
        RecalculateKey(_key);//重算
    }
    return cache[_key].final;
}

void CAttributeSystem::SetAttributeBase(std::string key) {
    base[key] = mOwner->jsonKV["Attribute"][key];
    MarkDirty(key);
}

//重算某个值
float CAttributeSystem::RecalculateKey(std::string _key) {
    auto& value = cache[_key];
    //重新计算
    value.flat = 0;value.pct = 0;value.base = base[_key];

    for (auto buff : mAffectedBuffs[_key])
    {
        value.flat += buff->GetAttributeFunc(_key);
        value.pct += buff->GetAttributePercentFunc(_key);
        // std::cout << "flat"<< value.flat << std::endl;
    }
    //最终公式
    value.final = value.base * (1 + value.pct*0.01)+ value.flat;
    //清除脏标记
    dirty[_key] = false;

    return value.final;
}
//注册buff
void CAttributeSystem::RegisterModifier(CBuff* _buff) {
    if (_buff == nullptr)return;
    //标记该buff影响的属性
    for (auto& x : _buff->AffectingAttributes())
    {
        mAffectedBuffs[x].push_back(_buff);
        MarkDirty(x);
    }

}
//注销buff
void CAttributeSystem::UnregisterModifier(CBuff *_buff) {
    if (_buff == nullptr)return;

    //标记该buff影响的属性
    for (auto& x : _buff->AffectingAttributes())
    {
        auto it = std::find(mAffectedBuffs[x].begin(), mAffectedBuffs[x].end(), _buff);
        mAffectedBuffs[x].erase(it);//移除指针
        MarkDirty(x);
    }
}

void CAttributeSystem::MarkDirty(std::string _attribute) {
    if (dirty[_attribute])return;// 已经标记过，说明已经传播过
    dirty[_attribute] = true;// 当前属性标记脏
    // 查找依赖属性
    auto it = mDependency.find(_attribute);

    if (it == mDependency.end())return;
    // 递归传播
    for (auto& child : it->second)
    {
        MarkDirty(child);
    }
}

void CAttributeSystem::ModifyBase(std::string _key, float _value) {
    base[_key] += _value;MarkDirty(_key);
}

