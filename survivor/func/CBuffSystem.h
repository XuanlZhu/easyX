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
    ~CBuffSystem();
    void AddBuff(CBuff* _buff);//添加buff
    void DestroyBuff(CBuff* _buff);//销毁buff
    void HasState();//获取状态
    void RemoveBuff();//移除buff
    void GetBuffByName(std::string _name);//获取某个名字的buff
    //驱散buff


    CUnit* mOwner;
    std::unordered_map<std::string,int> mStateTbale;//状态表
    std::vector<CBuff*> mBuffTbale;//记录所有buff
};
