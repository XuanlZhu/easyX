//
// Created by admin on 2026/7/20.
//
#include "Global.h"
#include "../CMyGame.h"
#include "../unit/CPlayer.h"
#include <fstream>
#include <iostream>
#include <random>
#include <cmath>
#include <filesystem>
// #include "./Graphics/CSprite.h"


#include "Core/CVector2.h"
#include "ResourceManager/CEffectManager.h"
#include "../survivor/effects/CEffectNumber.h"
#include "ResourceManager/CSoundManager.h"
#include "ResourceManager/CUnitManager.h"
#include "../sprite/CXpGem.h"

namespace fs = std::filesystem;

json LoadJson(std::string _path)
{
    json data;
    try {
        fs::path path = fs::current_path();
        // std::cout << path << std::endl;
        std::ifstream file(path/_path);
        if (!file.is_open())
        {
            std::cout << "无法打开文件: " << _path << std::endl;
            return {};
        }
        file >> data;
    }catch(const std::exception& e)
    {
        std::cout << "json文件错误" << std::endl;
    }
    return data;
}

//创建单位
std::weak_ptr<CUnit> CreateUnitByName(std::string _unitName, CVector2 _location, CUnit* _owner, int _team) {
    // json data= Global::unitJson[_unitName];
    auto& table= Global::unitJson;
    // std::cout<<table<<std::endl;
    std::shared_ptr<CUnit> unit;
    if(table[_unitName].contains("class"))//如果指定类
    {
        unit = std::make_shared<CPlayer>(_unitName);
    }else {
        unit = std::make_shared<CUnit>(_unitName);
    }
    unit->jsonKV= table[_unitName];//设置json信息

    unit->mTeam = _team;//队伍1：好人，队伍2：敌对，队伍3：中立
    unit->SetPosition(_location);//设置位置
    //要用单位管理器管理unit
    Global::spriteList->Append(unit);//添加精灵表
    Global::unitManager->Append(unit);//添加到单位管理器

    return unit;
}
//获取当前时间 单位秒
float GetNowTime() {
    auto ts = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<float>(ts-Global::game->mStartTime).count();
}

int RandomInt(int _min, int _max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(_min,_max);
    return dis(gen);
}

float RandomFloat(float _min, float _max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(_min,_max);
    return dis(gen);
}

CVector2 RandomVector(int _length)
{
    float angle = RandomFloat(0.0f, 360.0f);
    float rad = angle * 3.1415926f / 180.0f;
    CVector2 vector2;
    vector2.x = cos(rad) * _length;
    vector2.y = sin(rad) * _length;

    return vector2;
}

std::weak_ptr<CEffect> CreateEffect(std::string _className, CVector2 _pos,CSprite* _attacher) {
    // std::cout << "创建特效" << std::endl;
    return Global::effectManager->CreateEffect(_className,_pos,_attacher);
}

void SendOverheadEventMessage(CSprite* _owner, std::string _value) {
    std::shared_ptr<CEffect> effect = std::make_shared<CEffectNumber>(_value);
    effect->mPos = _owner->GetPos()+RandomVector(10);
    Global::effectManager->mEffects.push_back(effect);
}

float CalcDistanceBetweenEntityOBB(CSprite* _s1, CSprite* _s2) {
    return (_s1->GetPos() - _s2->GetPos()).Length();
}

void ApplyDamage(DamageContext _context) {
    //攻击力需大于0，被攻击者需要活着
    if(_context._damage>0 && !_context._victim->IsDeath()) {
        _context._victim->mHp -= _context._damage;
        SendOverheadEventMessage(_context._victim,std::to_string((int)_context._damage));
    }
}

void EmitSoundOn(std::string _name) {
    Global::soundManager->Play(_name);
}

std::vector<std::weak_ptr<CUnit>> FindUnitsInRadius(int _team, CVector2 _pos, float _radius, int _order) {
    std::vector<std::weak_ptr<CUnit>> result;

    for(auto& unit : Global::unitManager->mUnits)
    {
        // 阵营过滤
        if(unit->GetTeam() != _team)continue;
        // 距离判断
        float distance = (unit->GetPos() - _pos).Length();

        if(distance <= _radius)
        {
            result.push_back(unit);
        }
    }
    //排序还没实现
    return result;
}
//创建精灵
std::weak_ptr<CSprite> CreateCSprite(std::string _sprite,CVector2 _pos) {
    std::shared_ptr<CSprite> sprite;//创建精灵类，下发到当前精灵表
    if (true) {
        sprite = std::make_shared<CXpGem>();
    }
    sprite->SetPosition(_pos);
    Global::spriteList->Append(sprite);
    return sprite;
}

