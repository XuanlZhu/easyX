//
// Created by admin on 2026/7/29.
//

#pragma once
#include <string>
#include <unordered_map>
class CBuff;

class CUnit;

class CBuffSystem {
public:
    CBuffSystem(CUnit* _unit);
    void AddBuff(CBuff* _buff);//添加buff
    void DestroyBuff(CBuff* _buff);//销毁buff
    void HasState();//获取状态
    void RemoveBuff();//移除buff
    void GetBuffByName(std::string _name);//获取某个名字的buff
    void OnDestroy();
    bool HasState(int _state);//检查是否有某个状态
    //驱散buff


    CUnit* mOwner;
    std::unordered_map<int,int> mStateTable;//状态表
    std::vector<CBuff*> mBuffTbale;//记录所有buff
};
