//
// Created by admin on 2026/7/20.
//
#include "Global.h"
#include "../CMyGame.h"
#include <fstream>
#include <iostream>

json LoadJson(std::string _path)
{

    std::ifstream file("D:/project/easyX/survivor/"+_path);
    if (!file.is_open())
    {
        std::cout << "无法打开文件: " << _path << std::endl;
        return {};
    }
    json data;
    file >> data;
    return data;
}

//创建单位
std::weak_ptr<CUnit> CreateUnitByName(std::string _unitName, CVector2 _location, CUnit* _owner, int _team) {
    // json data= Global::unitJson[_unitName];
    auto unit = std::make_shared<CUnit>("creep");//共享指针
    unit->SetPosition(_location);//设置位置
    Global::game->SpriteListAppend(unit);//添加精灵表
    return unit;
}
//获取当前时间 单位秒
float GetNowTime() {
    auto ts = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<float>(ts-Global::game->mStartTime).count();
}

